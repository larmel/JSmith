#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "TestCase.h"

using namespace std;

static string tmp_output_file = "test/last_run/_output";
static string tmp_input_file = "test/last_run/_generated.js";

static string plot_output_file = "test/last_run/plot.png";
static string plot_data_file = "test/last_run/plot.dat";
static string plot_script_file = "test/last_run/plot.pg";

static string running_file = "test/last_run/RUNNING";
static string success_folder = "test/last_run/successes/";
static string bugs_folder = "test/last_run/bugs/";


int main(int argc, char* argv[]) 
{
    // First argument: how many tests to run
    unsigned int tests = 0;
    if (argc > 1) {
        tests = atoi(argv[argc-1]);
    }
    bool plot = false;
    
    // Plot?
    if(argc > 1){
    	for(int i = 1; i < argc; i++){
			string s = argv[i];
			if(s == "-plot"){
				plot = true;
				break;
			}
    	}
    }

    // Test a specific file?
    string input_file = "";
    if (argc > 1) {
        for(int i = 1; i < argc-1; i++){
            string s = argv[i];
            if(s == "-file"){
                input_file = argv[i+1];
                //if (tests==0) {
                //    tests = 1;
                //}
            }
        }
    }

    if (tests==0) {
        cerr << "Usage: bin/jsmith [-file <file>] [-plot] <number of tests>" << endl;
        exit(1);
    }

    int num_errors = 0;
    int testno = 0;
    
    // Cleanup folders
    string cmd = "rm -f "+success_folder+"*";
    system(cmd.c_str());
    cmd = "rm -f "+bugs_folder+"*";
    system(cmd.c_str());

    ofstream plotfile(plot_data_file.c_str());

    if(plot){
		if(plotfile.fail()){
			cerr << "Missing file " << plot_data_file;
			exit(2);
		}
		plotfile << "#\tAvg" << "\t";
		for(int i = 0; i < TestCase::num_compilers; i++){
			plotfile << TestCase::compilers[i];
			if(i != TestCase::num_compilers - 1){
				plotfile << "\t";
			}
		}
		plotfile << endl;
    }

    cout << "Running " << tests << " tests." << endl;

    ofstream running(running_file.c_str());
    running << "RUNNING, remove file to stop.";
    running.close();

    TestCase tcase;

    while (testno++ < tests)
    {
        ifstream runningcheck;
        runningcheck.open(running_file.c_str());
        if (runningcheck.fail()) {
            cout << "Stopping." << endl;
            break;
        } else {
            runningcheck.close();
        }


        if (input_file == "") {
            tcase.generateSource();
        } else {
            tcase.setSource(input_file);
        }
        tcase.testAgainstCompilers();
        
        if (!tcase.success()) {
        	num_errors++;
            cout << "Error detected in test " << testno << ", saved as bugs/" << testno << "!" << endl;
            stringstream filename;
            filename << bugs_folder << testno << ".js";
            tcase.reportToFile(filename.str());
        }
        else
        {
        	TestCaseCompiler* fastest = tcase.getFastestCompiler();
        	TestCaseCompiler* slowest = tcase.getSlowestCompiler();

        	cout << "Ran test " << testno << " in avg " << tcase.getAvgMs() << " ms (best " <<
        			fastest->getName()<< " " << fastest->getMs() << " ms, worst " << slowest->getName() <<
        			" "<<  slowest->getMs() << " ms)." << endl;

        	stringstream filename;
			filename << success_folder << testno << ".js";
			tcase.reportToFile(filename.str());

			// Record to plot.dat
			if(plot){
				vector<TestCaseCompiler*> compilers = tcase.getCompilers();

				plotfile << testno << "\t" << tcase.getAvgMs() << "\t";

				for(int i = 0; i < compilers.size(); i++){
					plotfile << compilers.at(i)->getMs();
					if(i != compilers.size() - 1){
						plotfile << "\t";
					}
				}
				if(testno != tests)
				{
					plotfile << endl;
				}
			}
        }

	}

    plotfile.close();
    tcase.removeTempFiles();

    if(plot)
    {
        ofstream plotconfig(plot_script_file.c_str());
        plotconfig << "reset" << endl;
        plotconfig << "set terminal png size 1100,600" << endl;
        plotconfig << "set xlabel \"Test Number\"" << endl;
        plotconfig << "set ylabel \"Time (ms)\"" << endl;
        plotconfig << "set title \"Runtimes for generated JSmith tests\"" << endl;
        plotconfig << "set key reverse Left outside" << endl;
        plotconfig << "set grid" << endl;
        plotconfig << "set style data linespoints" << endl;

        plotconfig << "set logscale y" << endl;
        plotconfig << "set style line 1 lt 0 lw 2" << endl;

        plotconfig << "plot  \""<<plot_data_file<<"\" using 1:2 w l ls 1 title 'Average', \\" << endl;

        TestCase tcase;
        vector<TestCaseCompiler*> compilers = tcase.getCompilers();
        for(int i = 0; i < compilers.size(); i++){
            plotconfig << "  \"test/last_run/plot.dat\" using 1:" << i+3 << " title '"<<compilers[i]->getName()<<"'";
            if(i != compilers.size() - 1){
                plotconfig << ",\\"<<endl;
            }
        }
        plotconfig.close();

        string plotcmd = "gnuplot "+plot_script_file+" > "+plot_output_file;
        system(plotcmd.c_str());

        cout << "Run times plotted to "<< plot_output_file << endl;

    } else {
        string rmcmd = "rm -f "+plot_output_file+" "+plot_data_file;
        system(rmcmd.c_str());
    }


    cout << "Completed! " << testno-1 << " tests ran, " << num_errors << " errors." << endl;

    string rmcmd = "rm -f "+plot_script_file+" "+running_file;
    system(rmcmd.c_str());
    return 0;

}

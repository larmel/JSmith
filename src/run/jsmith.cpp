#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "TestCase.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    // First argument: how many tests to run
    unsigned int tests = 1;
    if (argc > 1) {
        tests = atoi(argv[1]);
    }
    bool plot = false;
    
    // Plot?
    if(argc > 2){
    	for(int i = 2; i < argc; i++){
			string s = argv[i];
			if(s == "-plot"){
				plot = true;
				break;
			}
    	}
    }

    // Test a specific file?
    string input_file = "";
    if (argc > 2) {
        for(int i = 2; i < argc-1; i++){
            string s = argv[i];
            if(s == "-file"){
                input_file = argv[i+1];
                break;
            }
        }
    }

    int num_errors = 0;
    int testno = 0;
    
    system("rm -f test/current_jsmith/successes/*");
    system("rm -f test/current_jsmith/bugs/*");

    ofstream plotfile("test/current_jsmith/plot.dat");

    if(plot){
		if(plotfile.fail()){
			cerr << "Missing file plot.dat";
			exit(2);
		}
		plotfile << "#Avg" << "\t";
		for(int i = 0; i < TestCase::num_compilers; i++){
			plotfile << TestCase::compilers[i];
			if(i != TestCase::num_compilers - 1){
				plotfile << "\t";
			}
		}
		plotfile << endl;
    }

    cout << "Running " << tests << " tests." << endl;

    ofstream running("test/current_jsmith/RUNNING");
    running << "RUNNING";
    running.close();

    while (testno++ < tests)
    {
        ifstream runningcheck;
        runningcheck.open("test/current_jsmith/RUNNING");
        if (runningcheck.fail()) {
            cout << "Stopping." << endl;
            break;
        } else {
            runningcheck.close();
        }


        TestCase tcase;
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
            filename << "test/current_jsmith/bugs/" << testno << ".js";
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
			filename << "test/current_jsmith/successes/" << testno << ".js";
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

    if(plot)
    {
        ofstream plotconfig("test/current_jsmith/plot.pg");
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

        plotconfig << "plot  \"test/current_jsmith/plot.dat\" using 1:2 w l ls 1 title 'Average', \\" << endl;

        TestCase tcase;
        vector<TestCaseCompiler*> compilers = tcase.getCompilers();
        for(int i = 0; i < compilers.size(); i++){
            plotconfig << "  \"test/current_jsmith/plot.dat\" using 1:" << i+2 << " title '"<<compilers[i]->getName()<<"'";
            if(i != compilers.size() - 1){
                plotconfig << ",\\"<<endl;
            }
        }
        plotconfig.close();

        system("gnuplot test/current_jsmith/plot.pg > test/current_jsmith/plot.png");

        cout << "Run times plotted to test/current_jsmith/plot.png" << endl;

    }


    cout << "Completed! " << testno-1 << " tests ran, " << num_errors << " errors." << endl;

    system("rm -f test/current_jsmith/RUNNING");
    return 0;

}

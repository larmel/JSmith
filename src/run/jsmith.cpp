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
    
    if(argc > 2){
    	for(int i = 2; i < argc; i++){
			string s = argv[i];
			if(s == "-plot"){
				plot = true;
				break;
			}
    	}
    }

    // Test a specific file
    string input_file = "";
    if (argc > 2) {
        input_file = argv[2];
    }

    int num_errors = 0;
    int testno = 0;
    
    system("rm -f test/current_jsmith/successes/*");
    system("rm -f test/current_jsmith/bugs/*");

    ofstream plotfile("test/current_jsmith/plot.dat");

    if(plot && false){
		if(plotfile.fail()){
			cerr << "Missing file plot.dat";
			exit(2);
		}
		plotfile << endl;
		for(int i = 0; i < TestCase::num_compilers; i++){
			plotfile << TestCase::compilers[i];
			if(i != TestCase::num_compilers - 1){
				plotfile << "\t";
			}
		}
		plotfile << endl;
    }

    cout << "Running " << tests << " tests." << endl;

    while (testno++ < tests)
    {
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
    	string plotpg_filename = "test/current_jsmith/plot.pg";
    	ofstream plotpg (plotpg_filename.c_str());
    	if(plotpg.fail()){
			cerr << "Missing file plot.pg.";
			exit(2);
		}
    	plotpg << string("reset\nset terminal png\nset xlabel \"time\"\nset ylabel \"total actives\"\nset title ") +
				  string("\"M7YC Performance per time\"\nset key reverse Left outside\nset grid\nset style data linespoints\nplot \"plot.dat\"");
    	plotpg.close();

    	//system(string(string("chmod +x ") + plotpg_filename).c_str());
    	//system(string(string("gnuplot ") + plotpg_filename + string(" > test/current_jsmith/graph.png")).c_str());

    }


    cout << "Completed! " << tests << " tests ran, " << num_errors << " errors." << endl;
    return 0;

}

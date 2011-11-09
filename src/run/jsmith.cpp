#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "TestCase.h"

using namespace std;

/*
 * Usage:
 * > jsmith <number> <file>
 */ 
int main(int argc, char* argv[]) 
{
    // First argument: how many tests to run
    unsigned int tests = 1;
    if (argc > 1) {
        tests = atoi(argv[1]);
    }
    
    // Test a specific file
    string input_file = "";
    if (argc > 2) {
        input_file = argv[2];
    }

    int num_errors = 0;
    int testno = 0;

    system("rm -f test/current_jsmith/bugs/*.js");

    cout << "Running " << tests << " tests." << endl;

    while (testno++ < tests)
    {
        TestCase tcase;
		tcase.generateSource();
        tcase.testAgainstCompilers();
        
        if (!tcase.success()) {
        	num_errors++;
            cout << "Error detected in test " << testno << ", saved as bugs/" << num_errors << "!" << endl;
            stringstream filename;
            filename << "test/current_jsmith/bugs/" << num_errors << ".js";
            tcase.reportToFile(filename.str());
        }
        else
        {
        	TestCaseCompiler* fastest = tcase.getFastestCompiler();
        	TestCaseCompiler* slowest = tcase.getSlowestCompiler();

        	cout << "Ran test " << testno << " in avg " << tcase.getAvgMs() << " ms (best " <<
        			fastest->getName()<< " " << fastest->getMs() << " ms, worst " << slowest->getName() <<
        			" "<<  slowest->getMs() << " ms)." << endl;
        }

        if(testno == tests)
        {
			tcase.reportToFile("test/current_jsmith/report.js");
        }
	}
    
    cout << "Completed! " << tests << " tests ran, " << num_errors << " errors." << endl;
    return 0;
}


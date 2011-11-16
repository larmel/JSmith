#include <iostream>
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
    
    // Test a specific file
    string input_file = "";
    if (argc > 2) {
        input_file = argv[2];
    }

    int num_errors = 0;
    int testno = 0;
    
    system("rm -f test/current_jsmith/successes/*");
    system("rm -f test/current_jsmith/bugs/*");
   

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
        }

	}
    
    cout << "Completed! " << tests << " tests ran, " << num_errors << " errors." << endl;
    return 0;

}

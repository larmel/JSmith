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

    cout << "This is Jsmith. Running " << tests << " tests." << endl;

    while (testno++ < tests)
    {
        cout << "Running test " << testno << " of " << tests <<  "." << endl;
        
        TestCase tcase;

        if (input_file == "") {
        	tcase.generateSource();
        } else {
        	tcase.setSource(input_file);
        }
        tcase.testAgainstCompilers();
        
        if (!tcase.success()) {
        	num_errors++;
            cout << "Error detected on test " << testno << ", saved as bug/" << num_errors << "!" << endl;
            stringstream filename;
            filename << "test/current_jsmith/bugs/" << num_errors << ".js";
            tcase.reportToFile(filename.str());
        }
    }
    
    cout << "Completed! " << tests << " tests ran, " << num_errors << " errors." << endl;
    return 0;
}


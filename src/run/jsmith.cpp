#include <iostream>
#include <string>
#include <cstdlib>

#include "TestSuite.h"

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
    
    TestSuite testSuite;
    
    while (tests--)
    {
        cout << "Remaining: " << tests + 1 << endl;
        
        if (input_file == "") {
            testSuite.generateSource();
        } else {
            testSuite.setSource(input_file);
        }
        
        if (!testSuite.runAllTests()) {
            cout << "Error detected !!!" << endl;
            return 1;
        }
    }
    
    cout << "All tests ran with no error detected" << endl;
    return 0;
}


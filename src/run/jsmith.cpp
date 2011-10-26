#include <iostream>
#include <string>
#include <cstdlib>

#include "TestSuite.h"

using std::cout;
using std::endl;

/*
 * Usage:
 * > jsmith <number>
 */ 
int main(int argc, char* argv[]) 
{
    // First argument: how many tests to run
    unsigned int tests = 1;
    if (argc > 1) {
        tests = atoi(argv[1]);
    }
    
    TestSuite testSuite;
    
    while (tests--)
    {
        cout << "Remaining: " << tests + 1 << endl;
        testSuite.generateSource();
        
        if (!testSuite.runAllTests()) {
            cout << "Error detected !!!" << endl;
            return 1;
        }
    }
    
    cout << "All tests ran with no error detected" << endl;
    return 0;
}


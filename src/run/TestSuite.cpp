#include <iostream>
#include <fstream>
#include <cstdlib>

#include "TestSuite.h"

/*
 * Invoke generate, create a new program at test/generated.js
 */
void TestSuite::generateSource() {
    system("bin/generate > test/generated.js");
}

pair<bool, string> TestSuite::invoke(string path) {
    string command = path + " " + input_file + " > " + output_file;
    cout << command << endl;
    
    int success = system(command.c_str()) == 0;
    string result = getOutput();
    
    return pair<bool, string>(success, result);
}

/*
 * Read output file generated for each test
 */
string TestSuite::getOutput() {
    ifstream file(output_file.c_str());
    
    string concatinated = "", line;
    while (getline(file, line)) {
        concatinated += line;
    }
    
    file.close();
    return concatinated;
}

/*
 * Feed generated.js to all available compilers
 */
bool TestSuite::runAllTests() 
{
    pair<bool, string> spiderMonkey = invoke( "js-compilers/SpiderMonkey/js" );
    pair<bool, string> rhino = invoke( "/usr/bin/rhino -f" );
    pair<bool, string> v8 = invoke( "js-compilers/V8/v8" );
    pair<bool, string> kjs = invoke( "/usr/bin/kjs" );
    pair<bool, string> narcissus = invoke( "js-compilers/Narcissus/njs -f" );
    
    ofstream report(report_file.c_str());
    
    report << "*** Test Summary ***" << endl;
    report << "SpiderMonkey: \t (" << spiderMonkey.first << ", " << spiderMonkey.second << ")" << endl;
    report << "Rhino: \t\t (" << rhino.first << ", " << rhino.second << ")" << endl;
    report << "V8: \t\t (" << v8.first << ", " << v8.second << ")" << endl;
    report << "KJS: \t\t (" << kjs.first << ", " << kjs.second << ")" << endl;
    report << "Narcissus: \t (" << narcissus.first << ", " << narcissus.second << ")" << endl;
    
    ifstream source(input_file.c_str());
    
    string s;
    while (getline(source, s)) {
        report << s << endl;
    }
    
    source.close();
    report.close();
    
    return spiderMonkey.second == rhino.second && rhino.second == v8.second && v8.second == kjs.second && kjs.second == narcissus.second;
}


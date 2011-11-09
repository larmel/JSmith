#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "TestCase.h"

/*
 * Invoke generate, create a new program at test/generated.js
 */
void TestCase::generateSource() {
    system("bin/generate > test/current_jsmith/_generated.js");
}

void TestCase::setSource(string file) {
    input_file = file;
}

pair<bool, string> TestCase::testCompiler(string compiler_path) {
    string command = compiler_path + " " + input_file + " > " + tmp_output_file; // " 2>&1";
    int success = system(command.c_str()) == 0;
    //string result = getOutput();

    ifstream file(tmp_output_file.c_str());
    string result = "", line;
    while (getline(file, line)) {
        result += line;
    }
    file.close();

    return pair<bool, string>(success, result);
}

/*
 * Feed generated.js to all available compilers
 */

void TestCase::testAgainstCompilers()
{
    spiderMonkey = testCompiler( "js-compilers/SpiderMonkey/js" );
    rhino = testCompiler( "/usr/bin/rhino -f" );
    v8 = testCompiler( "js-compilers/V8/v8" );
    kjs = testCompiler( "/usr/bin/kjs" );
    narcissus = testCompiler( "js-compilers/Narcissus/njs -f" );
    
}

void TestCase::reportToFile(string filename)
{
    char buf [100];
    time_t now = time (NULL);
    struct tm *t = localtime (&now);
    strftime (buf, 100, "%B %d, %Y at %T", t);

    ofstream report(filename.c_str());
    
    report << "/*" << endl;
    report << " * ### Test Summary " << buf << "" << endl;
    report << " * ### Time Taken: Todo" << endl;
    report << " *" << endl;
    report << " * SpiderMonkey: (" << spiderMonkey.first << ", " << spiderMonkey.second << ")" << endl;
    report << " * Rhino:        (" << rhino.first << ", " << rhino.second << ")" << endl;
    report << " * V8:           (" << v8.first << ", " << v8.second << ")" << endl;
    report << " * KJS:          (" << kjs.first << ", " << kjs.second << ")" << endl;
    report << " * Narcissus:    (" << narcissus.first << ", " << narcissus.second << ")" << endl;
    report << " */" << endl;
    
    ifstream source(input_file.c_str());
    
    string s;
    while (getline(source, s)) {
        report << s << endl;
    }
    
    source.close();
    report.close();
    
}

bool TestCase::success()
{
	return spiderMonkey.second == v8.second && v8.second == kjs.second && kjs.second == narcissus.second;
}


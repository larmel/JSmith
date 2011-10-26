#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const static char* input_file = "test/generated.js";
const static char* output_file = "test/output";

string getOutput() 
{
    ifstream file(output_file);
    string concatinated = "";
    string s;
    while (getline(file, s)) {
        concatinated += s;
    }
    file.close();
    return concatinated;
}

bool invokeSpiderMonkey() 
{
    string command = "js-compilers/SpiderMonkey/js " + string(input_file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeRhino() 
{
    string command = "/usr/bin/rhino -f " + string(input_file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeV8() 
{
    string command = "js-compilers/V8/v8 " + string(input_file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeKjs()
{
    string command = "/usr/bin/kjs " + string(input_file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeNarcissus()
{
    string command = "js-compilers/Narcissus/njs -f " + string(input_file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

/*
 * Invoke generate, create a new program at test/generated.js
 */
void generateSource() {
    string command = "bin/generate > test/generated.js";
    cout << command << endl;
    system(command.c_str());
}

/*
 * Feed generated.js to all available compilers
 */
bool runAllTests() {
    invokeSpiderMonkey();
    string spiderMonkey = getOutput();
    
    invokeRhino();
    string rhino = getOutput();
    
    invokeV8();
    string v8 = getOutput();
    
    invokeKjs();
    string kjs = getOutput();
    
    invokeNarcissus();
    string narcissus = getOutput();
    
    ifstream source(input_file);
    ofstream report("test/report");
    
    report << "Test Summary" << endl;
    report << "SpiderMonkey: \t" << spiderMonkey << endl;
    report << "Rhino: \t\t" << rhino << endl;
    report << "V8: \t\t" << v8 << endl;
    report << "KJS: \t\t" << kjs << endl;
    
    report << "Narcissus: \t" << narcissus << endl << endl;
    
    string s;
    while (getline(source, s))
    {
        report << s << endl;
    }
    
    report.close();
    source.close();
    
    return spiderMonkey == rhino && rhino == v8 && v8 == kjs && kjs == narcissus;
}

/*
 * To run 100 tests
 * > jsmith 100
 */ 
int main(int argc, char* argv[]) 
{
    // First argument: how many tests to run
    unsigned int tests = 1;
    if (argc > 1) {
        tests = atoi(argv[1]);
    }
    
    while (tests--)
    {
        generateSource();
        
        if (!runAllTests()) {
            std::cout << "** !!! Error detected !!! **" << std::endl;
            return 1;
        }
    }
    return 0;
}




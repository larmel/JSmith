#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const static char* output_file = "test/output";

string getOutput() 
{
    ifstream file(output_file);
    string s;
    getline(file, s);
    file.close();
    return s;
}


bool invokeSpiderMonkey(const char* file) 
{
    string command = "js-compilers/SpiderMonkey/js " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeRhino(const char* file) 
{
    string command = "/usr/bin/rhino -f " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeV8(const char* file) 
{
    string command = "js-compilers/V8/v8 " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeKjs(const char* file)
{
    string command = "/usr/bin/kjs " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeNarcissus(const char* file)
{
    string command = "js-compilers/Narcissus/njs -f " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

int main(int argc, char* argv[]) 
{
    char* filename = argv[1];
    
    invokeSpiderMonkey(filename);
    string spiderMonkey = getOutput();
    
    invokeRhino(filename);
    string rhino = getOutput();
    
    invokeV8(filename);
    string v8 = getOutput();
    
    invokeKjs(filename);
    string kjs = getOutput();
    
    invokeNarcissus(filename);
    string narcissus = getOutput();
    
    cout << "Test Summary" << endl;
    cout << "SpiderMonkey: \t" << spiderMonkey << endl;
    cout << "Rhino: \t\t" << rhino << endl;
    cout << "V8: \t\t" << v8 << endl;
    cout << "KJS: \t\t" << kjs << endl;
    cout << "Narcissus: \t" << narcissus << endl;
    
    return 0;
}




#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const static char* output_file = "test/output";

string getOutput() {
    ifstream file(output_file);
    string s;
    getline(file, s);
    file.close();
    return s;
}


bool invokeSpiderMonkey(const char* file) {
    
    string command = "js-compilers/SpiderMonkey/js " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}

bool invokeRhino(const char* file) {
    
    string command = "/usr/bin/rhino -f " + string(file) + " > test/output";
    cout << command << endl;
    
    int retcode = system(command.c_str());
    return retcode == 0;
}


int main(int argc, char* argv[]) {
    
    // Reading a single javascript program from file
    //  1) Feeding to multiple compilers
    //  2) Gathering output and comparing
    //     Report differences. Need to store intermediate results
    
    char* filename = argv[1];
    
    invokeSpiderMonkey(filename);
    string spiderMonkey = getOutput();
    
    invokeRhino(filename);
    string rhino = getOutput();
    
    cout << "Test Summary" << endl;
    cout << "SpiderMonkey: \t" << spiderMonkey << endl;
    cout << "Rhino: \t\t" << rhino << endl;
    
    return 0;
}




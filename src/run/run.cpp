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


int main(int argc, char* argv[]) {
    
    // Reading a single javascript program from file
    //  1) Feeding to multiple compilers
    //  2) Gathering output and comparing
    //     Report differences. Need to store intermediate results
    
    char* filename = argv[1];
    
    invokeSpiderMonkey(filename);
    string s = getOutput();
    
    cout << "Test Summary" << endl;
    cout << "SpiderMonkey: \t" << s << endl;
    
    return 0;
}




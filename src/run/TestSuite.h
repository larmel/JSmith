#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <string>
#include <map>

using namespace std;

class TestSuite
{
private:
    string input_file;
    string output_file;
    string report_file;
    
    pair<bool, string> invoke(std::string command);
    std::string getOutput();

public:
    TestSuite() {
        input_file = "test/generated.js";
        output_file = "test/output";
        report_file = "test/report";
    };
    
    void generateSource();
    void setSource(string file);
    bool runAllTests();
};

#endif

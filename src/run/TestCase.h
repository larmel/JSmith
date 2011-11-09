#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <string>
#include <map>

using namespace std;

class TestCase
{
private:
    string input_file;
    string tmp_output_file;
    //string report_file;
    
    pair<bool, string> spiderMonkey;
    pair<bool, string> rhino;
    pair<bool, string> v8;
    pair<bool, string> kjs;
    pair<bool, string> narcissus;

    pair<bool, string> testCompiler(std::string command);

public:
    TestCase() {
        input_file = "test/current_jsmith/_generated.js";
        tmp_output_file = "test/current_jsmith/_output";
    };
    
    void generateSource();
    void setSource(string);
    void testAgainstCompilers();
    bool success();
    void reportToFile(string);
};

#endif

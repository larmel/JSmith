#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "TestCaseCompiler.h"

using namespace std;

class TestCase
{
private:
    vector<TestCaseCompiler*> tccompilers;
public:
    TestCase();
    ~TestCase();
    void generateSource();
    void setSource(string);
    void testAgainstCompilers();
    bool success();
    void reportToFile(string);
    int getAvgMs();
    TestCaseCompiler* getFastestCompiler();
    TestCaseCompiler* getSlowestCompiler();
    vector<TestCaseCompiler*> getCompilers();

    static string compilers[];
    static string compiler_commands[];
    static int num_compilers;
};

#endif

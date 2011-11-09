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
    vector<TestCaseCompiler> compilers;
public:
    TestCase();
    void generateSource();
    void setSource(string);
    void testAgainstCompilers();
    bool success();
    void reportToFile(string);
    int getAvgMs();
    TestCaseCompiler* getFastestCompiler();
    TestCaseCompiler* getSlowestCompiler();
};

#endif

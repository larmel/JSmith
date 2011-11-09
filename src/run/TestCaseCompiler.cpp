#include "TestCaseCompiler.h"
#include <iostream>

TestCaseCompiler::TestCaseCompiler(std::string name, std::string compiler_path) {
	this->name = name;
	this->tmp_output_file = "test/current_jsmith/_output";
	this->tmp_input_file = "test/current_jsmith/_generated.js";
	this->compiler_path = compiler_path;
}

void TestCaseCompiler::testCompiler()
{
	timeval x;
	struct timezone tz = {0, 0};
	gettimeofday(&x, &tz);

	unsigned long long start = 1000*(unsigned long long)x.tv_sec + x.tv_usec/1000;

	std::string command = compiler_path + " " + tmp_input_file + " > " + tmp_output_file; // " 2>&1";
    bool retcode = system(command.c_str()) == 0;

	gettimeofday(&x, &tz);

	unsigned long long end = 1000*(unsigned long long)x.tv_sec + x.tv_usec/1000;

	this->ms = end - start;

	//std::cout << start << " X " ;
	//std::cout << end << " Gives ms " << this->ms << std::endl;

    std::ifstream file(tmp_output_file.c_str());
    std::string result = "", line;
    while (std::getline(file, line)) {
        result += line;
    }
    file.close();

    this->retcode = retcode;
    this->result = result;
}

int TestCaseCompiler::getReturnCode()
{
	return this->retcode;
}

std::string TestCaseCompiler::getResult()
{
	return this->result;
}

std::string TestCaseCompiler::getName()
{
	return this->name;
}

int TestCaseCompiler::getMs()
{
	return this->ms;
}

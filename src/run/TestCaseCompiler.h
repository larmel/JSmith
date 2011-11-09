#ifndef TESTCASECOMPILER_H_
#define TESTCASECOMPILER_H_
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

class TestCaseCompiler {
private:
    std::string tmp_output_file;
    std::string tmp_input_file;
    std::string compiler_path;
    std::string name;
	int ms;
	int retcode;
	std::string result;
public:
	TestCaseCompiler(std::string, std::string);
	int getReturnCode();
	int getMs();
	void testCompiler();
	std::string getResult();
	std::string getName();
};

#endif /* TESTCASECOMPILER_H_ */

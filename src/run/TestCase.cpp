#include "TestCase.h"
#include "TestCaseCompiler.h"
#include <cassert>

std::string TestCase::compilers[] = {"SpiderMonkey", "Rhino", "V8", "KJS", "Narcissus" };
std::string TestCase::compiler_commands[] = {"js-compilers/SpiderMonkey/js", "/usr/bin/rhino -f", "js-compilers/V8/v8", "/usr/bin/kjs", "js-compilers/Narcissus/njs -f" };
int TestCase::num_compilers = 5;

TestCase::TestCase() {
    this->tmp_output_file = "test/last_run/_output";
    this->tmp_input_file = "test/last_run/_generated.js";

	for(int i = 0; i < num_compilers; i++)
	{
		tccompilers.push_back(new TestCaseCompiler(compilers[i], compiler_commands[i]));
	}
};

TestCase::~TestCase() {
	for(int i = 0; i < num_compilers; i++)
	{
		delete tccompilers.at(i);
	}
};


void TestCase::generateSource() {
    std::string command = "bin/generate > "+this->tmp_input_file;
    system(command.c_str());
}

void TestCase::setSource(std::string path) {
    std::string command = "cp " + path + " "+this->tmp_input_file;
    system(command.c_str());
}

/*
 * Feed generated.js to all available compilers
 */

void TestCase::testAgainstCompilers()
{
	for(int i = 0; i < tccompilers.size(); i++)
	{
		tccompilers.at(i)->testCompiler();
	}
}

void TestCase::removeTempFiles()
{
    std::string rmcmd = "rm -f "+this->tmp_output_file;
    system(rmcmd.c_str());
    rmcmd = "rm -f "+this->tmp_input_file;
    system(rmcmd.c_str());
}

void TestCase::reportToFile(string filename)
{
    char buf [100];
    time_t now = time (NULL);
    struct tm *t = localtime (&now);
    strftime (buf, 100, "%B %d, %Y at %T", t);

    ofstream report(filename.c_str());
    
	assert(!report.fail());

	TestCaseCompiler* fastest = this->getFastestCompiler();
	TestCaseCompiler* slowest = this->getSlowestCompiler();

    report << "/*" << endl;
    report << " * ### Test Summary " << buf << "" << endl;

    report << " * ### Time Taken: Average " << this->getAvgMs() << " ms. " << " Best " <<
			fastest->getName()<< " " << fastest->getMs() << " ms. Worst " << slowest->getName() <<
			" "<<  slowest->getMs() << " ms)." << endl;

    report << " *" << endl;

    report << " * [ <return> ] <compiler> {<runtime>}: ( <variable values> )" << endl;
    report << " * " << endl;

	for(int i = 0; i < tccompilers.size(); i++)
	{
		report << " * " <<  (tccompilers.at(i)->getReturnCode()?"[ OK ]":"[ ERROR ]")
		       << " " << tccompilers.at(i)->getName()
		       << " {" << tccompilers.at(i)->getMs() << "ms}"
		       << ": (" << tccompilers.at(i)->getResult() << ")" << endl;
	}

    report << " */" << endl;
    
    ifstream source(this->tmp_input_file.c_str());
    
    string s;
    while (getline(source, s)) {
        report << s << endl;
    }
    
    source.close();
    report.close();
    
}

bool TestCase::success()
{
	string ret = tccompilers.at(0)->getResult();
	for(int i = 1; i < tccompilers.size(); i++)
	{
		if(ret != tccompilers.at(i)->getResult() || !tccompilers.at(i)->getReturnCode()){
			return false;
		}
	}
	return true;
}

int TestCase::getAvgMs()
{
	int sum = 0;
	int qt = 0;
	for(int i = 1; i < tccompilers.size(); i++)
	{
		qt++;
		sum += tccompilers.at(i)->getMs();
	}
	return sum/qt;
}

TestCaseCompiler* TestCase::getFastestCompiler()
{
	TestCaseCompiler* fastest  = tccompilers.at(0);
	for(int i = 1; i < tccompilers.size(); i++)
	{
		if(tccompilers.at(i)->getMs() < fastest->getMs())
		{
			fastest = tccompilers.at(i);
		}
	}
	return fastest;
}

TestCaseCompiler* TestCase::getSlowestCompiler()
{
	TestCaseCompiler* slowest  = tccompilers.at(0);
	for(int i = 1; i < tccompilers.size(); i++)
	{
		if(tccompilers.at(i)->getMs() > slowest->getMs())
		{
			slowest = tccompilers.at(i);
		}
	}
	return slowest;
}

vector<TestCaseCompiler*> TestCase::getCompilers()
{
	return tccompilers;
}

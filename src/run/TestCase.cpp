
#include "TestCase.h"
#include "TestCaseCompiler.h"
#include <cassert>

TestCase::TestCase() {
	compilers.push_back(TestCaseCompiler("SpiderMonkey", "js-compilers/SpiderMonkey/js"));
	compilers.push_back(TestCaseCompiler("Rhino", "/usr/bin/rhino -f"));
	compilers.push_back(TestCaseCompiler("V8", "js-compilers/V8/v8"));
	compilers.push_back(TestCaseCompiler("KJS", "/usr/bin/kjs"));
	compilers.push_back(TestCaseCompiler("Narcissus", "js-compilers/Narcissus/njs -f"));
};

void TestCase::generateSource() {
    system("bin/generate > test/current_jsmith/_generated.js");
}

/*
 * Feed generated.js to all available compilers
 */

void TestCase::testAgainstCompilers()
{
	for(int i = 0; i < compilers.size(); i++)
	{
		compilers.at(i).testCompiler();
	}
}

void TestCase::reportToFile(string filename)
{
    char buf [100];
    time_t now = time (NULL);
    struct tm *t = localtime (&now);
    strftime (buf, 100, "%B %d, %Y at %T", t);

    ofstream report(filename.c_str());
    
	assert(!report.fail());

    report << "/*" << endl;
    report << " * ### Test Summary " << buf << "" << endl;
    report << " * ### Time Taken: Average " << this->getAvgMs() << " ms" << endl;
    report << " *" << endl;

	for(int i = 0; i < compilers.size(); i++)
	{
		report << " * " <<  compilers.at(i).getName() << ": (" << compilers.at(i).getReturnCode()
			   << ", " << compilers.at(i).getResult() << ")" << endl;
	}

    report << " */" << endl;
    
    ifstream source("test/current_jsmith/_generated.js");
    
    string s;
    while (getline(source, s)) {
        report << s << endl;
    }
    
    source.close();
    report.close();
    
}

bool TestCase::success()
{
	string ret = compilers.at(0).getResult();
	for(int i = 1; i < compilers.size(); i++)
	{
		if(ret != compilers.at(i).getResult()){
			return false;
		}
	}
	return true;
}

int TestCase::getAvgMs()
{
	int sum = 0;
	int qt = 0;
	for(int i = 1; i < compilers.size(); i++)
	{
		qt++;
		sum += compilers.at(i).getMs();
	}
	return sum/qt;
}

TestCaseCompiler* TestCase::getFastestCompiler()
{
	TestCaseCompiler* fastest  = &compilers.at(0);
	for(int i = 1; i < compilers.size(); i++)
	{
		if(compilers.at(i).getMs() < fastest->getMs())
		{
			fastest = &compilers.at(i);
		}
	}
	return fastest;
}

TestCaseCompiler* TestCase::getSlowestCompiler()
{
	TestCaseCompiler* slowest  = &compilers.at(0);
	for(int i = 1; i < compilers.size(); i++)
	{
		if(compilers.at(i).getMs() > slowest->getMs())
		{
			slowest = &compilers.at(i);
		}
	}
	return slowest;
}

#ifndef PROGRAM_CPP
#define PROGRAM_CPP

#include "function.cpp"
#include <map>
#include "identifier.cpp"

class Program {
	
private:
	std::map<std::string, Identifier> *global_identifiers;
	
public:
	
	Program(){
		global_identifiers = new std::map<std::string, Identifier>();
	}
	
	~Program(){
		delete global_identifiers;
	}
	
    void print(std::ostream& out) {
		
		Function f(NULL, this, 0);
		f.print(out);
        
    }
	
	void main(std::ostream& out)
	{
		out << "(function main(){ hash = foo(); print(hash); return 0; })();";
	}	
	
	std::map<std::string, Identifier>::iterator get_global_identifiers()
	{
		return this->global_identifiers->begin();
	}
	
	void add_global_identifier(Identifier id)
	{
		(*this->global_identifiers)[id.name] = id;
	}
	
}; 

#endif
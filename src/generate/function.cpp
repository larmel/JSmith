#include "statement.cpp"

class Function {
	
public:
	
	void print(std::ostream& out){
		out << "function foo() {"; 
		this->contents(out);
		out << std::endl << "return x++; };" << std::endl;
	}
	
	void contents(std::ostream& out){
		Statement s;
		s.print(out);
	}
	
};
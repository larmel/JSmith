#include <iostream>


class Program {
public:
	
    void print(std::ostream& out) {
        out << "var x = 100" << std::endl;
        out << "function foo() { return x++; };" << std::endl;
    };
	
	void main(std::ostream& out) {
		out << "(function main(){ hash = foo(); print(hash); return 0; })();";
	}
};

int main(int argc, char* argv[]) {
    
    std::cout << "/*\tJSmith\t*/" << std::endl;
    
    // Read parameters on how random/how large etc
    
    // Intantiate new random program, and print it to stdout (or to file)
    
	Program c;
	
	c.print(std::cout);
	c.main(std::cout);
	
    return 0;
}







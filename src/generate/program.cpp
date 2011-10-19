#include "function.cpp"

class Program {
public:
	
    void print(std::ostream& out) {
        out << "var x = 1260" << std::endl;
		
		Function f;
		f.print(out);
        
    }
	
	void main(std::ostream& out) {
		out << "(function main(){ hash = foo(); print(hash); return 0; })();";
	}
}; 

#include "function.cpp"

class Program {
	
private:
	vector<Identifier> global_identifiers;
	
public:
	
    void print(std::ostream& out) {
        out << "var x = 1260" << std::endl;
		
		Function f;
		f.print(out);
        
    }
	
	void main(std::ostream& out) {
		out << "(function main(){ hash = foo(); print(hash); return 0; })();";
	}	
	
	void get_global_identifiers(){
		return this.global_identifiers;
	}
	
	void add_global_identifier(Identifier id){
		this.global_identifiers.push_back(id);
	}
	
}; 
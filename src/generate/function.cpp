#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "statement.cpp"
#include "identifier.cpp"
#include "program.cpp"
#include <map>
#include <cstdlib>
#include <cassert>

class Program;


static const char valid_identifier_characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					   	  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'
					    	  };
					    	  
static const int number_of_valid_identifier_characters = 40;



class Function {
private:
	Function *parent;
	Program *prog;
	std::map<std::string, Identifier> local_identifiers;
	int depth;
	int remaining_subfunctions;
	int remaining_statements;

public:
	
	Function(Function *parent, Program *prog, int depth)
	{
		remaining_subfunctions = 3;
		remaining_statements = 3;
		this->parent = parent;
		this->prog = prog;
		this->depth = depth;
	}
	
	void print(std::ostream& out){
		print_tabs(out, 0);
		
		out << "function ";
		std::string s(this->new_random_identifier()->name);
		out << s << " () {\n"; 
		this->contents(out);
		print_tabs(out, 1);
		out << "return x++;\n";
		print_tabs(out, 0);
		out << "}\n" << std::endl;
	}
	
	void contents(std::ostream& out){
		
		if(depth <= 1){
			/*
			 * Generate a new subfunction or statement as long as we haven"t reached
			 * the recursion depth.
			 */
			while(remaining_subfunctions > 0 && remaining_statements > 0){
				// TODO mix these better
				if(remaining_subfunctions > 0){
					Function sub(this, prog, depth + 1);
					sub.print(out);
					remaining_subfunctions--;
				}else{
					Statement sub(this);
					sub.print(out);
					remaining_statements--;
				}
			}
		}else{

			print_tabs(out, 1);
			out << "// Recursion Max Depth" << std::endl;	
		}
		
		assert(remaining_subfunctions>=0);
		assert(remaining_statements>=0);

		Statement s(this);
		s.print(out);
	}
	
	std::map<std::string, Identifier>* get_local_identifiers()
	{
		return &this->local_identifiers;
	}
	
	void add_local_identifier(Identifier x){
		this->local_identifiers[x.name] = x;
	}
	
	// Has to check that this identifier is unique...
	Identifier* new_random_identifier(){
		char navn[5];
		while(true){
			for(int i = 0; i < 4; i++){
				int j = rand() % number_of_valid_identifier_characters;
				navn[i] = valid_identifier_characters[j];
			}
			navn[4] = '\0';
			break;
		}
		
		Identifier i;
		i.type = "function";
		i.name = navn;
		this->add_local_identifier(i);
		
		return &this->local_identifiers[i.name];
		
	}
	
	
	void print_tabs(std::ostream& out, int extra){
		for(int i = 0; i < this->depth + extra; i++){
			out << "\t";		
		}
	}
	
};

#endif

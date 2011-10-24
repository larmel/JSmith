#include "Function.h"
#include "Variable.h"
#include "statement.h"

Function::Function(Function *parent, Program *prog, int depth)
{
	remaining_subfunctions = 3;
	remaining_statements = 3;
	this->parent = parent;
	this->prog = prog;
	this->depth = depth;
}

void Function::print(std::ostream& out){
	print_tabs(out, 0);
	
	out << "function ";
	//std::string s(this->new_random_identifier()->name);
	std::string s(Variable::getNewRandomIdentifier(this));
	out << s << " () {\n"; 
	this->contents(out);
	print_tabs(out, 1);
	out << "return x++;\n";
	print_tabs(out, 0);
	out << "}\n" << std::endl;
}

void Function::contents(std::ostream& out){
	
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
	} else {

		print_tabs(out, 1);
		out << "// Recursion Max Depth" << std::endl;	
	}
	
	assert(remaining_subfunctions>=0);
	assert(remaining_statements>=0);

	Statement s(this);
	s.print(out);
}

void Function::print_tabs(std::ostream& out, int extra){
	for(int i = 0; i < this->depth + extra; i++){
		out << "\t";		
	}
}


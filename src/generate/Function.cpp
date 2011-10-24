#include "Function.h"
#include "Variable.h"
#include "Statement.h"

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
	std::string s = this->getNewRandomIdentifier();
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


Variable* Function::getRandomVariable(Type t) {
    // TODO: Recur on parent functions to get whole scope
    
    if (this->context.size() == 0) return NULL;
    int pos = rand() % this->context.size();
    return this->context[pos];
}

std::string Function::getNewRandomIdentifier() {
    // TODO: Recur on parent to check that it is unique
    char name[5];
	while (true) {
		for (int i = 0; i < 4; i++) {
			int j = rand() % number_of_valid_identifier_characters;
			name[i] = valid_identifier_characters[j];
		}
		name[4] = '\0';
		break;
	}
	
	return name;
}


#include "Function.h"
#include "Variable.h"
#include "Statement.h"

Function::Function(Function *parent, int depth)
{
	remaining_subfunctions = 3;
	remaining_statements = 3;
	
	this->parent = parent;
	this->depth = depth;
	
	generate();
}

void Function::generate() {
    this->identifier = this->getNewRandomIdentifier();
    
    // The root function is special
    if (this->depth == 0) 
    {
        for (int i = 0; i < 10; ++i) {
            this->statement_list.push_back(new Statement(this));
        }
        
        for (int i = 0; i < 3; ++i) {
            this->function_list.push_back(new Function(this, depth + 1));
        }
    }
    
    // Function at first level
    else if (depth == 1) {
	    /*
	     * Generate a new subfunction or statement as long as we haven"t reached
	     * the recursion depth.
	     */
	    while(remaining_subfunctions > 0 && remaining_statements > 0){
		    // TODO mix these better
		    if (remaining_subfunctions > 0) {
			    this->function_list.push_back(new Function(this, depth + 1));
			    remaining_subfunctions--;
		    } else {
                this->statement_list.push_back(new Statement(this));
			    remaining_statements--;
		    }
	    }
    }
}

void Function::print(std::ostream& out, unsigned int indentation){
    
    // Special printing for outer function
    if (depth == 0) {
        for (int i = 0; i < statement_list.size(); ++i) {
            statement_list[i]->print(out, indentation);
        }
        for (int i = 0; i < function_list.size(); ++i) {
            function_list[i]->print(out, indentation);
        }
        
        // Print main function?
    }
    else
    {
        for (int t = 0; t < indentation; ++t) out << "   ";
        out << "function " << this->identifier << "() {" << std::endl;
        
        for (int i = 0; i < statement_list.size(); ++i) {
            statement_list[i]->print(out, indentation + 1);
        }
        for (int i = 0; i < function_list.size(); ++i) {
            function_list[i]->print(out, indentation + 1);
        }
        
        for (int t = 0; t < indentation; ++t) out << "   ";
        out << "   " << "return 0;" << std::endl;
        
        for (int t = 0; t < indentation; ++t) out << "   ";
        out << "}" << std::endl;
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


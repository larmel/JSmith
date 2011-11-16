#include "FunctionExpression.h"
#include "Variable.h"
#include "Scope.h"


FunctionExpression::FunctionExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    // Fetch a local function (we're only allowed to call functions on the same level)
    this->function = parent_scope->getRandomFunction();

    Scope *scope = new Scope(parent_scope);

    // Create some number of SourceElements
    // Might want to enforce some return type
    for (int i = 0; i < 2; ++i) {
        this->statements.push_back( Statement::newRandomStatement(scope, depth+1) );
    }

    RandomDiscreteDistribution return_or_not (2, 50, 1);

    if(return_or_not.getChosenIndex() == 0){
        this->statements.push_back(new ReturnStatement(this, depth));
    }





    int num_args = rand() % 4;


    for (int i = 0; i < num_args; i++) {
    	arguments.push_back(scope->generateRandomNumberVariable());

    }



    // TODO Create expressions to use as args
}

void FunctionExpression::print(std::ostream& out) const {
    if (this->function == NULL)
    {
        // No functions available, what to do?
        out << "1";
    } 
    else
    {
        out << *this->function << "(";
        for (int i = 0; i < arguments.size(); i++) {
        	out << *arguments.at(i);
        	if(i != arguments.size() -1){
        		out << ", ";
        	}
        }
        out << ")" << endl;
        out << "{" << std::endl;
		for (int i = 0; i < statements.size(); ++i) {
			statements[i]->print(out);
		}
		out << indent << "}" << std::endl;
    }
}


std::ostream& operator<<(std::ostream& out, const FunctionExpression& e) {
    e.print(out);
    return out;
}


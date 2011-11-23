#include "MapExpression.h"
#include "Scope.h"
#include "Statement.h"
#include "RandomDiscreteDistribution.h"
#include "ReturnStatement.h"
#include "FunctionExpression.h"
#include "../Random.h"
#include "Variable.h"

MapExpression::MapExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    this->depth = depth;
    scope = new Scope(parent_scope);

    // Generate a random number of properties
    int num_properties = Random::randint(2,5);
    for(int i = 0; i < num_properties; i++)
    {
    	RandomDiscreteDistribution r(2,3,5);

    	if(r.getChosenIndex() == 0)
    	{
			// Function
			FunctionExpression* e = new FunctionExpression(scope, depth+1);
			Variable* left_variable = scope->generateFunctionVariable( e->numberOfArguments() );
			this->expressions.push_back((Expression*)e);
			this->properties.push_back(left_variable);
			//scope->add(left_variable);
			parent_scope->add(left_variable);
    	}
    	else
    	{
			// Expression
			Expression* e = Expression::generateExpression(scope, depth+1);
			Variable* left_variable = scope->generateNumberVariable();
			this->expressions.push_back(e);
			this->properties.push_back(left_variable);
			//scope->add(left_variable);
			parent_scope->add(left_variable);
    	}

    }
}


void MapExpression::print(std::ostream& out) const {

    out << "{" << std::endl;
    // Fake indentation
    /*for (int i = 0; i < depth; ++i) {
        out << "    ";
    }*/

    for(int i=0; i < this->expressions.size(); i++ )
    {
        for (int j = 0; j < depth; ++j) {
            out << "    ";
        }
        out << "\"" << *this->properties.at(i) << "\": " << *this->expressions.at(i);
        if(i != this->expressions.size()-1)
        {
        	out << ",";
        }

		out <<  std::endl;
    }


    // Fake indentation
    for (int i = 0; i < depth-1; ++i) {
        out << "    ";
    }
    out << "}";
}

std::ostream& operator<<(std::ostream& out, const MapExpression& e) {
    e.print(out);
    return out;
}

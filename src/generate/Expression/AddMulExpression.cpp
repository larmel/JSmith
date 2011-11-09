#include "AddMulExpression.h"
#include "Variable.h"

AddMulExpression::AddMulExpression(Scope* parent_scope, int depth, Type type) : Expression(parent_scope, depth, type) {
    
    switch (type) {
    // For numbers, you can have all types of arithmetic operands
    case NUMBER_T:
    {
		this->op1 = Expression::generateExpression(this->scope, this->depth+1, NUMBER_T);
		this->op2 = Expression::generateExpression(this->scope, this->depth+1, NUMBER_T);
		if (this->op1 == NULL)
			std::cerr << "No operator 1\n";
		if (this->op1 == NULL)
			std::cerr << "No operator 2\n";

		// Pick the operator
		int op_id = rand() % 4;
		switch (op_id) {
		case 0: this->op = "+"; break;
		case 1: this->op = "-"; break;
		case 2: this->op = "*"; break;
		case 3: this->op = "/"; break;
		}
    } break;

    // Strings can only have the + (concatenation) operator
    case STRING_T:
    {
		this->op1 = Expression::generateExpression(this->scope, this->depth+1, STRING_T);
		this->op2 = Expression::generateExpression(this->scope, this->depth+1, STRING_T);

		this->op = "+";
    } break;
    
    default:
    	std::cerr << "Unimplemented type for AddMulExpression: " << type<<"\n";
    	exit(1);
    	break;

    }//endswitch

}

void AddMulExpression::print(std::ostream& out) const {
    // Print variable
    op1->print(out);
    out << this->op;
    op2->print(out);
}


std::ostream& operator<<(std::ostream& out, const AddMulExpression& e) {
    e.print(out);
    return out;
}


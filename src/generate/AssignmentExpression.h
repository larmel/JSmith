#ifndef ASSIGNMENTEXPRESSION_H
#define ASSIGNMENTEXPRESSION_H 
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"


class Variable;
class Scope;
 
class AssignmentExpression : public Expression {

private:
    Variable *left_side;
    Expression *right_side;
    

public:
    AssignmentExpression(Scope* parent_scope, int depth);
    
    void print(std::ostream& out, unsigned int depth);
};
 
 
#endif

#ifndef MAP_EXPRESSION_H
#define MAP_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Expression.h"


class Variable;
class Statement;
class Scope;
 
class MapExpression : public Expression {
private:
	int depth; // Used as statement depth
	std::vector<Expression*> expressions;
	std::vector<Variable*> properties;
public:
	MapExpression(Scope* parent_scope, int depth, Variable* mapvar);
    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const MapExpression& e);
    void setParent(Variable*);
};
 #endif

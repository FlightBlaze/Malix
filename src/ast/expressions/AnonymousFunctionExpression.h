#ifndef MALIX_ANONYMOUSFUNCTIONEXPRESSION_H
#define MALIX_ANONYMOUSFUNCTIONEXPRESSION_H


#include "Expression.h"
#include "../statements/Statement.h"

class AnonymousFunctionExpression : public Expression {
public:
    explicit AnonymousFunctionExpression(std::vector<std::string> args, Statement * body)
        : args(std::move(args)), body(body) {}
    Value eval() override;
private:
    std::vector<std::string> args;
    Statement * body;
};


#endif //MALIX_ANONYMOUSFUNCTIONEXPRESSION_H

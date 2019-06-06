#ifndef MALIX_ANONYMOUSOBJECTEXPRESSION_H
#define MALIX_ANONYMOUSOBJECTEXPRESSION_H


#include "Expression.h"

class AnonymousObjectExpression : public Expression {
public:
    explicit AnonymousObjectExpression(std::map<std::string, Expression *> values)
        : values(std::move(values)) {}
    ~AnonymousObjectExpression() override;
    Value eval() override;
private:
    std::map<std::string, Expression *> values;
};


#endif //MALIX_ANONYMOUSOBJECTEXPRESSION_H

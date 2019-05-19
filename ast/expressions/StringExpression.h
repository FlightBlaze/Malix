#ifndef MALIX_STRINGEXPRESSION_H
#define MALIX_STRINGEXPRESSION_H


#include "Expression.h"

class StringExpression : public Expression {
public:
    explicit StringExpression(std::string string) : string(std::move(string)) {}
    Value eval() override;
private:
    std::string string;
};


#endif //MALIX_STRINGEXPRESSION_H

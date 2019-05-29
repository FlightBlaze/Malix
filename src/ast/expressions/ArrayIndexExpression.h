#ifndef MALIX_ARRAYINDEXEXPRESSION_H
#define MALIX_ARRAYINDEXEXPRESSION_H

#include "Expression.h"
#include "../../lib/Variables.h"

class ArrayIndexExpression : public Expression {
public:
    explicit ArrayIndexExpression(std::string name, std::vector<Expression *> indices)
        : name(std::move(name)), indices(std::move(indices)) {}
    ~ArrayIndexExpression() override;
    Value getArray(Value value);
    Value consume(Value value);
    Value eval() override;

    int lastIndex();
    int index(int index);

private:
    std::string name;
    std::vector<Expression *> indices;
};


#endif //MALIX_ARRAYINDEXEXPRESSION_H

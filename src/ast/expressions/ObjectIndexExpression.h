#ifndef MALIX_OBJECTINDEXEXPRESSION_H
#define MALIX_OBJECTINDEXEXPRESSION_H


#include "Expression.h"
#include <utility>

class ObjectIndexExpression : public Expression {
public:
    explicit ObjectIndexExpression(std::string name, std::vector<std::string> indices)
    : name(std::move(name)), indices(std::move(indices)) {}
    Value getObject(Value value);
    Value consume(Value value);
    Value eval() override;

    std::string lastIndex();
    std::string index(int index);

private:
    std::string name;
    std::vector<std::string> indices;
};


#endif //MALIX_OBJECTINDEXEXPRESSION_H

#ifndef MALIX_BLOCKEXPRESSION_H
#define MALIX_BLOCKEXPRESSION_H


#include "Expression.h"
#include "../statements/BlockStatement.h"
#include "../statements/ReturnStatement.h"
#include "../../lib/Variables.h"

class BlockExpression : public Expression {
public:
    explicit BlockExpression(BlockStatement * statement) : statement(statement) {}
    ~BlockExpression() override;
    Value eval() override;
private:
    BlockStatement * statement;
};


#endif //MALIX_BLOCKEXPRESSION_H

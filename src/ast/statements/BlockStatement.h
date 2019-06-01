#ifndef MALIX_BLOCKSTATEMENT_H
#define MALIX_BLOCKSTATEMENT_H

#include <vector>
#include "Statement.h"

class BlockStatement : public Statement {
public:
    BlockStatement() = default;
    explicit BlockStatement(std::vector<Statement *> statements)
        : statements(std::move(statements)) {}
    ~BlockStatement() override;
    void execute() override;
    void add(Statement * statement);
private:
    std::vector<Statement *> statements;
};


#endif //MALIX_BLOCKSTATEMENT_H

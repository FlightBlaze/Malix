#ifndef MALIX_BLOCKSTATEMENT_H
#define MALIX_BLOCKSTATEMENT_H

#include <vector>
#include "Statement.h"

class BlockStatement : public Statement {
public:
    ~BlockStatement() override;
    void execute() override;
    void add(Statement * statement);
private:
    std::vector<Statement *> statements;
};


#endif //MALIX_BLOCKSTATEMENT_H

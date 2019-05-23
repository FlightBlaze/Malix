#include "BlockStatement.h"

void BlockStatement::execute() {
    for (Statement * statement : statements)
        statement->execute();
}

void BlockStatement::add(Statement *statement) {
    statements.push_back(statement);
}

BlockStatement::~BlockStatement() {
    for (Statement * statement : statements) {
        delete statement;
    }
}

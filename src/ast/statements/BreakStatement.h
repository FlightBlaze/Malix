#ifndef MALIX_BREAKSTATEMENT_H
#define MALIX_BREAKSTATEMENT_H


#include <exception>
#include "Statement.h"

class BreakStatement : public Statement, std::exception {
public:
    void execute() override;
};


#endif //MALIX_BREAKSTATEMENT_H

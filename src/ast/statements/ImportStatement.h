#ifndef MALIX_IMPORTSTATEMENT_H
#define MALIX_IMPORTSTATEMENT_H

#include "Statement.h"
#include "../expressions/Expression.h"
#include "../../lib/packages/Package.h"
#include "../../lib/Packages.h"
#include <boost/filesystem.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

class ImportStatement : public Statement {
public:
    explicit ImportStatement(Expression * pathExpression, Expression * nameExpression)
        : pathExpression(pathExpression), nameExpression(nameExpression) {}
    ~ImportStatement() override;

    void execute() override;
private:
    Expression * pathExpression;
    Expression * nameExpression;
};


#endif //MALIX_IMPORTSTATEMENT_H

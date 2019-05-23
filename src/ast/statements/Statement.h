#ifndef MALIX_STATEMENT_H
#define MALIX_STATEMENT_H

class Statement {
public:
    virtual void execute() = 0;
    virtual ~Statement() = default;
};

#endif //MALIX_STATEMENT_H

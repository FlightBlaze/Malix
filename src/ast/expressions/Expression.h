#ifndef MALIX_EXPRESSION_H
#define MALIX_EXPRESSION_H

#include "../../utils/Value.h"

class Expression {
public:
    virtual Value eval() = 0;
    virtual ~Expression() = default;
};


#endif //MALIX_EXPRESSION_H

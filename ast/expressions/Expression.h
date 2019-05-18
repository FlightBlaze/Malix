#ifndef MYLANG_EXPRESSION_H
#define MYLANG_EXPRESSION_H

#include "../../utils/Value.h"

class Expression {
public:
    virtual Value eval() = 0;
};


#endif //MYLANG_EXPRESSION_H

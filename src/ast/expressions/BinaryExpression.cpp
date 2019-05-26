#include <stdexcept>
#include "BinaryExpression.h"

Value BinaryExpression::eval() {
    Value one = expression1->eval();
    Value too = expression2->eval();

    switch (operatorChar) {
        case '+': {
            if (one.isNumber())
                return Value(one.getNumberValue() + too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() + too.getBoolValue());
            else if (one.isString())
                return Value(one.getStringValue() += too.getStringValue());
            else return one;
        } case '-': {
            if (one.isNumber())
                return Value(one.getNumberValue() - too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() - too.getBoolValue());
            else return one;
        } case '*': {
            if (one.isNumber())
                return Value(one.getNumberValue() * too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() * too.getBoolValue());
            return one;
        } case '/': {
            if (one.isNumber())
                return Value(one.getNumberValue() / too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() / too.getBoolValue());
            else return one;
        } case '%': {
            if (one.isNumber() || one.isBool()) // because % operation invalid for double
                return Value((double) ((int) one.getNumberValue() % (int) too.getNumberValue()));
            else return one;
        }
    }

    return Value();
}

BinaryExpression::~BinaryExpression() {
    delete expression1;
    delete expression2;
}

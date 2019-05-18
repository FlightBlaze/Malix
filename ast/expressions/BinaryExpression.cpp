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
            else return Value();
        } case '-': {
            if (one.isNumber())
                return Value(one.getNumberValue() - too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() - too.getBoolValue());
            else return Value();
        } case '*': {
            if (one.isNumber())
                return Value(one.getNumberValue() * too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() * too.getBoolValue());
            else return Value();
        } case '/': {
            if (one.isNumber())
                return Value(one.getNumberValue() / too.getNumberValue());
            else if (one.isBool())
                return Value((double) one.getBoolValue() / too.getBoolValue());
            else return Value();
        } case '%': {
            if (one.isNumber() || one.isBool()) // because % operation invalid for double
                return Value((double) ((int) one.getNumberValue() % (int) too.getNumberValue()));
            else return Value();
        }
    }

    return Value();
}

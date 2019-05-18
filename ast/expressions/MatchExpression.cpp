#include "MatchExpression.h"

Value MatchExpression::eval() {
    Value one = expression1->eval();
    Value too = expression2->eval();

    switch (operatorChar) {
        case '+': {
            if (one.isDouble())
                return Value(one.getDoubleValue() + too.getDoubleValue());
            else if (one.isInt())
                return Value(one.getIntValue() + too.getIntValue());
            else if (one.isBool())
                return Value(one.getBoolValue() + too.getBoolValue());
            else return Value();
        } case '-': {
            if (one.isDouble())
                return Value(one.getDoubleValue() - too.getDoubleValue());
            else if (one.isInt())
                return Value(one.getIntValue() - too.getIntValue());
            else if (one.isBool())
                return Value(one.getBoolValue() - too.getBoolValue());
            else return Value();
        } case '*': {
            if (one.isDouble())
                return Value(one.getDoubleValue() * too.getDoubleValue());
            else if (one.isInt())
                return Value(one.getIntValue() * too.getIntValue());
            else if (one.isBool())
                return Value(one.getBoolValue() * too.getBoolValue());
            else return Value();
        } case '/': {
            if (one.isDouble())
                return Value(one.getDoubleValue() / too.getDoubleValue());
            else if (one.isInt())
                return Value(one.getIntValue() / too.getIntValue());
            else if (one.isBool())
                return Value(one.getBoolValue() / too.getBoolValue());
            else return Value();
        } case '%': {
            if (one.isDouble() || one.isInt()) // because % operation invalid for double
                return Value(one.getIntValue() % too.getIntValue());
            else if (one.isBool())
                return Value(one.getBoolValue() % too.getBoolValue());
            else return Value();
        }
    }

    return Value();
}

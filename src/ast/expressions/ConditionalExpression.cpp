#include "ConditionalExpression.h"

Value ConditionalExpression::eval() {
    Value one = expression1->eval();
    Value too = expression2->eval();

    if (one.isNumber()) {
        switch (operatorChar) {
            case '>': return Value(one.getNumberValue() > too.getNumberValue());
            case '<': return Value(one.getNumberValue() < too.getNumberValue());
            case '!': return Value(one.getNumberValue() != too.getNumberValue());
            case '=':
            default : return Value(one.getNumberValue() == too.getNumberValue());

        }
    } else if (one.isBool()) {
        switch (operatorChar) {
            case '>': return Value(one.getBoolValue() > too.getBoolValue());
            case '<': return Value(one.getBoolValue() < too.getBoolValue());
            case '!': return Value(one.getBoolValue() != too.getBoolValue());
            case '=':
            default : return Value(one.getBoolValue() == too.getBoolValue());
        }
    } else if (one.isString()) {
        switch (operatorChar) {
            case '>': return Value(one.getStringValue() > too.getStringValue());
            case '<': return Value(one.getStringValue() < too.getStringValue());
            case '!': return Value(one.getStringValue() != too.getStringValue());
            case '=':
            default : return Value(one.getStringValue().length() == too.getStringValue().length());
        }
    }

    return Value(false);
}

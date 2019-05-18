#include <iostream>
#include "parser/Lexer.h"
#include "ast/expressions/MatchExpression.h"
#include "ast/expressions/DoubleExpression.h"
#include "ast/expressions/IntegerExpression.h"

int main() {
    Lexer lexer("2.5 + 2.0 * 2 / 2");
    for (Token token : lexer.tokenize()) {
        std::cout << "StringValue -> " << token.getContent().getStringValue() << std::endl;
    }

    Expression * valueExpression1 = new IntegerExpression(26);
    Expression * valueExpression2 = new IntegerExpression(5);

    MatchExpression * expr = new MatchExpression('%', valueExpression1, valueExpression2);
    std::cout << expr->eval().getStringValue() << std::endl;

    return 0;
}
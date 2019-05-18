#include <iostream>
#include "parser/Lexer.h"
#include "ast/expressions/BinaryExpression.h"
#include "ast/expressions/NumberExpression.h"
#include "parser/Parser.h"

int main() {
    Lexer lexer("(2.0. + 2) * -2");
    Parser parser(lexer.tokenize());
    for (Expression * expr : parser.parse()) {
        std::cout << expr->eval().getStringValue() << std::endl;
    }

    return 0;
}
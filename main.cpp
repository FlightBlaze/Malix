#include <iostream>
#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "ast/expressions/ConstantExpression.h"

int main() {
    ConstantExpression::consts.insert(std::pair<std::string, Value>("PI", Value(3.14159265359)));
    ConstantExpression::consts.insert(std::pair<std::string, Value>("E", Value(2.71828182845)));

    Lexer lexer("(PI + E) * 2");
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    for (Expression * expr : parser.parse()) {
        std::cout << expr->eval().getStringValue() << std::endl;
    }

    return 0;
}
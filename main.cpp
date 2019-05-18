#include <iostream>
#include "parser/Lexer.h"
#include "ast/expressions/MatchExpression.h"
#include "ast/expressions/NumberExpression.h"
#include "parser/Parser.h"

int main() {
    Lexer lexer("2 + 2 * 2");
    std::vector<Token> tokens = lexer.tokenize();
    for (Token token : tokens) {
        std::cout << "StringValue -> " << token.getContent().getStringValue() << std::endl;
    }

    std::cout << std::endl;

    Parser parser(tokens);
    for (Expression * expr : parser.parse()) {
        std::cout << expr->eval().getStringValue() << std::endl;
    }

    return 0;
}
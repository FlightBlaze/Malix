#include <iostream>
#include <fstream>
#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "ast/expressions/ConstantExpression.h"

int main() {
    Constants::addConstant("PI", Value(3.14159265359));
    Constants::addConstant("E",  Value(2.71828182845));

    std::ifstream fileStream;

    fileStream.open("main.malix");

    if (!fileStream) {
        std::cerr << "main.malix not found!";
        exit(1);
    }

    std::string input((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));
    Lexer lexer(input);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    for (Expression * expr : parser.parse()) {
        std::cout << expr->eval().getStringValue() << std::endl;
    }

    return 0;
}
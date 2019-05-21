#include <iostream>
#include <fstream>
#include <ctime>
#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "lib/Variables.h"
#include "ast/statements/BreakStatement.h"
#include "ast/statements/ContinueStatement.h"

int main(int argc, char ** argv) {
    std::clock_t start = std::clock();
    double duration;

    Variables::setVariable("PI", Value(3.14159265359));
    Variables::setVariable("E",  Value(2.71828182845));

    std::ifstream fileStream;

    fileStream.open(argv[1]);
    if (!fileStream) {
        std::cerr << argv[1] << " not found!";
        exit(1);
    }

    std::string input((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));
    Lexer lexer(input);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    for (Statement * statement : parser.parse()) {
        try {
            statement->execute();
        } catch (BreakStatement operation) {}
          catch (ContinueStatement operation) {} // avoid errors
    }

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\n\n" << "Total time: " << duration << std::endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <ctime>
#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "lib/Variables.h"
#include "ast/statements/BreakStatement.h"
#include "ast/statements/ContinueStatement.h"
#include "ast/statements/ReturnStatement.h"
#include "lib/Packages.h"
#include "lib/packages/StdPackage.h"
#include "lib/packages/MathPackage.h"
#include "lib/packages/FileSystemPackage.h"


int main(int argc, char ** argv) {
    Packages::addPackage(new StdPackage());
    Packages::addPackage(new MathPackage());
    Packages::addPackage(new FileSystemPackage());

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
            delete statement;
        } catch (BreakStatement operation) {}
          catch (ContinueStatement operation) {} // avoid errors
          catch (ReturnStatement operation) {} // avoid errors
    }

    return 0;
}
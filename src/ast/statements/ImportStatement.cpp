#include <fstream>
#include "ImportStatement.h"
#include "../../parser/Lexer.h"
#include "../../parser/Parser.h"

ImportStatement::~ImportStatement() {
    delete pathExpression;
    delete nameExpression;
}

void ImportStatement::execute() {
    std::string path = pathExpression->eval().getStringValue();
    std::string name = path;

    if (nameExpression != nullptr) {
        name = nameExpression->eval().getStringValue();
    }

    if (fs::exists(path + ".malix")) {
        std::ifstream fileStream(path + ".malix");
        std::string input((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));
        Lexer lexer(input);
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        std::vector<Statement *> statements = parser.parse();
        BlockStatement * statement = new BlockStatement(statements);

        if (name != path)
            Packages::addPackage(new UserPackage(name, statement));
        else {
            Variables::push();
            Variables::clean();

            try {
                statement->execute();
            } catch (BreakStatement operation) {}
              catch (ContinueStatement operation) {}
              catch (ReturnStatement operation) {}
            delete statement;
            Variables::pop();
        }
    } else {
        std::string method = std::string(std::string("malix_") += name + "_package");

#ifdef _WIN32
        HINSTANCE handle = LoadLibrary(path.c_str());
#else
        void * handle = dlopen(path.c_str(), RTLD_LAZY);
#endif

        if (handle != nullptr) {
#ifdef _WIN32
            auto (* ptr)() = (Package * (*)()) GetProcAddress(handle, method.c_str());
#else
            auto (*ptr)() = (Package *(*)()) dlsym(handle, method.c_str());
#endif

            if (ptr != nullptr) {
                Packages::addPackage(reinterpret_cast<Package *>(ptr()));
            } else {
                throw std::runtime_error(std::string("Unable to load `") += name += "` package");
            }
        } else {
            throw std::runtime_error(std::string("Unable to open `") += path += "` file as shared library");
        }
    }
}

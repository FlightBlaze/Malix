#ifndef MALIX_LEXER_H
#define MALIX_LEXER_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include "token/Token.h"

class Lexer {
public:
    Lexer(std::string input);
    std::vector<Token> tokenize();

    char static getOperator(TType type);
private:
    std::string input;
    std::vector<Token> tokens;
    std::map<char, TType> operators;
    std::map<std::string, TType> keywords;
    int position;

    char peek(int relPos);
    char next();

    void addToken(TType type, Value content);
    TType isKeyWord(std::string keyword);

    void tokenizeNumber();
    void tokenizeWord();
    void tokenizeString();
    void tokenizeComment();
};


#endif //MALIX_LEXER_H

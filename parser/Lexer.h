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

    char static getOperator(TokenType type);
private:
    std::string input;
    std::vector<Token> tokens;
    std::map<char, TokenType> operators;
    std::map<std::string, TokenType> keywords;
    int position;

    char peek(int relPos);
    char next();

    void addToken(TokenType type, Value content);
    bool isKeyWord(std::string keyword);

    void tokenizeNumber();
    void tokenizeWord();
    void tokenizeString();
};


#endif //MALIX_LEXER_H

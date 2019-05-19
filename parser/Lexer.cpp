#include <sstream>
#include "Lexer.h"

Lexer::Lexer(std::string input) {
    this->input    = std::move(input);
    this->tokens   = std::vector<Token>();
    this->position = 0;

    this->operators['+'] = TokenType::PLUS;
    this->operators['-'] = TokenType::MINUS;
    this->operators['*'] = TokenType::STAR;
    this->operators['/'] = TokenType::SLASH;
    this->operators['%'] = TokenType::PERCENT;

    // not operators, but easy to parse as operator
    this->operators['('] = TokenType::L_PAREN;
    this->operators[')'] = TokenType::R_PAREN;
    this->operators['='] = TokenType::EQ;

    this->keywords["var"] = TokenType::KEYWORD;
    this->keywords["print"] = TokenType::KEYWORD;
}

std::vector<Token> Lexer::tokenize() {
    while (position < this->input.length()) {
        char current = next();

        if (isdigit(current)) tokenizeNumber();
        if (isalpha(current)) tokenizeWord();
        else if (this->operators.find(current) != this->operators.end())
            addToken(this->operators[current], Value(std::string(1, getOperator(this->operators[current]))));
    }

    return this->tokens;
}

char Lexer::peek(int relPos) {
    unsigned int pos = this->position + relPos;

    if (pos < this->input.length())
        return this->input.at(pos);
    else return '\0';
}

char Lexer::next() {
    char c = peek(0);
    this->position++;
    return c;
}

void Lexer::addToken(TokenType type, Value content) {
    this->tokens.emplace_back(type, content);
}

void Lexer::tokenizeNumber() {
    std::stringstream stream;
    bool dotExists = false;

    stream << peek(-1); // add current char to stream

    while (true) {
        if (peek(0) == '.') {
            if (dotExists) throw std::runtime_error(std::string("Invalid float number at position: ") += std::to_string(position));
            dotExists = true;
        }

        if (isdigit(peek(0)) || peek(0) == '.') stream << next();
        else break;
    }

    double number;
    stream >> number;
    addToken(TokenType::NUMBER, Value(number));
}

void Lexer::tokenizeWord() {
    std::stringstream stream;
    std::string word;

    stream << peek(-1);

    while (true) {
        if (isalpha(peek(0)) && peek(0) != '_' && peek(0) != '$') stream << next();
        else break;
    }

    stream >> word;
    if (!isKeyWord(word)) addToken(TokenType::WORD, Value(word));
    else addToken(TokenType::KEYWORD, Value(word));
}

char Lexer::getOperator(TokenType type) {
    switch (type) {
        case TokenType::PLUS:    return '+';
        case TokenType::MINUS:   return '-';
        case TokenType::STAR:    return '*';
        case TokenType::SLASH:   return '/';
        case TokenType::PERCENT: return '%';
        default:
            return '\0';
    }
}

bool Lexer::isKeyWord(std::string keyword) {
    auto it = keywords.find(keyword);
    return it != keywords.end();
}

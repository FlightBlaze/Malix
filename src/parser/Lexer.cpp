#include <sstream>
#include <algorithm>
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
    this->operators['{'] = TokenType::L_BRACKET;
    this->operators['}'] = TokenType::R_BRACKET;
    this->operators['['] = TokenType::L_SQUARE_BRACKET;
    this->operators[']'] = TokenType::R_SQUARE_BRACKET;
    this->operators['='] = TokenType::EQ;
    this->operators['<'] = TokenType::LT;
    this->operators['>'] = TokenType::GT;
    this->operators['!'] = TokenType::EXCLAMATION;
    this->operators['&'] = TokenType::AMP;
    this->operators['|'] = TokenType::BAR;
    this->operators[','] = TokenType::COMMA;

    this->keywords["var"] = TokenType::VAR;
    this->keywords["print"] = TokenType::PRINT;
    this->keywords["println"] = TokenType::PRINTLN;
    this->keywords["true"] = TokenType::TRUE;
    this->keywords["false"] = TokenType::FALSE;
    this->keywords["if"] = TokenType::IF;
    this->keywords["else"] = TokenType::ELSE;
    this->keywords["nil"] = TokenType::NIL;
    this->keywords["while"] = TokenType::WHILE;
    this->keywords["for"] = TokenType::FOR;
    this->keywords["break"] = TokenType::BREAK;
    this->keywords["continue"] = TokenType::CONTINUE;
    this->keywords["def"] = TokenType::DEF;
    this->keywords["return"] = TokenType::RETURN;
    this->keywords["use"] = TokenType::USE;
    this->keywords["import"] = TokenType::IMPORT;
    this->keywords["as"] = TokenType::AS;
}

std::vector<Token> Lexer::tokenize() {
    while (position < this->input.length()) {
        char current = next();

        if (isdigit(current)) tokenizeNumber();
        else if (isalpha(current)) tokenizeWord();
        else if (current == '"') tokenizeString();
        else if (current == ';') tokenizeComment();
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

    while (this->position < this->input.size()) {
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

    while (this->position < this->input.size()) {
        if (isalpha(peek(0)) && peek(0) != '_' && peek(0) != '$') stream << next();
        else break;
    }

    stream >> word;
    addToken(isKeyWord(word), Value(word));
}

void Lexer::tokenizeString() {
    std::stringstream stream;
    std::string string;

    char current = next();
    while (current != '"') {
        if (current == '\\') {
            current = next();
            switch (current) {
                case '"': stream << "\""; current = next(); continue;
                case 'n': stream << "\n"; current = next(); continue;
                case 't': stream << "\t"; current = next(); continue;
                default:  stream << "\\"; current = next(); continue;
            }
        }

        stream << current;
        current = next();
    }

    addToken(TokenType::STRING, Value(stream.str()));
}

void Lexer::tokenizeComment() {
    char current = next();


    if (current == ';') { // One line comment
        while (this->position < this->input.size()) {
            if (current == '\n') break;
            current = next();
        }
    } else { // Multiline comment
        while (this->position < this->input.size()) {
            if (current == ';') break;
            current = next();
        }

        next(); // skip ;
    }
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

TokenType Lexer::isKeyWord(std::string keyword) {
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    auto it = keywords.find(keyword);
    if (it != keywords.end()) return it->second;
    else return TokenType::WORD;
}

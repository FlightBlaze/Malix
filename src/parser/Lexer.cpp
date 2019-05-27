#include <sstream>
#include <algorithm>
#include "Lexer.h"

Lexer::Lexer(std::string input) {
    this->input    = std::move(input);
    this->tokens   = std::vector<Token>();
    this->position = 0;

    this->operators['+'] = PLUS;
    this->operators['-'] = MINUS;
    this->operators['*'] = STAR;
    this->operators['/'] = SLASH;
    this->operators['%'] = PERCENT;

    // not operators, but easy to parse as operator
    this->operators['('] = L_PAREN;
    this->operators[')'] = R_PAREN;
    this->operators['{'] = L_BRACKET;
    this->operators['}'] = R_BRACKET;
    this->operators['['] = L_SQUARE_BRACKET;
    this->operators[']'] = R_SQUARE_BRACKET;
    this->operators['='] = EQ;
    this->operators['<'] = LT;
    this->operators['>'] = GT;
    this->operators['!'] = EXCLAMATION;
    this->operators['&'] = AMP;
    this->operators['|'] = BAR;
    this->operators[','] = COMMA;

    this->keywords["var"] = VAR;
    this->keywords["define"] = DEFINE;
    this->keywords["package"] = PACKAGE;
    this->keywords["print"] = PRINT;
    this->keywords["println"] = PRINTLN;
    this->keywords["true"] = TRUE;
    this->keywords["false"] = FALSE;
    this->keywords["if"] = IF;
    this->keywords["else"] = ELSE;
    this->keywords["nil"] = NIL;
    this->keywords["do"] = DO;
    this->keywords["while"] = WHILE;
    this->keywords["for"] = FOR;
    this->keywords["break"] = BREAK;
    this->keywords["continue"] = CONTINUE;
    this->keywords["def"] = DEF;
    this->keywords["return"] = RETURN;
    this->keywords["use"] = USE;
    this->keywords["import"] = IMPORT;
    this->keywords["as"] = AS;
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

void Lexer::addToken(TType type, Value content) {
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
    addToken(NUMBER, Value(number));
}

void Lexer::tokenizeWord() {
    std::stringstream stream;
    std::string word;

    stream << peek(-1);

    while (this->position < this->input.size()) {
        if ((isalpha(peek(0)) && peek(0) != '$') || peek(0) == '_') stream << next();
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

    addToken(STRING, Value(stream.str()));
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

char Lexer::getOperator(TType type) {
    return type.c_str()[0];
}

TType Lexer::isKeyWord(std::string keyword) {
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    auto it = keywords.find(keyword);
    if (it != keywords.end()) return it->second;
    else return LEXEM;
}

#include <memory>
#include "Parser.h"
#include "../ast/expressions/UnaryExpression.h"
#include "../ast/statements/AssigmentStatement.h"
#include "../ast/expressions/VariableExpression.h"
#include "../ast/statements/PrintStatement.h"
#include "../ast/expressions/ConditionalExpression.h"
#include "../ast/statements/IfStatement.h"
#include "../ast/expressions/ValueExpression.h"
#include "../ast/expressions/ExclamationExpression.h"
#include "../ast/statements/PrintlnStatement.h"
#include "../ast/statements/WhileStatement.h"
#include "../ast/statements/BlockStatement.h"
#include "../lib/Variables.h"
#include "../ast/statements/ForStatement.h"
#include "../ast/statements/BreakStatement.h"
#include "../lib/Functions.h"
#include "../ast/expressions/FunctionExpression.h"
#include "../ast/expressions/ArrayExpression.h"
#include "../ast/statements/FunctionStatement.h"
#include "../ast/statements/FunctionDefineStatement.h"
#include "../ast/statements/ReturnStatement.h"
#include "../ast/statements/UseStatement.h"
#include "../ast/statements/ImportStatement.h"
#include "../ast/statements/DoWhileStatement.h"

std::vector<Statement *> Parser::parse() {
    this->size = tokens.size();

    while (!match(TokenType::FILEEND)) {
        if (look(0, TokenType::FILEEND))
            break;

        statements.push_back(statement());
    }

    return statements;
}

Token Parser::peek(int pos) {
    int fullPosition = this->position + pos;

    if (fullPosition >= size)
        return Token(TokenType::FILEEND, Value());

    return tokens[fullPosition];
}

bool Parser::match(TokenType type) {
    if (peek(0).getType() != type)
        return false;

    this->position++;
    return true;
}

Statement * Parser::statement() {
    if (match(TokenType::USE))
        return new UseStatement(expression());

    if (match(TokenType::PRINT))
        return new PrintStatement(expression());

    if (match(TokenType::PRINTLN))
        return new PrintlnStatement(expression());

    if (match(TokenType::BREAK))
        return new BreakStatement();

    if (match(TokenType::CONTINUE))
        return new ContinueStatement();

    if (match(TokenType::RETURN))
        return new ReturnStatement(expression());

    if (match(TokenType::IF)) {
        Expression * expr       = nullptr;
        Statement  * statement1 = nullptr;
        Statement  * statement2 = nullptr;

        if (!match(TokenType::L_PAREN))
            throw std::runtime_error("Syntax error: expected (");
        expr = expression();
        if (!match(TokenType::R_PAREN))
            throw std::runtime_error("Syntax error: expected )");

        statement1 = statementOrBlock();
        if (match(TokenType::ELSE)) {
            statement2 = statementOrBlock();
        }

        return new IfStatement(expr, statement1, statement2);
    }

    if (match(TokenType::WHILE)) {
        Expression * expr = nullptr;

        if (!match(TokenType::L_PAREN))
            throw std::runtime_error("Syntax error: expected (");
        expr = expression();
        if (!match(TokenType::R_PAREN))
            throw std::runtime_error("Syntax error: expected )");

        return new WhileStatement(expr, statementOrBlock());
    }

    if (match(TokenType::DO)) {
        Statement * body = statementOrBlock();
        Expression * expr = nullptr;

        match(TokenType::WHILE);
        if (!match(TokenType::L_PAREN))
            throw std::runtime_error("Syntax error: expected (");
        expr = expression();
        if (!match(TokenType::R_PAREN))
            throw std::runtime_error("Syntax error: expected )");

        return new DoWhileStatement(expr, body);
    }

    if (match(TokenType::FOR)) {
        Statement * state1 = nullptr;
        Expression * expr = nullptr;
        Statement * state2 = nullptr;

        if (!match(TokenType::L_PAREN)) throw std::runtime_error("Syntax error: expected (");
        state1 = statement();
        if (!match(TokenType::COMMA)) throw std::runtime_error("Syntax error: expected ,");
        expr = expression();
        if (!match(TokenType::COMMA)) throw std::runtime_error("Syntax error: expected ,");
        state2 = statement();
        if (!match(TokenType::R_PAREN)) throw std::runtime_error("Syntax error: expected )");
        return new ForStatement(state1, expr, state2, statementOrBlock());
    }

    if (match(TokenType::DEF)) {
        std::string name = peek(0).getContent().getStringValue();

        if (Functions::exists(name))
            throw std::runtime_error(std::string("Function: ") += name += " exists!");

        match(TokenType::WORD);
        match(TokenType::L_PAREN);

        std::vector<std::string> args;
        while (!match(TokenType::R_PAREN)) {
            match(TokenType::WORD);
            args.push_back(peek(-1).getContent().getStringValue());
            match(TokenType::COMMA);
        }

        return new FunctionDefineStatement(name, args, statementOrBlock());
    }

    if (look(0, TokenType::WORD) && look(1, TokenType::L_PAREN)) {
        return new FunctionStatement(function());
    }

    if (match(TokenType::IMPORT)) {
        Expression * pathExpression = expression();
        Expression * nameExpression = nullptr;

        if (match(TokenType::AS)) {
            nameExpression = expression();
        }

        return new ImportStatement(pathExpression, nameExpression);
    }

    return assignmentStatement();
}

Statement * Parser::assignmentStatement() {
    Statement * state = nullptr;
    Token token = peek(0);

    if (match(TokenType::VAR)) {
        token = peek(0);
        std::string variableName = token.getContent().getStringValue();
        match(TokenType::WORD);
        match(TokenType::EQ);
        state = new AssigmentStatement(variableName, expression());
    }

    if (match(TokenType::WORD) && peek(0).getType() == TokenType::EQ) {
        token = peek(-1);
        match(TokenType::EQ);
        std::string variableName = token.getContent().getStringValue();
        state = new AssigmentStatement(variableName, expression());
    }

    if (state == nullptr)
        throw std::runtime_error("Unknown statement");

    return state;
}

Expression * Parser::expression() {
    return logicalOr();
}

Expression * Parser::logicalOr() {
    Expression * expr = logicalAnd();

    if (match(TokenType::BAR) && match(TokenType::BAR)) {
        return new ConditionalExpression('4', expr, logicalAnd());
    }

    return expr;
}

Expression * Parser::logicalAnd() {
    Expression * expr = conditional();

    if (match(TokenType::AMP) && match(TokenType::AMP)) {
        return new ConditionalExpression('5', expr, conditional());
    }

    return expr;
}

Expression * Parser::conditional() {
    Expression * expr = additive();

    while (this->position < this->size) {
        // ==
        if (look(0, TokenType::EQ) && match(TokenType::EQ)) {
            match(TokenType::EQ);
            expr = new ConditionalExpression('=', expr, additive());
            continue;
        }

        // !=
        if (look(0, TokenType::EXCLAMATION) && look(1, TokenType::EQ)) {
            match(TokenType::EXCLAMATION);
            match(TokenType::EQ);
            expr = new ConditionalExpression('!', expr, additive());
            continue;
        }

        // <=
        if (look(0, TokenType::LT) && look(1, TokenType::EQ)) {
            match(TokenType::LT);
            match(TokenType::EQ);
            expr = new ConditionalExpression('3', expr, additive());
            continue;
        }

        // >=
        if (look(0, TokenType::GT) && look(1, TokenType::EQ)) {
            match(TokenType::GT);
            match(TokenType::EQ);
            expr = new ConditionalExpression('2', expr, additive());
            continue;
        }

        if (match(TokenType::LT)) {
            expr = new ConditionalExpression('<', expr, additive());
            continue;
        }

        if (match(TokenType::GT)) {
            expr = new ConditionalExpression('>', expr, additive());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::additive() {
    Expression * expr = multiplicative();

    while (true) {
        if (match(TokenType::PLUS)) {
            expr = new BinaryExpression('+', expr, multiplicative());
            continue;
        }

        if (match(TokenType::MINUS)) {
            expr = new BinaryExpression('-', expr, multiplicative());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::multiplicative() {
    Expression * expr = unary();

    while (this->position < this->size) {
        if (match(TokenType::STAR)) {
            expr = new BinaryExpression('*', expr, unary());
            continue;
        }

        if (match(TokenType::SLASH)) {
            expr = new BinaryExpression('/', expr, unary());
            continue;
        }

        if (match(TokenType::PERCENT)) {
            expr = new BinaryExpression('%', expr, unary());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::unary() {
    if (match(TokenType::MINUS)) {
        return new UnaryExpression('-', exclamation());
    }

    match(TokenType::PLUS);
    return exclamation();
}

Expression * Parser::exclamation() {
    if (match(TokenType::EXCLAMATION)) {
        return new ExclamationExpression(primary());
    }

    return primary();
}

Expression * Parser::primary() {
    Token token = peek(0);
    Expression * expr = nullptr;

    if (match(TokenType::NUMBER)) {
        expr = new ValueExpression(Value(token.getContent().getNumberValue()));
    } else if (match(TokenType::STRING)) {
        expr = new ValueExpression(Value(token.getContent().getStringValue()));
    } else if (match(TokenType::L_PAREN)) {
        expr = expression();
        match(TokenType::R_PAREN);
        return expr;
    } else if (look(0, TokenType::WORD) && look(1, TokenType::L_PAREN)) {
        expr = function();
    } else if (match(TokenType::WORD)) {
        expr = new VariableExpression(token.getContent().getStringValue());
    } else if (match(TokenType::TRUE)) {
        expr = new ValueExpression(Value(true));
    } else if (match(TokenType::FALSE)) {
        expr = new ValueExpression(Value(false));
    } else if (match(TokenType::NIL)) {
        expr = new ValueExpression(Value());
    } else if (match(TokenType::L_SQUARE_BRACKET)) { // array
        auto * expression1 = new ArrayExpression();
        while (!match(TokenType::R_SQUARE_BRACKET)) {
            expression1->addExpression(expression());
            match(TokenType::COMMA);
        }

        return expression1;
    }

    if (expr == nullptr) {
        throw std::runtime_error("Unknown operation");
    }

    return expr;
}

Statement * Parser::block() {
    auto * block = new BlockStatement();
    match(TokenType::L_BRACKET);

    while (!match(TokenType::R_BRACKET))
        block->add(statement());

    return block;
}

Statement * Parser::statementOrBlock() {
    if (look(0, TokenType::L_BRACKET)) return block();
    return statement();
}

bool Parser::look(int pos, TokenType type) {
    return peek(pos).getType() == type;
}

FunctionExpression * Parser::function() {
    std::string name = peek(0).getContent().getStringValue();

    match(TokenType::WORD);
    match(TokenType::L_PAREN);
    FunctionExpression * expression1 = new FunctionExpression(name);

    while (!match(TokenType::R_PAREN)) {
        expression1->addArgument(expression());

        if (look(0, TokenType::COMMA)) {
            match(TokenType::COMMA);
        }
    }

    return expression1;
}

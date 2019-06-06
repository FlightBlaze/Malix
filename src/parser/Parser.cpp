#include "Parser.h"
#include "../ast/expressions/ObjectIndexExpression.h"

std::vector<Statement *> Parser::parse() {
    this->size = tokens.size();

    while (!match(FILEEND)) {
        if (look(0, FILEEND))
            break;

        statements.push_back(statement());
    }

    return statements;
}

Token Parser::peek(int pos) {
    int fullPosition = this->position + pos;

    if (fullPosition >= size)
        return Token(FILEEND, Value());

    return tokens[fullPosition];
}

bool Parser::match(TType type) {
    if (peek(0).getType() != type)
        return false;

    this->position++;
    return true;
}

Statement * Parser::statement() {
    if (match(USE))
        return new UseStatement(expression());

    if (match(DEFINE)) {
        std::string name = consume(LEXEM).getContent().getStringValue();

        return new DefineStatement(name, expression());
    }

    if (match(PACKAGE)) {
        std::string name = consume(STRING).getContent().getStringValue();
        return new UserPackageStatement(name, block());
    }

    if (match(PRINT))
        return new PrintStatement(expression());

    if (match(PRINTLN))
        return new PrintlnStatement(expression());

    if (match(BREAK))
        return new BreakStatement();

    if (match(CONTINUE))
        return new ContinueStatement();

    if (match(RETURN))
        return new ReturnStatement(expression());

    if (match(IF)) {
        Expression * expr       = nullptr;
        Statement  * statement1 = nullptr;
        Statement  * statement2 = nullptr;

        consume(L_PAREN);
        expr = expression();
        consume(R_PAREN);

        statement1 = statementOrBlock();
        if (match(ELSE)) {
            statement2 = statementOrBlock();
        }

        return new IfStatement(expr, statement1, statement2);
    }

    if (match(WHILE)) {
        Expression * expr = nullptr;

        consume(L_PAREN);
        expr = expression();
        consume(R_PAREN);

        return new WhileStatement(expr, statementOrBlock());
    }

    if (match(DO)) {
        Statement * body = statementOrBlock();
        Expression * expr = nullptr;

        consume(WHILE);
        consume(L_PAREN);
        expr = expression();
        consume(R_PAREN);

        return new DoWhileStatement(expr, body);
    }

    if (match(FOR)) {
        Statement * state1 = nullptr;
        Expression * expr = nullptr;
        Statement * state2 = nullptr;

        consume(L_PAREN);
        state1 = statement();
        consume(COMMA);
        expr = expression();
        consume(COMMA);
        state2 = statement();
        if (!match(R_PAREN)) throw std::runtime_error("Syntax error: expected )");
        return new ForStatement(state1, expr, state2, statementOrBlock());
    }

    if (match(DEF)) {
        std::string name = consume(LEXEM).getContent().getStringValue();

        if (Functions::exists(name))
            throw std::runtime_error(std::string("Function: ") += name += " exists!");

        consume(L_PAREN);

        std::vector<std::string> args;
        while (!match(R_PAREN)) {
            args.push_back(consume(LEXEM).getContent().getStringValue());
            match(COMMA);
        }

        return new FunctionDefineStatement(name, args, statementOrBlock());
    }

    if (look(0, LEXEM) && look(1, L_PAREN)) {
        return new FunctionStatement(function());
    }

    if (match(IMPORT)) {
        Expression * pathExpression = expression();
        Expression * nameExpression = nullptr;

        if (match(AS)) {
            nameExpression = expression();
        }

        return new ImportStatement(pathExpression, nameExpression);
    }

    if (match(OBJECT)) {
        std::string name = consume(LEXEM).getContent().getStringValue();
        std::map<std::string, Expression *> values;

        consume(L_BRACKET);
        while (!match(R_BRACKET)) {
            std::string key = consume(LEXEM).getContent().getStringValue();
            consume(DOUBLEDOT);
            values[key] = expression();
            match(COMMA);
        }

        return new ObjectDefineStatement(name, values);
    }

    return assignmentStatement();
}

Statement * Parser::assignmentStatement() {
    if (match(VAR)) {
        std::string variableName = consume(LEXEM).getContent().getStringValue();
        consume(EQ);
        return new VariableDefineStatement(variableName, expression());
    }

    if (look(0, LEXEM) && look(1, EQ)) {
        std::string variableName = consume(LEXEM).getContent().getStringValue();
        consume(EQ);
        return new AssigmentStatement(variableName, expression());
    }

    if (look(0, LEXEM) && look(1, L_SQUARE_BRACKET)) {
        std::string variableName = consume(LEXEM).getContent().getStringValue();
        std::vector<Expression *> indices;
        do {
            consume(L_SQUARE_BRACKET);
            indices.push_back(expression());
            consume(R_SQUARE_BRACKET);
        } while (look(0, L_SQUARE_BRACKET));
        consume(EQ);
        return new ArrayAssigmentStatement(variableName, indices, expression());
    }


    throw std::runtime_error("Unknown statement");
}

Expression * Parser::expression() {
    if (look(0, L_BRACKET)) {
        return new BlockExpression(block());
    }

    return logicalOr();
}

Expression * Parser::logicalOr() {
    Expression * expr = logicalAnd();

    if (match(BAR) && match(BAR)) {
        return new ConditionalExpression('4', expr, logicalAnd());
    }

    return expr;
}

Expression * Parser::logicalAnd() {
    Expression * expr = conditional();

    if (match(AMP) && match(AMP)) {
        return new ConditionalExpression('5', expr, conditional());
    }

    return expr;
}

Expression * Parser::conditional() {
    Expression * expr = additive();

    while (this->position < this->size) {
        // ==
        if (look(0, EQ) && match(EQ)) {
            match(EQ);
            expr = new ConditionalExpression('=', expr, additive());
            continue;
        }

        // !=
        if (look(0, EXCLAMATION) && look(1, EQ)) {
            match(EXCLAMATION);
            match(EQ);
            expr = new ConditionalExpression('!', expr, additive());
            continue;
        }

        // <=
        if (look(0, LT) && look(1, EQ)) {
            match(LT);
            match(EQ);
            expr = new ConditionalExpression('3', expr, additive());
            continue;
        }

        // >=
        if (look(0, GT) && look(1, EQ)) {
            match(GT);
            match(EQ);
            expr = new ConditionalExpression('2', expr, additive());
            continue;
        }

        if (match(LT)) {
            expr = new ConditionalExpression('<', expr, additive());
            continue;
        }

        if (match(GT)) {
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
        if (match(PLUS)) {
            expr = new BinaryExpression('+', expr, multiplicative());
            continue;
        }

        if (match(MINUS)) {
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
        if (match(STAR)) {
            expr = new BinaryExpression('*', expr, unary());
            continue;
        }

        if (match(SLASH)) {
            expr = new BinaryExpression('/', expr, unary());
            continue;
        }

        if (match(PERCENT)) {
            expr = new BinaryExpression('%', expr, unary());
            continue;
        }

        break;
    }

    return expr;
}

Expression * Parser::unary() {
    if (match(MINUS)) {
        return new UnaryExpression('-', exclamation());
    }

    match(PLUS);
    return exclamation();
}

Expression * Parser::exclamation() {
    if (match(EXCLAMATION)) {
        return new ExclamationExpression(primary());
    }

    return primary();
}

Expression * Parser::primary() {
    Token token = peek(0);

    if (match(NUMBER)) {
        return new ValueExpression(Value(token.getContent().getNumberValue()));
    }

    if (match(STRING)) {
        return new ValueExpression(Value(token.getContent().getStringValue()));
    }

    if (match(L_PAREN)) {
        Expression * expr = expression();
        match(R_PAREN);
        return expr;
    }

    if (look(0, LEXEM) && look(1, L_PAREN)) {
        return function();
    }

    if (look(0, LEXEM) && look(1, L_SQUARE_BRACKET)) {
        std::string name = consume(LEXEM).getContent().getStringValue();
        std::vector<Expression *> indices;
        do {
            consume(L_SQUARE_BRACKET);
            indices.push_back(expression());
            consume(R_SQUARE_BRACKET);
        } while (look(0, L_SQUARE_BRACKET));
        return new ArrayIndexExpression(name, indices);
    }

    if (look(0, LEXEM) && look(1, MINUS) && look(2, GT)) {
        std::string name = consume(LEXEM).getContent().getStringValue();
        std::vector<std::string> indices;
        do {
            consume(MINUS);
            consume(GT);
            indices.push_back(consume(LEXEM).getContent().getStringValue());
        } while (look(0, MINUS) && look(1, GT));
        return new ObjectIndexExpression(name, indices);
    }

    if (match(LEXEM)) {
        return new VariableExpression(token.getContent().getStringValue());
    }

    if (match(TRUE)) {
        return new ValueExpression(Value(true));
    }

    if (match(FALSE)) {
        return new ValueExpression(Value(false));
    }

    if (match(NIL)) {
        return new ValueExpression(Value());
    }

    if (match(L_SQUARE_BRACKET)) { // array
        auto * expression1 = new ArrayExpression();
        while (!match(R_SQUARE_BRACKET)) {
            expression1->addExpression(expression());
            match(COMMA);
        }

        return expression1;
    }

    if (match(DEF)) { // anonymous function
        consume(L_PAREN);

        std::vector<std::string> args;
        while (!match(R_PAREN)) {
            args.push_back(consume(LEXEM).getContent().getStringValue());
            match(COMMA);
        }

        return new AnonymousFunctionExpression(args, statementOrBlock());
    }

    if (match(OBJECT)) { // anonymous object
        std::map<std::string, Expression *> values;

        consume(L_BRACKET);
        while (!match(R_BRACKET)) {
            std::string key = consume(LEXEM).getContent().getStringValue();
            consume(DOUBLEDOT);
            values[key] = expression();
            match(COMMA);
        }

        return new AnonymousObjectExpression(values);
    }

    throw std::runtime_error("Unknown operation");
}

BlockStatement * Parser::block() {
    auto * block = new BlockStatement();
    match(L_BRACKET);

    while (!match(R_BRACKET))
        block->add(statement());

    return block;
}

Statement * Parser::statementOrBlock() {
    if (look(0, L_BRACKET)) return block();
    return statement();
}

bool Parser::look(int pos, TType type) {
    return peek(pos).getType() == type;
}

FunctionExpression * Parser::function() {
    std::string name = consume(LEXEM).getContent().getStringValue();
    consume(L_PAREN);
    FunctionExpression * expression1 = new FunctionExpression(name);

    while (!match(R_PAREN)) {
        expression1->addArgument(expression());
        match(COMMA);
    }

    return expression1;
}

Token Parser::consume(TType type) {
    if (match(type)) return peek(-1);
    throw std::runtime_error(std::string("Expected ") + type);
}

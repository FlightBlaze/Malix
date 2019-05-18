cmake_minimum_required(VERSION 3.14)
project(myLang)

set(CMAKE_CXX_STANDARD 14)

add_executable(myLang main.cpp parser/Lexer.cpp parser/Lexer.h parser/token/Token.cpp parser/token/Token.h parser/token/TokenType.h ast/expressions/Expression.h utils/Value.cpp utils/Value.h ast/expressions/BinaryExpression.cpp ast/expressions/BinaryExpression.h ast/expressions/NumberExpression.cpp ast/expressions/NumberExpression.h parser/Parser.cpp parser/Parser.h ast/expressions/UnaryExpression.cpp ast/expressions/UnaryExpression.h)
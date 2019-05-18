cmake_minimum_required(VERSION 3.14)
project(myLang)

set(CMAKE_CXX_STANDARD 14)

add_executable(myLang main.cpp parser/Lexer.cpp parser/Lexer.h parser/token/Token.cpp parser/token/Token.h parser/token/TokenType.h ast/expressions/Expression.h utils/Value.cpp utils/Value.h ast/expressions/MatchExpression.cpp ast/expressions/MatchExpression.h ast/expressions/DoubleExpression.cpp ast/expressions/DoubleExpression.h ast/expressions/IntegerExpression.cpp ast/expressions/IntegerExpression.h)
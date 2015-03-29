#include <string>


enum Keywords {
    FUNCTION,
    
    IF,
    ELSE,
    
    WHILE,
    DO,
    FOR
};

enum Operators {
    ASSIGN,
    
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    
    
}


class Token {
  public:

    Token();
}


class Identifier : public Token {
  public:
    string name;
    
    Identifier(string);
}


class Keyword : public Token {
  public:
}


class Whitespace : public Token {
  public:
    unsigned size;
    
    Whitespace(unsigned);
}
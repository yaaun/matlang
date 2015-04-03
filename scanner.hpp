#define SCANNER_HPP

#ifndef STD_STRING
#define STD_STRING
#include <string>
using std::string;
#endif

#ifndef STD_LIST
#define STD_LIST
#include <list>
#endif

#ifndef STD_EXCEPTION
#define STD_EXCEPTION
#include <exception>
using std::exception;
#endif


class InvalidName : public exception {
  private:
    string name;

  public:
    InvalidName(string& s): name(s) {}
    ~InvalidName() throw ();
    const char* what();
};

const char* InvalidName::what() {
    return (string("Invalid name \"") + name + string("\"")).c_str();
}


class Token {
  public:
    Token();
};


class Identifier : public Token {
  public:
    string name;
    
    Identifier(string s);
};


class Keyword : public Token {
  private:
    static string strings[];

  public:
    enum Keywords {
        FUNC,
        
        IF,
        ELSE,
        
        WHILE,
        DO,
        FOR
    };
    
    Keywords word;
    
    Keyword(Keywords kw): word(kw) {}
    
    static Keywords match(string s) throw (InvalidName);
};


class Operator : public Token {
  pr
  public:
    enum Operators {
        ASSIGN,
        
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        
        //  Combined assignment operators.
        A_ADD,
        A_SUB,
        A_MUL,
        A_DIV,
        A_MOD
    };
}


//  This only counts when used to indent.
class Whitespace : public Token {
  public:
    unsigned size;
    
    Whitespace(unsigned s): size(s) {}
};

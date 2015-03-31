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


enum Keywords {
    FUNC,
    
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
    
    //  Combined assignment operators.
    A_ADD,
    A_SUB,
    A_MUL,
    A_DIV,
    A_MOD
};


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
    Keywords word;
    
    Keyword(Keywords kw): word(kw) {}
    
    static Keywords getKeyword(string s) throw (InvalidName);
};

string Keyword::strings[] = {
    string("funkcja"),
    string("je\xC5\x9Bli"),
    string("inaczej"), 
    string("gdy"),
    string("wykonuj"),
    string("dla")
};

Keywords Keyword::getKeyword(string s) throw (InvalidName) {
    Keywords kw;
    
    if (s == Keyword::strings[0]) {
        return FUNC;
    } else if (s == Keyword::strings[1]) {
        return IF;
    } else if (s == Keyword::strings[2]) {
        return ELSE;
    } else if (s == Keyword::strings[3]) {
        return WHILE;
    } else if (s == Keyword::strings[4]) {
        return DO;
    } else if (s == Keyword::strings[5]) {
        return FOR;
    } else {
        throw InvalidName(s);
    }
}


//  This only counts when used to indent.
class Whitespace : public Token {
  public:
    unsigned size;
    
    Whitespace(unsigned s): size(s) {}
};

Keywords toKeyword(string s) {
    
}


list<Token> scan(string s) {
    enum {
        ALPHA,
        NUMERIC,
        OPERATOR,
        WHITESPACE
    } state;
    
    for (unsigned i = 0; i < s.size(); i++) {
        switch (state) {
          default:
            
        }
    }
}
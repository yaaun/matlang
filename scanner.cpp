#ifndef STD_STRING
#define STD_STRING
#include <string>
#endif

#ifndef STD_LIST
#define STD_LIST
#include <list>
#endif

#ifndef STD_EXCEPTION
#define STD_EXCEPTION
#include <exception>
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


class InvalidName : public Exception {
  private:
    string name;

  public:
    InvalidName(string& s) name(s) {};
    const char* what();
}

const char* InvalidName::what() {
    return (string("Invalid name \"") + errStr + string("\"")).c_str();
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
    
    static Keyword getKeyword(string s) throw InvalidName;
};

string Keyword::strings[] = {
    string("funkcja"),
    string("je\xC5\x9Bli"),
    string("inaczej"), 
    string("gdy"),
    string("wykonuj"),
    string("dla")
};

Keyword::getKeyword(string s) throw InvalidName {
    if (s == Keyword::strings[0]) {
        return Keywords.FUNC;
    } else if (s == Keyword::strings[1]) {
        return Keywords.IF;
    } else if (s == Keyword::strings[2]) {
        return Keywords.ELSE;
    } else if (s == Keyword::strings[3]) {
        return Keywords.WHILE;
    } else if (s == Keyword::strings[4]) {
        return Keywords.DO;
    } else if (s == Keyword::strings[5]) {
        return Keywords.FOR;
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
    for (unsigned i = 0; i < s.size(); i++) {
        
    }
}
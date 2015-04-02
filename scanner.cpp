#ifndef STD_STRING
#define STD_STRING
#include <string>
using std::string;
#endif

#ifndef STD_LIST
#define STD_LIST
#include <list>
using std::list;
#endif

#ifndef STD_EXCEPTION
#define STD_EXCEPTION
#include <exception>
using std::exception;
#endif


#ifndef STD_CCTYPE
#define STD_CCTYPE
#include <cctype>
#endif



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

string Keyword::strings[] = {
    string("funkcja"),
    string("je\xC5\x9Bli"),
    string("inaczej"), 
    string("gdy"),
    string("wykonuj"),
    string("dla")
};

Keyword::Keywords Keyword::match(string s) throw (InvalidName) {
    Keyword::Keywords kw;
    
    if (s == Keyword::strings[0]) {
        return Keyword::FUNC;
    } else if (s == Keyword::strings[1]) {
        return Keyword::IF;
    } else if (s == Keyword::strings[2]) {
        return Keyword::ELSE;
    } else if (s == Keyword::strings[3]) {
        return Keyword::WHILE;
    } else if (s == Keyword::strings[4]) {
        return Keyword::DO;
    } else if (s == Keyword::strings[5]) {
        return Keyword::FOR;
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


list<Token> scan(string s) {
    enum {
        ALPHA,
        NUMERIC,
        OPERATOR,
        WHITESPACE
    } state;
    
    for (int i = 0; i < s.size();) {
        char c = s[i];
        
        switch (state) {
          case ALPHA:
          
          break;
          case NUMERIC:
          
          break;
          case OPERATOR:
          
          break;
          case WHITESPACE:
            if (c == '\r' || c == '\n') {
                
            } else if (c == ' ' || c == '\t') {
                
            } else {
                
            }
          break;
          default:
            if (isalpha(c)) {
                state = ALPHA;
            } else if (isdigit(c)) {
                
            } else (c == '\r') {
                
            }
          break;
        }
    }
}
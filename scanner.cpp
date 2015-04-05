#ifndef STD_CCTYPE
#define STD_CCTYPE
#include <cctype>
#endif

#ifndef SCANNER_HPP
#include "scanner.hpp"
#endif


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


std::list<Token> scan(string s) {
    enum {
        NUL,
        ALPHA,
        ALPHA_START,
        NUMERIC,
        NUMERIC_START,
        OPERATOR,
        WHITESPACE
    } state;
    state = NUL;
    
    enum {
        DECIMAL,
        BINARY,
        HEXADECIMAL,
        UNKNOWN
    } numFormat;
    
    std::list<Token> tokens;
    
    int identStart, identLen;
    int numStart, numLen;
    int opStart, opLen;
    int wsCount;
    
    for (int i = 0; i < s.size();) {
        char c = s[i];
        
        switch (state) {
          case ALPHA_START:
            //  Start of an identifier.
            identStart = i;
            identLen = 1;
            i += 1;
            state = ALPHA;
          break;
          case ALPHA:
            if (std::isalnum(c)) {
                //  Continuation of an identifier.
                identLen += 1;
                i += 1;
            } else {
                //  Found a non-whitespace char.
                tokens.push_back(Identifier(s.substr(identStart, identLen)));
                identLen = 0;
                state = NUL;
            }
          break;
          case NUMERIC_START:
            numStart = i;
            numLen = 1;
            i += 1;
            state = NUMERIC;
          break;
          case NUMERIC:
            if (numLen == 0) {
                
            } else {
                
            }
          break;
          case OPERATOR:
            if (std::ispunct(c)) {
                
            }
          break;
          case WHITESPACE:
            if (c == '\r' || c == '\n') {
                wsCount = 0;
                i += 1;
            } else if (c == ' ' || c == '\t') {
                wsCount += 1;
                i += 1;
            } else {
                tokens.push_back(Whitespace(wsCount));
                state = NUL;
            }
          break;
          default:
            if (std::isalpha(c)) {
                state = ALPHA_START;
            } else if (std::isdigit(c)) {
                state = NUMERIC_START;
            } else if (std::ispunct(c)) {
                state = OPERATOR;
            } else if (std::iscontrol(c)) {
                state = WHITESPACE;
            }
          break;
        }
    }
}
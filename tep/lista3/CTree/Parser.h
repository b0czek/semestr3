//
// Created by dariusz on 19.11.23.
//

#ifndef LISTA3_PARSER_H
#define LISTA3_PARSER_H

#include <list>
#include <cmath>
#include <set>
#include "CNode.h"

#define NUMBER_BASE 10
#define MAX_INT_LENGTH 10

#define UNKNOWN_VARIABLE_NAME "unknown"
#define UNKNOWN_VARIABLE_NAME_SIZE \
    (sizeof (UNKNOWN_VARIABLE_NAME) / sizeof (char))

struct Token {
    const char* start;
    int length;
};


extern const char* ParseErrorTypeLabels[];

enum ParseErrorType {
    PARSE_ERR_ARG_COUNT,
    PARSE_ERR_VARIABLE_NAME,
    PARSE_ERR_UNKNOWN_TOKEN,
    PARSE_ERR_UNEXPECTED_TOKEN
};

struct ParseError {
    ParseErrorType type;
    std::string mistake;
    std::string correctedTo;
};

class Parser {
public:
    void parse(const char* data, CNode* output);

    const std::list<ParseError> &getParseErrors() const;
    const std::set<std::string> &getVariables() const;
private:
    void parse(const char** data, CNode* node);

    static void trimSpaces(const char** data);
    static void extractToken(const char **data, Token* output);
    static bool isNumber(Token* token);
    static bool hasLetter(Token *token);

    // copies all characters that are allowed in a variableName into buffer
    // and adds null terminator at the end
    // returns length of copied characters(excluding '\0')
    static int toVariable(Token *token, char* outputBuffer);

    // basically atol with length of string to convert
    static unsigned long toNumber(Token* token);

    static std::string tokenToString(Token* token);

    static inline bool isLetter(const char character) {
        return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
    }
    static inline bool isDigit(const char character) {
        return character >= '0' && character <= '9';
    }

private:

    std::list<ParseError> parseErrors;
    std::set<std::string> variables;
    unsigned int unknownTokenCounter;
};


#endif //LISTA3_PARSER_H

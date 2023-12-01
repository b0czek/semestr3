//
// Created by dariusz on 19.11.23.
//

#ifndef LISTA3_PARSER_H
#define LISTA3_PARSER_H

#include <cmath>
#include <set>
#include <cstdio>
#include "CNode.h"

#define NUMBER_BASE 10
#define MAX_INT_LENGTH 10

#define UNKNOWN_VARIABLE_NAME "unknown"
#define UNKNOWN_VARIABLE_NAME_SIZE \
    (sizeof (UNKNOWN_VARIABLE_NAME) / sizeof (char))

struct Token {
    const char *start;
    int length;
};

extern const char *ParseErrorTypeLabels[];

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

template<typename T>
class ParserParameters {
public:
    virtual bool isOfType(Token *token) = 0;

    virtual T tokenToValue(Token *token) = 0;

    virtual T defaultValue() = 0;

    virtual Operators<T> *getOperators() = 0;

};

class ParserUtilities {
public:
    static void trimSpaces(const char **data);

    static void extractToken(const char **data, Token *output);

    static bool hasLetter(Token *token);

    // copies all characters that are allowed in a variableName into buffer
    // and adds null terminator at the end
    // returns length of copied characters(excluding '\0')
    static int toVariable(Token *token, char *outputBuffer);

    static std::string tokenToString(Token *token);

    static inline bool isLetter(const char character) {
        return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
    }

    static inline bool isDigit(const char character) {
        return character >= '0' && character <= '9';
    }

};

class Parser {
public:
    Parser();

    const std::vector<ParseError> &getParseErrors() const;

    const std::set<std::string> &getVariables() const;

    template<typename T>
    void parse(const char *data, CNode<T> *output, ParserParameters<T> &parameters) {
        unknownTokenCounter = 0;
        parseErrors.clear();
        variables.clear();

        parse(&data, output, parameters);

        // extract redundant tokens and add to errors
        Token token;
        do {
            ParserUtilities::extractToken(&data, &token);
            if (token.length != 0) {
                parseErrors.push_back((struct ParseError) {
                        PARSE_ERR_UNEXPECTED_TOKEN, ParserUtilities::tokenToString(&token), ""
                });
            }
        } while (token.length != 0);

    }


private:
    std::vector<ParseError> parseErrors;
    std::set<std::string> variables;
    unsigned int unknownTokenCounter;


    template<typename T>
    void parse(const char **data, CNode<T> *node, ParserParameters<T> &parameters) {
        Token token;
        ParserUtilities::extractToken(data, &token);

        if (token.length == 0) {
            T value = parameters.defaultValue();
            node->setConstValue(value);
            parseErrors.push_back((struct ParseError) {
                    PARSE_ERR_ARG_COUNT, ParserUtilities::tokenToString(&token), node->toString()
            });
            return;
        }


        // check if token is a symbol of any operator
        Operators<T> *ops = parameters.getOperators();
        int operatorIdx = ops->findOperatorIdx(token.start, token.length);
        if (operatorIdx != -1) {
            const Operator<T> *op = (ops->getOperators() + operatorIdx);

            node->setOperator(op);
            for (int i = 0; i < op->argumentCount; i++) {
                CNode<T> *argument = new CNode<T>();

                parse(data, argument, parameters);
                node->addChild(argument);
            }
            return;
        }
        // check if token is of parsed type
        if (parameters.isOfType(&token)) {
            T value = parameters.tokenToValue(&token);
            node->setConstValue(value);
            return;
        }

        // if it has a letter in it, it's a variable
        if (ParserUtilities::hasLetter(&token)) {
            // allocates new char* possibly bigger than output variable
            char *variableName = new char[token.length + 1];
            int variableLength = ParserUtilities::toVariable(&token, variableName);

            node->setVariable(variableName);
            variables.insert(variableName);

            delete[] variableName;

            if (variableLength != token.length) {
                parseErrors.push_back((struct ParseError) {
                        PARSE_ERR_VARIABLE_NAME, ParserUtilities::tokenToString(&token), node->toString()
                });
            }
            return;
        }

        // if it's not an operator, a variable, nor a parsed type
        // then we have no idea what it is
        // correct it to unknown variable
        char variableName[UNKNOWN_VARIABLE_NAME_SIZE + MAX_INT_LENGTH];
        sprintf(variableName, "%s%u", UNKNOWN_VARIABLE_NAME, unknownTokenCounter);
        unknownTokenCounter++;

        node->setVariable(variableName);

        parseErrors.push_back((struct ParseError) {
                PARSE_ERR_UNKNOWN_TOKEN, ParserUtilities::tokenToString(&token), node->toString()
        });

    }


};


#endif //LISTA3_PARSER_H

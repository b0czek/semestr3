//
// Created by dariusz on 19.11.23.
//

#include <cstring>
#include <cstdio>
#include "Parser.h"

const char *ParseErrorTypeLabels[] = {
        "PARSE_ERR_ARG_COUNT",
        "PARSE_ERR_VARIABLE_NAME",
        "PARSE_ERR_UNKNOWN_TOKEN",
        "PARSE_ERR_UNEXPECTED_TOKEN",
};

Parser::Parser(const Operators *operators) : ops(operators), unknownTokenCounter(0) {

}

Parser::Parser() : ops(&operators), unknownTokenCounter(0) {

}

void Parser::parse(const char *data, CNode *output) {
    unknownTokenCounter = 0;
    parseErrors.clear();
    variables.clear();

    parse(&data, output);

    // extract redundant tokens and add to errors
    Token token;
    do {
        extractToken(&data, &token);
        if (token.length != 0) {
            parseErrors.push_back((struct ParseError) {
                    PARSE_ERR_UNEXPECTED_TOKEN, tokenToString(&token), ""
            });
        }
    } while (token.length != 0);

}

const std::vector<ParseError> &Parser::getParseErrors() const {
    return parseErrors;
}

const std::set<std::string> &Parser::getVariables() const {
    return variables;
}

void Parser::parse(const char **data, CNode *node) {
    Token token;
    extractToken(data, &token);

    if (token.length == 0) {
        node->setData(1);
        parseErrors.push_back((struct ParseError) {
                PARSE_ERR_ARG_COUNT, tokenToString(&token), node->toString()
        });
        return;
    }


    // check if token is a symbol of any operator
    int operatorIdx = findOperatorIdx(ops, token.start, token.length);
    if (operatorIdx != -1) {
        const Operator *op = (ops->operators + operatorIdx);

        node->setData(op);
        for (int i = 0; i < op->argumentCount; i++) {
            CNode *argument = new CNode();

            parse(data, argument);
            node->addChild(argument);
        }
        return;
    }
    // if it has a letter in it, it's a variable
    if (hasLetter(&token)) {
        // allocates new char* possibly bigger than output variable
        char *variableName = new char[token.length + 1];
        int variableLength = toVariable(&token, variableName);

        node->setData(variableName);
        variables.insert(variableName);

        delete[] variableName;

        if (variableLength != token.length) {
            parseErrors.push_back((struct ParseError) {
                    PARSE_ERR_VARIABLE_NAME, tokenToString(&token), node->toString()
            });
        }
        return;
    }

    // check if token is a number
    if (isNumber(&token)) {
        node->setData(toNumber(&token));
        return;
    }

    // if it's not an operator, a variable, nor a number
    // then we have no idea what it is
    // correct it to unknown variable
    char variableName[UNKNOWN_VARIABLE_NAME_SIZE + MAX_INT_LENGTH];
    sprintf(variableName, "%s%u", UNKNOWN_VARIABLE_NAME, unknownTokenCounter);
    unknownTokenCounter++;

    node->setData(variableName);

    parseErrors.push_back((struct ParseError) {
            PARSE_ERR_UNKNOWN_TOKEN, tokenToString(&token), node->toString()
    });


}

void Parser::trimSpaces(const char **data) {
    while (**data == ' ') {
        (*data)++;
    }
}

void Parser::extractToken(const char **data, Token *output) {
    trimSpaces(data);

    output->start = *data;
    output->length = 0;
    while (**data != ' ' && **data != '\0') {
        output->length++;
        (*data)++;
    }

}

bool Parser::isNumber(Token *token) {
    for (int i = 0; i < token->length; i++) {
        const char character = token->start[i];
        if (!isDigit(character)) {
            return false;
        }
    }
    return true;
}

bool Parser::hasLetter(Token *token) {
    for (int i = 0; i < token->length; i++) {
        const char character = token->start[i];
        if (isLetter(character)) {
            return true;
        }
    }
    return false;
}

int Parser::toVariable(Token *token, char *outputBuffer) {
    int position = 0;
    for (int i = 0; i < token->length; i++) {
        const char character = token->start[i];
        if (isLetter(character) || isDigit(character)) {
            outputBuffer[position] = character;
            position++;
        }
    }
    outputBuffer[position] = '\0';
    return position;
}

unsigned long Parser::toNumber(Token *token) {
    unsigned long result = 0;
    for (int i = 0; i < token->length; i++) {
        result *= NUMBER_BASE;
        result += (*(token->start + i) - '0');
    }
    return result;
}

std::string Parser::tokenToString(Token *token) {
    char *buffer = strndup(token->start, token->length);
    std::string result(buffer);
    free(buffer);
    return result;
}


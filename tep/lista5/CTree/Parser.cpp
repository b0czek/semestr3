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

Parser::Parser() : unknownTokenCounter(0) {

}

const std::vector<ParseError> &Parser::getParseErrors() const {
    return parseErrors;
}

const std::set<std::string> &Parser::getVariables() const {
    return variables;
}

void ParserUtilities::trimSpaces(const char **data) {
    while (**data == ' ') {
        (*data)++;
    }
}

void ParserUtilities::extractToken(const char **data, Token *output) {
    trimSpaces(data);

    output->start = *data;
    output->length = 0;
    while (**data != ' ' && **data != '\0') {
        output->length++;
        (*data)++;
    }

}

bool ParserUtilities::hasLetter(Token *token) {
    for (int i = 0; i < token->length; i++) {
        const char character = token->start[i];
        if (ParserUtilities::isLetter(character)) {
            return true;
        }
    }
    return false;
}

int ParserUtilities::toVariable(Token *token, char *outputBuffer) {
    int position = 0;
    for (int i = 0; i < token->length; i++) {
        const char character = token->start[i];
        if (ParserUtilities::isLetter(character) || ParserUtilities::isDigit(character)) {
            outputBuffer[position] = character;
            position++;
        }
    }
    outputBuffer[position] = '\0';
    return position;
}

std::string ParserUtilities::tokenToString(Token *token) {
    return std::string(token->start, 0, token->length);
}


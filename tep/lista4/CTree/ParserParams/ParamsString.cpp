//
// Created by dariusz on 01.12.23.
//

#include "ParamsString.h"

const Operator<std::string> ParamsString::operators[] = {
        {OPERATOR_STR_ADD, OPERATOR_STR_ADD_ARGS, operator_add},
        {OPERATOR_STR_SUB, OPERATOR_STR_SUB_ARGS, operator_sub},
        {OPERATOR_STR_MUL, OPERATOR_STR_MUL_ARGS, operator_mul},
        {OPERATOR_STR_DIV, OPERATOR_STR_DIV_ARGS, operator_div},

};

ParamsString::ParamsString() {
    ops = Operators<std::string>(operators,
                                 sizeof(operators) / sizeof(Operator<std::string>));
}

bool ParamsString::isOfType(Token *token) {
    return *token->start == '\"' && *(token->start + token->length - 1) == '\"';
}

std::string ParamsString::tokenToValue(Token *token) {
    return std::string(token->start, 1, token->length - 2);
}

std::string ParamsString::defaultValue() {
    return std::string();
}

Operators<std::string> *ParamsString::getOperators() {
    return &ops;
}

std::string ParamsString::operator_add(std::string *args) {
    return args[0] + args[1];
}

std::string ParamsString::operator_sub(std::string *args) {
    std::string first = args[0];
    std::string second = args[1];

    int pos = first.rfind(second);
    if(pos == first.npos) {
        return first;
    }
    return first.substr(0, pos) + first.substr(pos + second.length());


}

std::string ParamsString::operator_mul(std::string *args) {
    std::string first = args[0];
    std::string second = args[1];

    if(second.length() == 0) {
        return first;
    }

    int pos = first.find(second[0]);
    while(pos != first.npos) {
        first = first.replace(pos, 1, second);

        pos = first.find(second[0], pos + 1);
    }

    return first;

}

std::string ParamsString::operator_div(std::string *args) {
    std::string first = args[0];
    std::string second = args[1];

    if(second.length() == 0) {
        return first;
    }

    int pos = first.find(second);
    std::string firstLetter(second, 0, 1);
    while(pos != first.npos) {
        first = first.replace(pos, second.length(), firstLetter);

        pos = first.find(second, pos + 1);
    }

    return first;

}



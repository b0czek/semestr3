//
// Created by dariusz on 01.12.23.
//

#ifndef LISTA4_PARAMSSTRING_H
#define LISTA4_PARAMSSTRING_H

#include <string>
#include "../Parser.h"

#define OPERATOR_STR_ADD "+"
#define OPERATOR_STR_SUB "-"
#define OPERATOR_STR_MUL "*"
#define OPERATOR_STR_DIV "/"
#define OPERATOR_STR_ADD_ARGS 2
#define OPERATOR_STR_SUB_ARGS 2
#define OPERATOR_STR_MUL_ARGS 2
#define OPERATOR_STR_DIV_ARGS 2

class ParamsString : public ParserParameters<std::string> {
public:
    ParamsString();

    virtual bool isOfType(Token *token);

    virtual std::string tokenToValue(Token *token);

    virtual std::string defaultValue();

    virtual Operators<std::string> *getOperators();

private:
    static const Operator<std::string> operators[];

    static std::string operator_add(std::string *args);

    static std::string operator_sub(std::string *args);

    static std::string operator_mul(std::string *args);

    static std::string operator_div(std::string *args);

    Operators<std::string> ops;
};


#endif //LISTA4_PARAMSSTRING_H

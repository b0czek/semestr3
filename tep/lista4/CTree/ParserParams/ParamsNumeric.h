//
// Created by dariusz on 01.12.23.
//

#ifndef LISTA3_PARAMSNUMERIC_H
#define LISTA3_PARAMSNUMERIC_H
#include "../Parser.h"

#define OPERATOR_ADD "+"
#define OPERATOR_SUB "-"
#define OPERATOR_MUL "*"
#define OPERATOR_DIV "/"
#define OPERATOR_SIN "sin"
#define OPERATOR_COS "cos"
#define OPERATOR_ADD_ARGS 2
#define OPERATOR_SUB_ARGS 2
#define OPERATOR_MUL_ARGS 2
#define OPERATOR_DIV_ARGS 2
#define OPERATOR_SIN_ARGS 1
#define OPERATOR_COS_ARGS 1




template <typename T>
class ParamsNumeric : public ParserParameters<T> {
public:
    ParamsNumeric() {
        ops = Operators<T>(operators, sizeof(operators) / sizeof(Operator<T>));

    }
    ~ParamsNumeric(){

    }

    virtual bool isOfType(Token *token) {
        int dotCounter = 0;
        for (int i = 0; i < token->length; i++) {
            const char character = token->start[i];
            if (!ParserUtilities::isDigit(character) && character != '.') {
                return false;
            }
            if(character == '.') {
                dotCounter++;
            }
        }
        return dotCounter <= 1;
    }

    virtual T tokenToValue(Token *token) {
        // according to documentation, strtod will stop upon whitespace after a number
        return strtod(token->start, NULL);

    }

    virtual T defaultValue() {
        return 1;
    }

    virtual Operators<T> *getOperators() {
        return &ops;
    }

private:

    static T operator_add(T *args) {
        return args[0] + args[1];
    }

    static T operator_sub(T *args) {
        return args[0] - args[1];
    }

    static T operator_mul(T *args) {
        return args[0] * args[1];
    }

    static T operator_div(T *args) {
        return args[0] / args[1];
    }

    static T operator_sin(T *args) {
        return std::sin(args[0]);
    }

    static T operator_cos(T *args) {
        return std::cos(args[0]);
    }

    static const Operator<T> operators[];

    Operators<T> ops;

};

template < typename T >
const Operator<T> ParamsNumeric<T>::operators[] = {
    {OPERATOR_ADD, OPERATOR_ADD_ARGS, operator_add},
    {OPERATOR_SUB, OPERATOR_SUB_ARGS, operator_sub},
    {OPERATOR_MUL, OPERATOR_MUL_ARGS, operator_mul},
    {OPERATOR_DIV, OPERATOR_DIV_ARGS, operator_div},
    {OPERATOR_SIN, OPERATOR_SIN_ARGS, operator_sin},
    {OPERATOR_COS, OPERATOR_COS_ARGS, operator_cos},
};

#endif //LISTA3_PARAMSNUMERIC_H

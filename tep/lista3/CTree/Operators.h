//
// Created by dariusz on 18.11.23.
//

#ifndef LISTA3_OPERATORS_H
#define LISTA3_OPERATORS_H

#include <vector>
#include <cmath>

inline double operator_add(double *args) {
    return args[0] + args[1];
}

inline double operator_sub(double *args) {
    return args[0] - args[1];
}

inline double operator_mul(double *args) {
    return args[0] * args[1];
}

inline double operator_div(double *args) {
    return args[0] / args[1];
}

inline double operator_sin(double *args) {
    return std::sin(args[0]);
}

inline double operator_cos(double *args) {
    return std::cos(args[0]);
}

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

struct Operator {
    const char *const symbol;
    const int argumentCount;

    double (*execute)(double *args);
};

const Operator operators[] = {
        {OPERATOR_ADD, OPERATOR_ADD_ARGS, operator_add},
        {OPERATOR_SUB, OPERATOR_SUB_ARGS, operator_sub},
        {OPERATOR_MUL, OPERATOR_MUL_ARGS, operator_mul},
        {OPERATOR_DIV, OPERATOR_DIV_ARGS, operator_div},
        {OPERATOR_SIN, OPERATOR_SIN_ARGS, operator_sin},
        {OPERATOR_COS, OPERATOR_COS_ARGS, operator_cos},
};

int findOperatorIdx(const char *symbol, int symbolLength);

#endif //LISTA3_OPERATORS_H

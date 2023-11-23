//
// Created by dariusz on 18.11.23.
//

#include "Operators.h"
#include <cstring>

double operator_add(double *args) {
    return args[0] + args[1];
}

double operator_sub(double *args) {
    return args[0] - args[1];
}

double operator_mul(double *args) {
    return args[0] * args[1];
}

double operator_div(double *args) {
    return args[0] / args[1];
}

double operator_sin(double *args) {
    return std::sin(args[0]);
}

double operator_cos(double *args) {
    return std::cos(args[0]);
}


int findOperatorIdx(const Operators* ops, const char *symbol, int symbolLength) {
    for (int i = 0; i < ops->operatorsCount; i++) {
        const char* operatorSymbol = ops->operators[i].symbol;

        if ((strlen(operatorSymbol)) == symbolLength
            && strncmp(symbol, operatorSymbol, symbolLength) == 0) {
            return i;
        }
    }
    return -1;
}

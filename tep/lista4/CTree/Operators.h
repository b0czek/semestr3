//
// Created by dariusz on 18.11.23.
//

#ifndef LISTA3_OPERATORS_H
#define LISTA3_OPERATORS_H

#include <vector>
#include <cmath>
#include <cstring>


template<typename T>
struct Operator {
    const char *const symbol;
    const int argumentCount;

    T (*const execute)(T *args);
};

template<typename T>
class Operators {
public:
    Operators() : operators(NULL), operatorsCount(0) {}

    Operators(const Operator<T> *operators, int operatorsCount) : operators(operators),
                                                                        operatorsCount(operatorsCount) {}

    const Operator<T> *getOperators() const {
        return operators;
    }

    const int getOperatorsCount() const {
        return operatorsCount;
    }

    int findOperatorIdx(const char *symbol, int symbolLength) {
        for (int i = 0; i < operatorsCount; i++) {
            const char *operatorSymbol = operators[i].symbol;

            if ((strlen(operatorSymbol)) == symbolLength
                && strncmp(symbol, operatorSymbol, symbolLength) == 0) {
                return i;
            }
        }
        return -1;
    }

private:
    const Operator<T> *operators;
    int operatorsCount;
};


#endif //LISTA3_OPERATORS_H

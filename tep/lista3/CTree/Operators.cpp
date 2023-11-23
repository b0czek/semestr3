//
// Created by dariusz on 18.11.23.
//

#include "Operators.h"
#include <cstring>

int findOperatorIdx(const char *symbol, int symbolLength) {
    int operatorsCount = sizeof(operators) / sizeof(Operator);
    for (int i = 0; i < operatorsCount; i++) {
        const char* operatorSymbol = operators[i].symbol;

        if ((std::strlen(operatorSymbol)) == symbolLength
            && std::strncmp(symbol, operatorSymbol, symbolLength) == 0) {
            return i;
        }
    }
    return -1;
}

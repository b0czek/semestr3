#include "zad1.h"
#include <iostream>

void v_alloc_table_fill_34(int iSize) {
    if (iSize < 0) {
        return;
    }
    int *table = new int[iSize];

    for (int i = 0; i < iSize; i++) {
        *(table + i) = ZAD1_TABLE_FILLED_VALUE;
    }

    for (int i = 0; i < iSize; i++) {
        std::cout << *(table + i) << " ";
    }


    delete[] table;

}

int main() {
    v_alloc_table_fill_34(10);

    return 0;
}
#include <iostream>
#include "zad23.h"


bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY < 0) {
        return false;
    }
    if (piTable == NULL) {
        return false;
    }
    int **table = new int *[iSizeX];
    for (int i = 0; i < iSizeX; i++) {
        *(table + i) = new int[iSizeY];
    }

    *piTable = table;
    return true;
}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0) {
        return false;
    }
    if (piTable == NULL) {
        return false;
    }
    for (int i = 0; i < iSizeX; i++) {
        delete *(piTable + i);
    }
    delete piTable;
    return true;

}

int main() {
    int **pi_table;
    b_alloc_table_2_dim(&pi_table, ZAD2_ISIZE_X, ZAD2_ISIZE_Y);

    b_dealloc_table_2_dim(pi_table, ZAD2_ISIZE_X, ZAD2_ISIZE_Y);

    return 0;
}
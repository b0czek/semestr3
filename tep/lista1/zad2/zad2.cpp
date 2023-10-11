#include <iostream>

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if(iSizeX <= 0 || iSizeY < 0) {
        return false;
    }
    int** table = new int*[iSizeX];
    for (int i = 0; i < iSizeX; i++) {
        *(table + i) = new int[iSizeY];
    }

    *piTable = table;
    return true;
}

int main() {
    int** piTable;
    b_alloc_table_2_dim(&piTable, 10,10);
    return 0;
}
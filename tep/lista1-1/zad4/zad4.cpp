//
// Created by dariusz on 10/12/23.
//


#include <iostream>
#include "CTable.h"

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}

void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

int main() {
    CTable *ctable = new CTable;
    ctable->vSetName("dynamic");
    delete ctable;


    CTable ct("static", 11);

    CTable ctt(ct);

    std::cout << "przed v_mod_tab (cTab): " << ctt.iGetSize() << "\n";
    v_mod_tab(ctt, 22);
    std::cout << "po v_mod_tab (cTab): " << ctt.iGetSize() << "\n";

    std::cout << "przed v_mod_tab (pcTab): " << ctt.iGetSize() << "\n";
    v_mod_tab(&ctt, 98);
    std::cout << "po v_mod_tab (pcTab): " << ctt.iGetSize() << "\n";


    CTable *ctables = new CTable[10];
    delete[] ctables;

}
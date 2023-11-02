//
// Created by dariusz on 10/12/23.
//


#include <iostream>
#include <vector>
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

    // ciekawostka ładna ładna bardzo ciekawa
    std::vector<CTable> v_test;
    for  (int ii = 0; ii < 500; ii++)
        v_test.push_back(ct);

    CTable ctt(ct);

    CTable *ctt_clone = ctt.pcClone();
    delete ctt_clone;

    std::cout << "before v_mod_tab (cTab): " << ctt.iGetSize() << "\n";
    v_mod_tab(ctt, 22);
    std::cout << "after v_mod_tab (cTab): " << ctt.iGetSize() << "\n";

    std::cout << "before v_mod_tab (pcTab): " << ctt.iGetSize() << "\n";
    v_mod_tab(&ctt, 98);
    std::cout << "after v_mod_tab (pcTab): " << ctt.iGetSize() << "\n";


    CTable *ctables = new CTable[10];
    delete[] ctables;

    // modyfikacja

    CTable *copy0;
    CTable *copy1;
    ctt.vDoubleCopy(&copy0, &copy1);
    copy1->bSetNewSize(21);

    std::cout << "copy0 length: " << copy0->iGetSize() << "\n";
    std::cout << "copy1 length: " << copy1->iGetSize() << "\n";
    delete copy0;
    delete copy1;

}
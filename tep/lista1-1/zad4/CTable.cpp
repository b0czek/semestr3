//
// Created by dariusz on 10/11/23.
//

#include <iostream>
#include "CTable.h"


CTable::CTable() {
    s_name = CTABLE_DEFAULT_NAME;

    table = new int[CTABLE_DEFAULT_LENGTH];
    table_len = CTABLE_DEFAULT_LENGTH;

    vSendMessage("bezp");
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;

    table = new int[iTableLen];
    table_len = iTableLen;

    vSendMessage("parametr");
}

CTable::CTable(CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";

    vSendMessage("kopiuj");

    table = new int[pcOther.table_len];
    table_len = pcOther.table_len;

    vCopyTableFrom(pcOther.table, table_len);
}

CTable::~CTable() {
    vSendMessage("usuwam");

    delete table;
    table = NULL;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen < 0) {
        return false;
    }

    int *new_table = new int[iTableLen];
    std::copy(table, table + std::min(iTableLen, table_len), new_table);

    delete table;
    table = new_table;
    table_len = iTableLen;

    return true;
}

int CTable::iGetSize() {
    return table_len;
}


CTable *CTable::pcClone() {
    CTable *c_table = new CTable(s_name, table_len);
    c_table->vCopyTableFrom(table, table_len);
    return c_table;
}

void CTable::vCopyTableFrom(int *piTable, int iTableLen) {
    std::copy(piTable, piTable + iTableLen, table);

}

void CTable::vSendMessage(const char *sTitle) {
    std::cout << sTitle << ": '" << s_name << "'\n";
}


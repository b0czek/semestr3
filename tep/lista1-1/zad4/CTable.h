//
// Created by dariusz on 10/11/23.
//

#ifndef LISTA1_1_CTABLE_H
#define LISTA1_1_CTABLE_H

#include <string>

#define CTABLE_DEFAULT_NAME "table"
#define CTABLE_DEFAULT_LENGTH 5

class CTable {
public:
    CTable();

    CTable(std::string sName, int iTableLen);

    CTable(CTable &pcOther);

    ~CTable();

    void vSetName(std::string sName);

    bool bSetNewSize(int iTableLen);

    int iGetSize();

    CTable *pcClone();

private:
    void vCopyTableFrom(int *piTable, int iTableLen);

    void vSendMessage(const char *sTitle);

    std::string s_name;

    int *table;
    int table_len;

};


#endif //LISTA1_1_CTABLE_H

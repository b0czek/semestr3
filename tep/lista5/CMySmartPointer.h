//
// Created by dariusz on 20.12.23.
//

#ifndef LISTA4_CMYSMARTPOINTER_H
#define LISTA4_CMYSMARTPOINTER_H

class CRefCounter
{
public:
    CRefCounter() { i_count = 0; }
    int iAdd() { return(++i_count); }
    int iDec() { return(--i_count); };
    int iGet() { return(i_count); }
private:
    int i_count;
};//class CRefCounter


template <typename  T>
class CMySmartPointer
{
public:
    CMySmartPointer(T *pcPointer)
    {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }//CMySmartPointer(CSellData *pcPointer)
    CMySmartPointer(const CMySmartPointer &pcOther)
    {
        copyPointer(pcOther);
    }//CMySmartPointer(const CMySmartPointer &pcOther)
    ~CMySmartPointer()
    {
        if (pc_counter->iDec() == 0)
        {
            delete pc_pointer;
            delete pc_counter;
        }//if (pc_counter->iDec())
    }//~CMySmartPointer()
    T& operator*() { return(*pc_pointer); }
    T* operator->() { return(pc_pointer); }
    T& operator=(const CMySmartPointer& other) {
        if (pc_counter->iDec() == 0)
        {
            delete pc_pointer;
            delete pc_counter;
        }
        copyPointer(other);

        return *this;
    }
private:
    CRefCounter *pc_counter;
    T *pc_pointer;

    void copyPointer(const CMySmartPointer& other) {
        pc_pointer = other.pc_pointer;
        pc_counter = other.pc_counter;
        pc_counter->iAdd();
    };


};//class CMySmartPointer


#endif //LISTA4_CMYSMARTPOINTER_H

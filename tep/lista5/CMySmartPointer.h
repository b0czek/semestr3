//
// Created by dariusz on 20.12.23.
//

#ifndef LISTA4_CMYSMARTPOINTER_H
#define LISTA4_CMYSMARTPOINTER_H

#include <vector>

class CRefCounter
{
public:
    CRefCounter() {
    }
    int add(void* ptr) {
#if DEBUG
        std::cout << "added pointer "<< (ptr) << " to the counter \n";
#endif

        pointers.push_back(ptr);
        return(pointers.size());
    }
    int dec(void* ptr) {
        for(int i = 0 ; i < pointers.size(); i++) {
            if(pointers[i] == ptr) {
#if DEBUG
                std::cout << "deleted pointer "<< (ptr) << " from the counter \n";
#endif

                pointers.erase(pointers.begin()+ i);
                return pointers.size();
            }
        }
        return(pointers.size());
    };
    int get() {
        return(pointers.size());
    }
private:
    std::vector<void*> pointers;
};

template <typename  T>
class CMySmartPointer
{
public:
    CMySmartPointer(T *ptr)
    {
        pointer = ptr;
        counter = new CRefCounter();
        counter->add(this);
    }

    CMySmartPointer(const CMySmartPointer &other)
    {
        copyPointer(other);
    }

    ~CMySmartPointer()
    {
        deletePointer();
    }

    T& operator*() { return(*pointer); }

    T* operator->() { return(pointer); }

    T& operator=(const CMySmartPointer& other) {
        deletePointer();
        copyPointer(other);

        return *this;
    }

    CMySmartPointer<T> cDuplicate() {
        return CMySmartPointer<T>(*this);
    }

private:
    CRefCounter*counter;
    T *pointer;

    void copyPointer(const CMySmartPointer& other) {
        pointer = other.pointer;
        counter = other.counter;
        counter->add(this);
    };

    void deletePointer() {
        if (counter->dec(this) == 0)
        {
            delete pointer;
            delete counter;
        }
    }


};//class CMySmartPointer


#endif //LISTA4_CMYSMARTPOINTER_H

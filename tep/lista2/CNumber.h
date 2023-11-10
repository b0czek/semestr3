//
// Created by dariusz on 07.11.23.
//

#ifndef LISTA2_CNUMBER_H
#define LISTA2_CNUMBER_H

#define NUMBER_INTEGER_LENGTH 32
#define NUMBER_DEFAULT_LENGTH 3
#define NUMBER_NEGATIVE_SIGN -1
#define NUMBER_POSITIVE_SIGN 1
#define NUMBER_BASE 10

const char DIGITS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a','b','c','d','e','f'};

class CNumber {
public:
    CNumber();

    CNumber(const int value);

    CNumber(const CNumber &other);

    ~CNumber();

    void operator=(const int value);

    void operator=(const CNumber &newValue);

    std::string toString();

    CNumber operator+(int term);

    CNumber operator-(int term);

    CNumber operator*(int term);

    CNumber operator/(int term);

    CNumber operator+(CNumber &term);

    CNumber operator-(CNumber &term);

    CNumber operator*(CNumber &term);

    CNumber operator/(CNumber &term);

    void setSign(int newSign);

    int compareAbs(CNumber& other);


private:
    int *digits;
    int size;
    int length;
    int sign;

    void fromInteger(int value);

    void freeArray();

    void allocTable(int newLength);

    void reallocTable(int newLength);

    void growTable(int newSize);

    void trimTable();

    CNumber addNumber(CNumber *other, int operation);

    CNumber prefix(int prefixLength);

    void shiftLeft(int shiftCount);

    int getTwoDigitsFromPosition(int position);


}; //class CNumber


#endif //LISTA2_CNUMBER_H

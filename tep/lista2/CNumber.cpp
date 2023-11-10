//
// Created by dariusz on 07.11.23.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include "CNumber.h"

CNumber::CNumber() {
    size = NUMBER_DEFAULT_LENGTH;
    length = NUMBER_DEFAULT_LENGTH;
    digits = new int[length];
    sign = NUMBER_POSITIVE_SIGN;
}

CNumber::CNumber(const int value) {
    fromInteger(value);

}

CNumber::CNumber(const CNumber &other) {
    sign = other.sign;
    length = other.length;
    size = length;
    digits = new int[length];
    std::copy(other.digits, other.digits + length, digits);
}

CNumber::~CNumber() {
    freeArray();
}



void CNumber::operator=(const int value) {
    freeArray();
    fromInteger(value);

}

void CNumber::operator=(const CNumber &newValue) {
    if (this == &newValue) {
        return;
    }
    freeArray();

    sign = newValue.sign;
    length = newValue.length;
    size = length;
    digits = new int[length];
    std::copy(newValue.digits, newValue.digits + length, digits);
}


std::string CNumber::toString() {
    std::string result = sign == NUMBER_POSITIVE_SIGN ? "" : "-";
    for (int i = length - 1; i >= 0; i--) {
        result += DIGITS[digits[i]];
    }
    return result;
}

CNumber CNumber::operator+(int term) {
    CNumber addend(term);
    return (*this) * addend;
}

CNumber CNumber::operator-(int term) {
    CNumber subtrahend(term);
    return (*this) * subtrahend;
}

CNumber CNumber::operator*(int term) {
    CNumber multiplier(term);
    return (*this) * multiplier;
}

CNumber CNumber::operator/(int term) {
    CNumber divisor(term);
    return (*this) * divisor;
}

CNumber CNumber::operator+(CNumber &term) {
    return addNumber(&term, NUMBER_POSITIVE_SIGN);
}

CNumber CNumber::operator-(CNumber &term) {
    return addNumber(&term, NUMBER_NEGATIVE_SIGN);
}

CNumber CNumber::operator*(CNumber &term) {

    CNumber result;

    int productLength = this->length + term.length;
    result.allocTable(productLength);


    result.setSign(this->sign * term.sign);

    int *arr = result.digits;

    for (int i = 0; i < term.length; i++) {
        for (int j = 0; j < this->length; j++) {
            arr[i + j] += term.digits[i] * this->digits[j];
        }
    }

    for (int i = 0; i < productLength - 1; i++) {
        arr[i + 1] += arr[i] / NUMBER_BASE;
        arr[i] %= NUMBER_BASE;
    }
    result.trimTable();

    if(result.length == 1 && result.digits[0] == 0) {
        result.setSign(NUMBER_POSITIVE_SIGN);
    }

    return result;
}


CNumber CNumber::operator/(CNumber &term) {
    CNumber zeroNum(0);

    if (zeroNum.compareAbs(term) == 0) {
        // what to do????
        // throw???
        return zeroNum;
    }

    if (compareAbs(term) < 0) {
        return zeroNum;
    }

    CNumber dividend = *this;
    dividend.setSign(NUMBER_POSITIVE_SIGN);

    CNumber divisor = term;
    divisor.setSign(NUMBER_POSITIVE_SIGN);

    // most significant digit of divisor
    int msdDivisor = divisor.digits[divisor.length - 1];

    int scalingFactor = 1;
    if (divisor.length > 1 && msdDivisor < (NUMBER_BASE / 2)) {
        scalingFactor = NUMBER_BASE / (msdDivisor + 1);
        dividend = dividend * scalingFactor;
        divisor = divisor * scalingFactor;
        msdDivisor = divisor.digits[divisor.length - 1];
    }

    int quotientLength = dividend.length - divisor.length + 1;

    CNumber result;
    result.allocTable(quotientLength);
    result.setSign(this->sign * term.sign);

    int i = 0;
    CNumber current;
    while (i < dividend.length) {
        if (i == 0) {
            i = divisor.length;
            current = dividend.prefix(i);
//            current.growTable(quotientLength);
        } else {
            i++;
            current.shiftLeft(1);
            current.digits[0] = dividend.digits[dividend.length - i];
        }

        int yz = current.getTwoDigitsFromPosition(divisor.length);
        // initial guess for probable quotient
        int d = yz / msdDivisor;


        // correct it
        if (d >= NUMBER_BASE) {
            d = NUMBER_BASE - 1;
//            d = 0;
        }
        CNumber temp(d);
        temp = divisor * temp;

        while (d > 0 && current.compareAbs(temp) < 0) {
            d--;
            temp = temp - divisor;
        }

        current = current - temp;

        result.digits[result.length - 1 - i + divisor.length] = d;


    }

    result.trimTable();

//    for handling remainder
//    if(scalingFactor > 1) {
//        CNumber temp(scalingFactor);
//        result = result / temp;
//    }

    return result;


}

void CNumber::setSign(int newSign) {
    sign = newSign;
}

// < 0 - other is greater
// > 0 - this is greater
// = 0 - equal
int CNumber::compareAbs(CNumber &other) {
    if (this->length != other.length) {
        CNumber *longer = this->length > other.length ? this : &other;
        CNumber *shorter = longer == this ? &other : this;

        for (int i = longer->length - 1; i >= shorter->length; i--) {
            if (longer->digits[i] != 0) {
                return longer == this ? 1 : -1;
            }
        }
    }

    for (int i = this->length - 1; i >= 0; i--) {
        int comparison = this->digits[i] - other.digits[i];
        if (comparison != 0) {
            return comparison;
        }
    }

    return 0;

}

void CNumber::fromInteger(int value) {
    sign = value >= 0 ? NUMBER_POSITIVE_SIGN : NUMBER_NEGATIVE_SIGN;
    value = std::abs(value);

    int digitsBuffer[NUMBER_INTEGER_LENGTH];
    int i = 0;
    do {
        digitsBuffer[i] = value % NUMBER_BASE;
        value /= NUMBER_BASE;
        i++;
    } while (value != 0);

    digits = new int[i];
    size = i;
    length = i;

    for (int j = 0; j < i; j++) {
        digits[j] = digitsBuffer[j];

    }

}

void CNumber::freeArray() {
    delete digits;
    digits = NULL;

}

// drops everything in current table and allocates new, zeroed out array
void CNumber::allocTable(int newLength) {
    freeArray();
    length = newLength;
    size = length;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = 0;
    }
}

// resizes table by trimming/utilizing over-allocated space
// or copying table to bigger one
void CNumber::reallocTable(int newLength) {
    // make sure table is big enough
    growTable(newLength);

    for (int i = length; i < newLength; i++) {
        digits[i] = 0;
    }
    length = newLength;
}

// resize table without changing its length
void CNumber::growTable(int newSize) {
    if (newSize <= size) {
        return;
    }
    int *newTable = new int[newSize];
    std::copy(digits, digits + length, newTable);

    freeArray();
    digits = newTable;
    size = newSize;
}

void CNumber::trimTable() {
    int newLength = length;
    while (newLength > 1 && digits[newLength - 1] == 0) {
        newLength--;
    }
    reallocTable(newLength);
}


CNumber CNumber::addNumber(CNumber *other, int operation) {
    int performedOperation = this->sign * other->sign * operation;

    CNumber *bigger = compareAbs(*other) >= 0 ? this : other;
    CNumber *smaller = bigger == this ? other : this;

    int maxOutputLength = std::max(bigger->length, smaller->length) + 1;

    CNumber result;
    result.allocTable(maxOutputLength);


    int carry = 0;
    int i = 0;

    while (carry != 0 || i < bigger->length || i < smaller->length) {
        int value1 = i >= bigger->length ? 0 : bigger->digits[i];
        int value2 = i >= smaller->length ? 0 : smaller->digits[i];

        int value = value1 + (value2 * performedOperation) + carry;

        carry = 0;

        if (value >= NUMBER_BASE) {
            carry = value / NUMBER_BASE;
            value %= NUMBER_BASE;
        }
        if (value < 0) {
            carry = -1;
            value = NUMBER_BASE + value;
        }

        result.digits[i] = value;
        i++;
    }

    result.trimTable();

    int rightSign = operation * other->sign;
    int newSign = bigger == this ? this->sign : rightSign;
    result.setSign(newSign);

    if(result.length == 1 && result.digits[0] == 0) {
        result.setSign(NUMBER_POSITIVE_SIGN);
    }

    return result;

}


void CNumber::shiftLeft(int shiftCount) {
    reallocTable(length + shiftCount);

    for (int i = length - 1; i >= shiftCount; i--) {
        digits[i] = digits[i - shiftCount];
    }

    for (int i = 0; i < shiftCount; i++) {
        digits[i] = 0;
    }

}

CNumber CNumber::prefix(int prefixLength) {
    CNumber result;
    result.allocTable(prefixLength);
    for (int i = 0; i < prefixLength; i++) {
        result.digits[prefixLength - i - 1] = this->digits[this->length - i - 1];
    }
    return result;
}

int CNumber::getTwoDigitsFromPosition(int position) {
    int y = position >= length ? 0 : digits[position];
    int z = (position - 1) >= length ? 0 : digits[position - 1];

    return (y * NUMBER_BASE) + z;

}




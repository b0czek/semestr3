#include <iostream>
#include <sstream>
#include "CNumber.h"

std::string intToString(int number) {
    std::ostringstream s;
    s << number;
    return s.str();
}

#define CHECK_OPERATION(operation) \
    result = c_num_0 operation c_num_1; \
    intRes = intToString(i operation j);                \
    if(result.toString() != intRes) { \
        std::cout << "error at i: " << i << " j: " << j << " expected: " << intRes << " actual: " << result.toString() <<"\n"; \
    }

int main() {
    CNumber c_num_0, c_num_1;
    CNumber result;
    std::string intRes;
//
//    for(int i = -1000; i < 1000; i++) {
//        for(int j = -1000; j < 1000; j++) {
//            c_num_0 = i;
//            c_num_1 = j;
//
//            CHECK_OPERATION(+);
//            CHECK_OPERATION(-);
//            CHECK_OPERATION(*);
//            if(j != 0) {
//                CHECK_OPERATION(/);
//            }
//
//        }
//    }

//    c_num_0 = 213700000;
//    c_num_0 = c_num_0 * c_num_0;
//    std::cout << "MULTIPLICATION: " << (c_num_0).toString() << "\n";
//    c_num_1 = 4212;
//    c_num_1 = c_num_1*c_num_1;


//    c_num_0 = 9123123;
//    c_num_1 = 1;
//
//    result = c_num_0 / c_num_1;
//    std::string str = result.toString();
//    std::cout << "division: " << result.toString() << "\n";
//

    int array1[] = {1, 2, 3};
    int array2[] = {3, 4, 5, 6, 7, 8};

    c_num_0 = CNumber(array1, sizeof(array1) / sizeof(int));
    c_num_1 = CNumber(array2, sizeof(array2) / sizeof(int));


    std::cout << "cnum0 + cnum1: " << (c_num_0 + c_num_1).toString() << "\n";
    std::cout << "cnum1 - cnum0: " << (c_num_1 - c_num_0).toString() << "\n";
    std::cout << "cnum0 - cnum1: " << (c_num_0 - c_num_1).toString() << "\n";


    return 0;
}


/// modyfikacja:
/// przerobic + i -
/// mam 3 liczby CNumber cVal0, cVal1, cs
/// cv0 <- [1,2]
/// cv1 <- [3,4,5]
/// cs = cv0 + cv1    wynik [1,2,3,4,5]
/// cs = cb1-cv2;     wynik [3]
/// cs = cv0 - cv1    wynik [0]
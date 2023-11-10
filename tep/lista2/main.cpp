#include <iostream>
#include <sstream>
#include "CNumber.h"

std::string intToString(int number) {
    std::ostringstream s;
    s << number;
    return s.str();
}

#define CHECK_OPERATION(operation ) \
    result = c_num_0 operation c_num_1; \
    intRes = intToString(i operation j);                \
    if(result.toString() != intRes) { \
        std::cout << "error at i: " << i << " j: " << j << " expected: " << intRes << " actual: " << result.toString() <<"\n"; \
    }

int main() {
    CNumber c_num_0, c_num_1;
    CNumber result;
    std::string intRes;

    for(int i = -1000; i < 1000; i++) {
        for(int j = -1000; j < 1000; j++) {
            c_num_0 = i;
            c_num_1 = j;

            CHECK_OPERATION(+);
            CHECK_OPERATION(-);
            CHECK_OPERATION(*);
            if(j != 0) {
                CHECK_OPERATION(/);
            }

        }
    }

    c_num_0 = 213700000;
    c_num_0 = c_num_0 * c_num_0;
    std::cout << "MULTIPLICATION: " << (c_num_0).toString() << "\n";
    c_num_1 = 4212;
    c_num_1 = c_num_1*c_num_1;


//    c_num_0 = 9123123;
//    c_num_1 = 1;

    result = c_num_0 / c_num_1;
    std::string str = result.toString();
    std::cout << "division: " << result.toString() << "\n";



    return 0;
}

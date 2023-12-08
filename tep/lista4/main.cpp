#include "UserInterface.h"
#include "ParserParams/ParamsString.h"
#include "ParserParams/ParamsNumeric.h"

int main() {

//    ParamsString parserParams;
//    UserInterface<std::string> userInterface(parserParams);

    ParamsNumeric<double> parserParams;
    UserInterface<double> userInterface(parserParams);

    userInterface.start();




    return 0;


}

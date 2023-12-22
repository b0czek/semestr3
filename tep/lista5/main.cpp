#include "main.h"


#include "UserInterface.h"
#include "ParserParams/ParamsString.h"
#include "ParserParams/ParamsNumeric.h"
#include "CMySmartPointer.h"

int main() {

//    ParamsString parserParams;
//    UserInterface<std::string> userInterface(parserParams);

    ParamsNumeric<double> parserParams;
    UserInterface<double> userInterface(parserParams);

//    userInterface.start();

    typedef CMySmartPointer<CTree<double>> SmartPtr;

    CTree<double>* tree = new CTree<double>();
    SmartPtr smartPtr1(tree);

    SmartPtr smartPtr2(smartPtr1);

    SmartPtr smartPtr3 = smartPtr2.cDuplicate();




    return 0;


}

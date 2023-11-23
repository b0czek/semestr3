//
// Created by dariusz on 21.11.23.
//

#ifndef LISTA3_USERINTERFACE_H
#define LISTA3_USERINTERFACE_H

#include "CTree.h"
#include "Parser.h"

#define UI_CMD_ENTER "enter"
#define UI_CMD_VARS "vars"
#define UI_CMD_PRINT "print"
#define UI_CMD_COMP "comp"
#define UI_CMD_JOIN "join"



class UserInterface {
public:
    void start();

private:

    bool getVariablesMap(std::string& input, std::map<std::string, double> &output);

    static inline bool startsWithCommand(const char *command, std::string& input);

    void printParseErrors();

    CTree tree;
    Parser parser;
};


#endif //LISTA3_USERINTERFACE_H

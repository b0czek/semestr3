//
// Created by dariusz on 21.11.23.
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "UserInterface.h"


typedef std::set<std::string>::iterator VariablesIterator;
typedef std::vector<ParseError>::iterator ParseErrorIterator;

UserInterface::UserInterface() {
    parser = Parser(&operators);
}


void UserInterface::start() {
    while (true) {
        std::cout << ">> ";

        std::string input;
        getline(std::cin, input);

        if (startsWithCommand(UI_CMD_ENTER, input)) {
            tree.parse(input.c_str() + sizeof UI_CMD_ENTER, parser);
            printParseErrors();

            std::cout << "przetwarzana formula: \n";
            std::cout << tree.toString() << "\n";

        } else if (startsWithCommand(UI_CMD_PRINT, input)) {
            std::cout << tree.toString() << "\n";
        } else if (startsWithCommand(UI_CMD_VARS, input)) {
            std::set<std::string> variables = tree.getVariables();
            for (VariablesIterator it = variables.begin(); it != variables.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << "\n";
        } else if (startsWithCommand(UI_CMD_COMP, input)) {
            std::map<std::string, double> variablesMap;
            bool success = getVariablesMap(input, variablesMap);
            if (!success) {
                std::cout << "nieprawidłowa liczba zmiennych \n";
            } else {
                std::cout << "wynik obliczen: " << tree.eval(variablesMap) << "\n";
            }
        } else if (startsWithCommand(UI_CMD_JOIN, input)) {
            CTree secondTree, newTree;
            secondTree.parse(input.c_str() + sizeof UI_CMD_JOIN, parser);
            printParseErrors();

            newTree = tree + secondTree;
            tree = newTree;
        } else if(startsWithCommand(UI_CMD_LEVELS, input)) {
            std::cout << tree.levels();
        }
        else {
            std::cout << "Nie rozpoznano polecenia!\n";
        }
    }
}


bool UserInterface::getVariablesMap(std::string &input, std::map<std::string, double> &output) {
    std::stringstream ss(input);
    std::string element;

    std::set<std::string> variables = tree.getVariables();
    VariablesIterator it = variables.begin();

    // skip command
    getline(ss, element, ' ');


    while (getline(ss, element, ' ') && it != variables.end()) {
        output[*it] = atoi(element.c_str());
        it++;
    }
    return !ss && it == variables.end();
}

bool UserInterface::startsWithCommand(const char *command, std::string &input) {
    return input.substr(0, input.find(' ')) == command;
}

void UserInterface::printParseErrors() {
    std::vector<ParseError> parseErrors = parser.getParseErrors();

    for (ParseErrorIterator it = parseErrors.begin(); it != parseErrors.end(); it++) {
        std::cout << "Wykryto bład w wyrazeniu - " << ParseErrorTypeLabels[it->type] << " - ";
        std::cout << "było: \"" << it->mistake << "\" poprawiono na: \"" << it->correctedTo << "\"\n";
    }
}


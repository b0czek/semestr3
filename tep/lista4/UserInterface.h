//
// Created by dariusz on 21.11.23.
//

#ifndef LISTA3_USERINTERFACE_H
#define LISTA3_USERINTERFACE_H

#include <iostream>
#include "CTree.h"

#define UI_CMD_ENTER "enter"
#define UI_CMD_VARS "vars"
#define UI_CMD_PRINT "print"
#define UI_CMD_COMP "comp"
#define UI_CMD_JOIN "join"
#define UI_CMD_LEVELS "levels"
#define UI_CMD_DUPLICATE "duplicate"

template < typename T>
class UserInterface {
    typedef std::set<std::string>::iterator VariablesIterator;
    typedef std::vector<ParseError>::iterator ParseErrorIterator;

public:
    UserInterface(ParserParameters<T> &parserParameters) : parserParameters(&parserParameters){

    }

    void start() {
        while (true) {
            std::cout << ">> ";

            std::string input;
            getline(std::cin, input);

            if (startsWithCommand(UI_CMD_ENTER, input)) {
                tree.parse(input.c_str() + sizeof UI_CMD_ENTER, parser, *parserParameters);
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
                std::map<std::string, T> variablesMap;
                bool success = getVariablesMap(input, variablesMap);
                if (!success) {
                    std::cout << "nieprawidłowa liczba zmiennych \n";
                } else {
                    std::cout << "wynik obliczen: " << tree.eval(variablesMap) << "\n";
                }
            } else if (startsWithCommand(UI_CMD_JOIN, input)) {
                CTree<T> secondTree, newTree;
                secondTree.parse(input.c_str() + sizeof UI_CMD_JOIN, parser, *parserParameters);
                printParseErrors();

                newTree = tree + secondTree;
                tree = newTree;
            } else if(startsWithCommand(UI_CMD_LEVELS, input)) {
                std::cout << tree.levels();
            } else if(startsWithCommand(UI_CMD_DUPLICATE, input)) {
                tree.duplicate();
            }
            else {
                std::cout << "Nie rozpoznano polecenia!\n";
            }
        }
    }

private:

    bool getVariablesMap(std::string &input, std::map<std::string, T> &output) {
        std::stringstream ss(input);
        std::string element;

        std::set<std::string> variables = tree.getVariables();
        VariablesIterator it = variables.begin();

        // skip command
        getline(ss, element, ' ');


        while (getline(ss, element, ' ') && it != variables.end()) {
            output[*it] = variableToType(element);
            it++;
        }
        return !ss && it == variables.end();
    }



    static inline bool startsWithCommand(const char *command, std::string &input) {
        return input.substr(0, input.find(' ')) == command;
    }

    void printParseErrors() {
        std::vector<ParseError> parseErrors = parser.getParseErrors();

        for (ParseErrorIterator it = parseErrors.begin(); it != parseErrors.end(); it++) {
            std::cout << "Wykryto bład w wyrazeniu - " << ParseErrorTypeLabels[it->type] << " - ";
            std::cout << "było: \"" << it->mistake << "\" poprawiono na: \"" << it->correctedTo << "\"\n";
        }
    }

    T variableToType(std::string& variable);

    CTree<T> tree;
    Parser parser;
    ParserParameters<T> *parserParameters;
};

template < typename T>
T UserInterface<T>::variableToType(std::string &variable) {
    Token token = {
            .start = variable.c_str(),
            .length = variable.length()
    };
    return parserParameters->tokenToValue(&token);
}
template <>
std::string UserInterface<std::string>::variableToType(std::string &variable) {
    return variable;
}


#endif //LISTA3_USERINTERFACE_H

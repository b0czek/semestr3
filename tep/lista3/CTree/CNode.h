//
// Created by dariusz on 15.11.23.
//

#ifndef LISTA3_CNODE_H
#define LISTA3_CNODE_H

#include <vector>
#include <string>
#include <map>
#include "Operators.h"

#define MAX_LONG_LENGTH 20

enum NodeType {
    CONSTANT = 0,
    OPERATOR,
    VARIABLE
};
union NodeData {
    unsigned long constValue;
    const Operator *operatorType;
    char *variableName;

};

class CNode {
public:
    CNode();

    CNode(const CNode &other);

    ~CNode();

    void copyFrom(const CNode &other);

    void setData(unsigned long constValue);

    void setData(const Operator *operatorType);

    void setData(const char *variableName);

    std::vector<CNode *> &getChildren();

    void addChild(CNode *child);

    void freeChildren();

    double eval(std::map<std::string, double> &variablesMap);

    void scanVariables(std::set<std::string> &output);

    std::string toString();

    void toString(std::string &string);

private:

    NodeType nodeType;
    NodeData nodeData;

    std::vector<CNode *> children;
};


#endif //LISTA3_CNODE_H

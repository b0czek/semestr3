//
// Created by dariusz on 15.11.23.
//

#ifndef LISTA3_CTREE_H
#define LISTA3_CTREE_H


#include <set>
#include "CNode.h"
#include "Parser.h"


class CTree {
public:
    CTree();

    ~CTree();

    void parse(const char *data, Parser &parser);

    void parse(std::string &data, Parser &parser);


    CTree &operator=(const CTree &cOther);

    CTree &operator+(const CTree &cOther);

    std::string toString();

    double eval(std::map<std::string, double> &variablesMap);

    const std::set<std::string> &getVariables() const;

    void levels();

private:
    bool printLevel(CNode *node, int level);

    void scanVariables();

    CNode *leftmostLeaf();

    CNode root;

    std::set<std::string> variables;

};


#endif //LISTA3_CTREE_H

//
// Created by dariusz on 15.11.23.
//

#include <iostream>
#include "CTree.h"

CTree::CTree() {
}

CTree::~CTree() {
}

void CTree::parse(const char *data, Parser &parser) {
    root.freeChildren();
    parser.parse(data, &root);
    variables = parser.getVariables();
}

void CTree::parse(std::string &data, Parser &parser) {
    parse(data.c_str(), parser);
}

CTree &CTree::operator=(const CTree &cOther) {
    root.copyFrom(cOther.root);
    variables = cOther.variables;

    return *this;
}

CTree &CTree::operator+(const CTree &cOther) {
    CTree *newTree = new CTree(*this);
    CNode *joinedAt = newTree->leftmostLeaf();
    joinedAt->copyFrom(cOther.root);

    newTree->scanVariables();

    return *newTree;
}

std::string CTree::toString() {
    return root.toString();
}

double CTree::eval(std::map<std::string, double> &variablesMap) {
    return root.eval(variablesMap);
}

const std::set<std::string> &CTree::getVariables() const {
    return variables;
}

void CTree::scanVariables() {
    variables.clear();
    root.scanVariables(variables);
}

CNode *CTree::leftmostLeaf() {
    CNode *leaf = &root;
    while (leaf->getChildren().size() != 0) {
        leaf = leaf->getChildren()[0];

    }
    return leaf;
}

void CTree::levels() {
    bool result = false;
    int i = 1;
    do {
        result = printLevel(&root, i);
        i++;
        std::cout << "\n";
    } while(result);
}

bool CTree::printLevel(CNode *node, int level) {
    if(level == 1) {
        std::cout << node->toString(true);
        return true;
    }
    else {
        std::vector<CNode *> children = node->getChildren();
        if(children.size() == 0){
            return false;
        }
        int result = 0;
        for(int i = 0 ; i < children.size(); i++) {
            result += printLevel(children[i], level - 1);
            std::cout << " ";
        }
        return result != 0;
    }
}


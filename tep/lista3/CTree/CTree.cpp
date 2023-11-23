//
// Created by dariusz on 15.11.23.
//

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




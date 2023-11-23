//
// Created by dariusz on 15.11.23.
//

#include <cstring>
#include <cstdio>
#include <set>
#include "CNode.h"

CNode::CNode() {
    nodeType = CONSTANT;
    nodeData.constValue = 1;
}

CNode::CNode(const CNode &other) {
    copyFrom(other);
}

CNode::~CNode() {
    if (nodeType == VARIABLE) {
        delete nodeData.variableName;
    }
    freeChildren();

}

void CNode::copyFrom(const CNode &other) {
    freeChildren();

    nodeType = other.nodeType;
    if (nodeType == VARIABLE) {
        nodeData.variableName = strdup(other.nodeData.variableName);
    } else {
        nodeData = other.nodeData;
    }

    for (int i = 0; i < other.children.size(); i++) {
        children.push_back(new CNode(*other.children[i]));
    }
}

void CNode::setData(unsigned long constValue) {
    nodeType = CONSTANT;
    nodeData.constValue = constValue;
}

void CNode::setData(const Operator *operatorType) {
    nodeType = OPERATOR;
    nodeData.operatorType = operatorType;
}

void CNode::setData(const char *variableName) {
    nodeType = VARIABLE;
    nodeData.variableName = strdup(variableName);
}

std::vector<CNode *> &CNode::getChildren() {
    return children;
}

void CNode::addChild(CNode *child) {
    children.push_back(child);
}

void CNode::freeChildren() {
    for (int i = 0; i < children.size(); i++) {
        children[i]->freeChildren();
        delete children[i];
    }
    children.clear();
}

double CNode::eval(std::map<std::string, double> &variablesMap) {
    switch (nodeType) {
        case CONSTANT:
            return nodeData.constValue;
        case VARIABLE:
            return variablesMap.at(nodeData.variableName);
        case OPERATOR: {
            int argumentCount = nodeData.operatorType->argumentCount;
            double args[argumentCount];
            for (int i = 0; i < argumentCount; i++) {
                args[i] = children[i]->eval(variablesMap);
            }
            return nodeData.operatorType->execute(args);
        }
        default:
            return 0.0;
    }
}

void CNode::scanVariables(std::set<std::string> &output) {
    if (nodeType == VARIABLE) {
        output.insert(nodeData.variableName);
    }
    for (int i = 0; i < children.size(); i++) {
        children[i]->scanVariables(output);
    }
}

std::string CNode::toString() {
    std::string result;
    toString(result);
    return result;
}

void CNode::toString(std::string &string) {
    switch (nodeType) {
        case VARIABLE:
            string += nodeData.variableName;
            break;
        case CONSTANT: {
            char buffer[MAX_LONG_LENGTH + 1];
            sprintf(buffer, "%lu", nodeData.constValue);
            string += buffer;
            break;
        }
        case OPERATOR:
            string += nodeData.operatorType->symbol;
            for (int i = 0; i < nodeData.operatorType->argumentCount; i++) {
                string += " ";
                children[i]->toString(string);
            }
            break;
    }
}

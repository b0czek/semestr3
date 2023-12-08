//
// Created by dariusz on 15.11.23.
//

#ifndef LISTA3_CNODE_H
#define LISTA3_CNODE_H

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include "Operators.h"

enum NodeType {
    CONSTANT = 0,
    OPERATOR,
    VARIABLE
};


template<typename T>
class CNode {
public:
    union NodeData {
        T *constValue;
        const Operator<T> *operatorType;
        char *variableName;

    };


    CNode() {
        nodeType = VARIABLE;
        nodeData.variableName = strdup("x");
    }

    CNode(const CNode &other) {
        copyFrom(other);
    }

    ~CNode() {
        freeNode();
    }

    void freeData() {
        if (nodeType == VARIABLE) {
            delete nodeData.variableName;
        } else if (nodeType == CONSTANT) {
            delete nodeData.constValue;
        }
    }

    void freeNode() {
        freeData();
        freeChildren();

    }

    void copyFrom(const CNode &other, int withChildren = true) {
        freeNode();

        nodeType = other.nodeType;
        if (nodeType == VARIABLE) {
            nodeData.variableName = strdup(other.nodeData.variableName);

        }
        else if(nodeType == CONSTANT) {
            nodeData.constValue = new T;
            *nodeData.constValue = *other.nodeData.constValue;
        }
        else {
            nodeData = other.nodeData;
        }

        if(withChildren) {
            for (int i = 0; i < other.children.size(); i++) {
                children.push_back(new CNode(*other.children[i]));
            }
        }
    }

    void setConstValue(T &constValue) {
        if (nodeType != CONSTANT) {
            freeData();
            nodeType = CONSTANT;
            nodeData.constValue = new T;
        }

        *nodeData.constValue = constValue;
    }

    void setOperator(const Operator<T> *operatorType) {
        freeData();

        nodeType = OPERATOR;
        nodeData.operatorType = operatorType;
    }

    void setVariable(const char *variableName) {
        freeData();

        nodeType = VARIABLE;
        nodeData.variableName = strdup(variableName);
    }

    std::vector<CNode *> &getChildren() {
        return children;
    }

    void addChild(CNode *child) {
        children.push_back(child);
    }

    void freeChildren() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
        children.clear();
    }

    T eval(std::map<std::string, T> &variablesMap) {
        switch (nodeType) {
            case CONSTANT:
                return *nodeData.constValue;
            case VARIABLE:
                return variablesMap.at(nodeData.variableName);
            case OPERATOR: {
                int argumentCount = nodeData.operatorType->argumentCount;
                T args[argumentCount];
                for (int i = 0; i < argumentCount; i++) {
                    args[i] = children[i]->eval(variablesMap);
                }
                return nodeData.operatorType->execute(args);
            }
        }
    }

    void scanVariables(std::set<std::string> &output) {
        if (nodeType == VARIABLE) {
            output.insert(nodeData.variableName);
        }
        for (int i = 0; i < children.size(); i++) {
            children[i]->scanVariables(output);
        }
    }

    std::string toString(int shortened = false) {
        std::string result;
        toString(result, shortened);
        return result;
    }

    void toString(std::string &string, int shortened) {
        switch (nodeType) {
            case VARIABLE:
                string += nodeData.variableName;
                break;
            case CONSTANT: {
                string += constToString();
                break;
            }
            case OPERATOR:
                string += nodeData.operatorType->symbol;
                if (!shortened) {
                    for (int i = 0; i < nodeData.operatorType->argumentCount; i++) {
                        string += " ";
                        children[i]->toString(string, shortened);
                    }
                }
                break;
        }
    }

    std::string constToString();


    CNode<T> * duplicateByType();

private:

    NodeType nodeType;
    NodeData nodeData;

    std::vector<CNode *> children;
};


template<typename T>
std::string CNode<T>::constToString() {
    std::stringstream ss;
    ss << *nodeData.constValue;
    return ss.str();
}

template<>
inline std::string CNode<std::string>::constToString() {
    return '\"' + *nodeData.constValue + '\"';
}

template<typename T>
CNode<T> * CNode<T>::duplicateByType() {
    CNode<T> *node = new CNode<T>;
    node->copyFrom(*this);
    return node;
}

template<>
inline CNode<double> * CNode<double>::duplicateByType() {
    CNode<double> *node = new CNode<double>;
    node->copyFrom(*this, false);
    return node;
}

template<>
inline CNode<std::string> * CNode<std::string>::duplicateByType() {
    return NULL;
}


#endif //LISTA3_CNODE_H

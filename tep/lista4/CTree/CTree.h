//
// Created by dariusz on 15.11.23.
//

#ifndef LISTA3_CTREE_H
#define LISTA3_CTREE_H


#include <set>
#include "CNode.h"
#include "Parser.h"

template<typename T>
class CTree {
public:
    CTree() {
        scanVariables();
    }

    ~CTree() {}

    void parse(const char *data, Parser &parser, ParserParameters<T> &parameters) {
        root.freeChildren();
        parser.parse(data, &root, parameters);
        variables = parser.getVariables();
    }


    CTree &operator=(const CTree &cOther) {
        root.copyFrom(cOther.root);
        variables = cOther.variables;

        return *this;
    }

    CTree operator+(const CTree &cOther) {
        CTree newTree = CTree(*this);
        CNode<T> *joinedAt = newTree.leftmostLeaf();
        joinedAt->copyFrom(cOther.root);

        newTree.scanVariables();

        return newTree;
    }

    std::string toString() {
        return root.toString();
    }

    T eval(std::map<std::string, T> &variablesMap) {
        return root.eval(variablesMap);
    }

    const std::set<std::string> &getVariables() const {
        return variables;

    }

    std::string levels() {
        bool success = false;
        std::string result;
        int i = 1;
        do {
            success = printLevel(&root, i, result);
            result += "\n";
            i++;
        } while (success);
        return result;
    }

    void duplicate() {
        CNode<T> * newroot = root.duplicateByType();
        if(newroot != NULL) {
            root.copyFrom(*newroot);
            delete newroot;
        }
    }

private:
    bool printLevel(CNode<T> *node, int level, std::string &output) {
        if (level == 1) {
            output += node->toString(true);
            return true;
        } else {
            std::vector<CNode<T> *> children = node->getChildren();
            if (children.size() == 0) {
                return false;
            }
            int result = 0;
            for (int i = 0; i < children.size(); i++) {
                result += printLevel(children[i], level - 1, output);
                output += " ";
            }
            return result != 0;
        }
    }

    void scanVariables() {
        variables.clear();
        root.scanVariables(variables);
    }

    CNode<T> *leftmostLeaf() {
        CNode<T> *leaf = &root;
        while (leaf->getChildren().size() != 0) {
            leaf = leaf->getChildren()[0];

        }
        return leaf;
    }

    CNode<T> root;

    std::set<std::string> variables;

};


#endif //LISTA3_CTREE_H

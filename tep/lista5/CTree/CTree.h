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
        root = new CNode<T>();
        scanVariables();
    }

    CTree(const CTree& other) {
#if DEBUG
        std::cout << "tree copied" << "\n";
#endif
        root = new CNode<T>(*other.root);
        variables = other.variables;
    }

    CTree(CTree &&other) {
#if DEBUG
        std::cout << "tree moved" << "\n";
#endif
        root = other.root;
        other.root = nullptr;

        variables = std::move(other.variables);;

    }

    ~CTree() {
        if(root != nullptr) {
            delete root;
        }
    }

    void parse(const char *data, Parser &parser, ParserParameters<T> &parameters) {
        root->freeChildren();
        parser.parse(data, root, parameters);
        variables = parser.getVariables();
    }


    void operator=(CTree &&other) {
        if(&other != this) {
            delete root;
            root = other.root;
            variables = std::move(other.variables);

            other.root = nullptr;
        }
    }

//    CTree &operator=(const CTree &cOther) {
//        root.copyFrom(cOther.root);
//        variables = cOther.variables;
//
//        return *this;
//    }

    CTree operator+(const CTree &cOther) {
        CTree newTree(*this);
        CNode<T> *joinedAt = newTree.leftmostLeaf();
        joinedAt->copyFrom(*cOther.root);

        newTree.scanVariables();

        return std::move(newTree);
    }

    std::string toString() {
        return root->toString();
    }

    T eval(std::map<std::string, T> &variablesMap) {
        return root->eval(variablesMap);
    }

    const std::set<std::string> &getVariables() const {
        return variables;

    }

private:


    void scanVariables() {
        variables.clear();
        root->scanVariables(variables);
    }

    CNode<T> *leftmostLeaf() {
        CNode<T> *leaf = root;
        while (leaf->getChildren().size() != 0) {
            leaf = leaf->getChildren()[0];

        }
        return leaf;
    }

    CNode<T>* root;

    std::set<std::string> variables;

};


#endif //LISTA3_CTREE_H

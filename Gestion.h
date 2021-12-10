//
// Created by Usuario on 5/12/2021.
//

#ifndef ARANGURENTALLERLISTASDOBLES_GESTION_H
#define ARANGURENTALLERLISTASDOBLES_GESTION_H

#include "Node.h"
#include "LinkedList.cpp"
#include "Calculadora.h"

class Gestion {
public:
    Gestion(LinkedList<Calculadora>*);

    bool isEmpty();

    void addNodeFirst(Calculadora);

    void addNodeLast(Calculadora);

    bool addNodeSorted(Calculadora);

    bool addNodeAfter(std::string id, Calculadora);

    bool addNodeBefore(std::string id, Calculadora);

    std::string findNode(std::string);

    std::string findInfo(std::string);

    std::string deleteNode(std::string);

    std::string getList(bool);

    int getSize();

    Calculadora* getObject(int);

    std::string getFirst();

    std::string getLast();

    std::string convertToString(Calculadora);

private:
    LinkedList<Calculadora>* list;
};


#endif //ARANGURENTALLERLISTASDOBLES_GESTION_H

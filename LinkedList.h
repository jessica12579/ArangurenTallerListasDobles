//
// Created by Usuario on 9/12/2021.
//

#ifndef ARANGURENTALLERLISTASDOBLES_LINKEDLIST_H
#define ARANGURENTALLERLISTASDOBLES_LINKEDLIST_H

#include "Node.h"
#include <string>
#include <vector>

template <class T>

class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList();

    bool isEmpty();

    void addNodeFirst(T);

    void addNodeLast(T);

    void addNodeAfterTo(Node<T>*, T);

    void addNodeBeforeTo(Node<T>*, T);

    bool nodeExist(std::string);

    T *findInfo(std::string);

    Node<T>* findNode(std::string);

    std::vector<T> getList(bool);

    T deleteNode(Node<T>*);

    int getSize();

    void addNodeSorted(T info);

    T* getObject(int);

    T getFirst();

    T getLast();

    virtual ~LinkedList();

};


#endif //ARANGURENTALLERLISTASDOBLES_LINKEDLIST_H

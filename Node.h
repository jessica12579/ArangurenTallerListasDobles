//
// Created by Jessica on 5/12/2021.
//

#ifndef ARANGURENTALLERLISTASDOBLES_NODE_H
#define ARANGURENTALLERLISTASDOBLES_NODE_H

#include <cstdlib>

template <class T> class LinkedList;
template <class T>

class Node {
    friend class LinkedList<T>;

private:
    Node<T>* next;
    Node<T>* previous;
    T info;

public:
    Node(T);

    virtual ~Node();
};

template<class T>
Node<T>::Node(T info) {
    Node<T>::info = info;
    Node<T>::next = NULL;
    Node<T>::previous = NULL;
}


template<class T>
Node<T>::~Node() = default;


#endif //ARANGURENTALLERLISTASDOBLES_NODE_H

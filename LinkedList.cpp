//
// Created by Jessica on 9/12/2021.
//

#include "LinkedList.h"

template<class T>

LinkedList<T>::LinkedList() {
    LinkedList::head = NULL;
    LinkedList::tail = NULL;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return head == NULL and tail == NULL;
}

template<class T>
void LinkedList<T>::addNodeFirst(T info) {
    Node<T> *newNode = new Node<T>(info);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template<class T>
void LinkedList<T>::addNodeLast(T info) {
    Node<T> *newNode = new Node<T>(info);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

template<class T>
std::vector<T> LinkedList<T>::getList(bool forward) {
    std::vector<T> out;
    Node<T> *aux = forward ? head : tail;
    while (aux != NULL) {
        out.push_back(aux->info);
        aux = forward ? aux->next : aux->previous;
    }
    return out;
}

template <class T>
T* LinkedList<T>::findInfo(std::string id){
    return &findNode(id)->info;
}

template<class T>
Node<T> *LinkedList<T>::findNode(std::string id) {
    Node<T> *aux = head;
    while (aux != NULL) {
        if (aux->info.getId().compare(id) == 0) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}


template<class T>
void LinkedList<T>::addNodeAfterTo(Node<T> *after, T info) {
    if (after != tail) {
        if (after != NULL) {
            Node<T> *newNode = new Node<T>(info);
            Node<T> *aux = head;
            while (aux != after) {
                aux = aux->next;
            }
            newNode->previous = aux;
            newNode->next = aux->next;
            aux->next->previous = newNode;
            aux->next = newNode;
        }
    } else {
        addNodeLast(info);
    }
}

template<class T>
void LinkedList<T>::addNodeBeforeTo(Node<T> *before, T info) {
    if (before != head) {
        Node<T> *newNode = new Node<T>(info);
        Node<T> *aux = head;
        if (before != NULL) {
            while (aux != before) {
                aux = aux->next;
            }
            newNode->next = aux;
            aux->previous->next = newNode;
            aux->previous = newNode;
        }
    } else {
        addNodeFirst(info);
    }
}

template <class T>
void LinkedList<T>::addNodeSorted(T info){
    Node<T>* aux = head;
    if(isEmpty()){
        addNodeFirst(info);
    }else{
        if (info.getId().compare(head->info.getId()) < 0){
            addNodeFirst(info);
        }else if(info.getId().compare(tail->info.getId()) > 0){
            addNodeLast(info);
        }else{
            while (aux != NULL && aux->next != NULL){
                if (info.getId().compare(aux->info.getId()) > 0 and info.getId().compare(aux->next->info.getId()) < 0){
                    addNodeAfterTo(aux, info);
                    break;
                }
                aux = aux->next;
            }
        }
    }
}

template<class T>
T LinkedList<T>::deleteNode(Node<T> *node) {
    Node<T> *aux = head;
    T ret;
    if (node == head) {
        ret = head->info;
        head = head->next;
    } else if (node == tail) {
        ret = tail->info;
        tail = tail->previous;
        tail->next = NULL;
    } else {
        while (aux != NULL) {
            if (aux == node) {
                ret = aux->info;
                aux->next->previous = aux->previous;
                aux->previous->next = aux->next;
                break;
            }
            aux = aux->next;
        }
    }
    return ret;
}

template<class T>
int LinkedList<T>::getSize() {
    if ( isEmpty() ) return 0;
    Node<T>* aux = head;
    int count = 0;
    while (aux != tail){
        aux = aux->next;
        count++;
    }
    return count;
}

template<class T>
T *LinkedList<T>::getObject(int index) {
    Node<T>* aux = head;
    int count = 0;
    while (aux != NULL){
        if (count == index){
            break;
        }
        aux = aux->next;
        count++;
    }
    return &aux->info;
}

template<class T>
T LinkedList<T>::getFirst() {
    return head->info;
}

template<class T>
T LinkedList<T>::getLast() {
    return tail->info;
}

template<class T>
bool LinkedList<T>::nodeExist(std::string id) {
    return findNode(id) != NULL;
}

template<class T>
LinkedList<T>::~LinkedList() = default;




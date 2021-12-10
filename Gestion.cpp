//
// Created by Jessica on 5/12/2021.
//

#include <sstream>
#include "Gestion.h"

Gestion::Gestion(LinkedList<Calculadora> *list) {
    Gestion::list = list;
}

bool Gestion::isEmpty() {
    return Gestion::list->isEmpty();
}

void Gestion::addNodeFirst(Calculadora calculadora) {
    list->addNodeFirst(calculadora);
}

void Gestion::addNodeLast(Calculadora calculadora) {
    list->addNodeFirst(calculadora);
}

bool Gestion::addNodeSorted(Calculadora calculadora) {
    if (list->nodeExist(calculadora.getId())) {
        return false;
    }
    list->addNodeSorted(calculadora);
    return true;
}

bool Gestion::addNodeAfter(std::string after, Calculadora info) {
    if (list->nodeExist(after)) {
        list->addNodeAfterTo(list->findNode(after), info);
        return true;
    }
    return false;
}

bool Gestion::addNodeBefore(std::string before, Calculadora info) {
    if (list->nodeExist(before)) {
        list->addNodeBeforeTo(list->findNode(before), info);
        return true;
    }
    return false;
}

std::string Gestion::findNode(std::string id) {
    if (list->nodeExist(id)) {
        return "Se ha encontrado el nodo: " + findInfo(id);
    }
    return "Nodo no encontrado";
}

std::string Gestion::findInfo(std::string id) {
    return (list->findInfo(id)->getId().compare("")) == 0 ? "Informacion no encontrada" : convertToString(
            *list->findInfo(id));
}

std::string Gestion::deleteNode(std::string id) {
    std::string retu = "Nodo no encontrado";
    Calculadora ret;
    if (list->nodeExist(id)) {
        ret = list->deleteNode(list->findNode(id));
        retu = "Se ha eliminado: " + convertToString(ret);
    }
    return retu;
}

std::string Gestion::getList(bool dir) {
    std::string ret;
    if (list->isEmpty()) {
        return "La lista esta vacia";
    } else {
        for (const auto &item : list->getList(dir)) {
            ret += convertToString(item) + "\n";
        }
    }
    return ret;
}

int Gestion::getSize() {
    return list->getSize();
}

Calculadora *Gestion::getObject(int index) {
    return list->getObject(index);
}

std::string Gestion::getFirst() {
    return convertToString(list->getFirst());
}

std::string Gestion::getLast() {
    return convertToString(list->getLast());
}

std::string Gestion::convertToString(Calculadora calculadora) {
    std::ostringstream ret;
    ret << calculadora;
    return ret.str();
}

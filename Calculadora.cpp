//
// Created by Jessica on 5/12/2021.
//

#include "Calculadora.h"

Calculadora::Calculadora(const std::string &marca, const std::string &color, std::string id)
        : marca(
        marca), color(color), id(id) {}

const std::string &Calculadora::getBrand() const {
    return marca;
}

void Calculadora::setMarca(const std::string &marca) {
    Calculadora::marca = marca;
}

const std::string &Calculadora::getColor() const {
    return color;
}

void Calculadora::setColor(const std::string &color) {
    Calculadora::color = color;
}

std::string Calculadora::getId() const {
    return id;
}

void Calculadora::setId(const std::string &id) {
    Calculadora::id = id;
}


std::ostream &operator<<(std::ostream &os, const Calculadora &calculadora) {
    os << " Id: " << calculadora.id << " Marca: " << calculadora.marca << " Color: " << calculadora.color;
    return os;
}

std::string Calculadora::toString() {
    return " Id: " + Calculadora::id + " Marca: " + Calculadora::marca + " Color: " + Calculadora::color;
}

Calculadora::Calculadora() = default;

Calculadora::~Calculadora() = default;
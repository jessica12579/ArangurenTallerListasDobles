//
// Created by Jessica on 5/12/2021.
//

#ifndef ARANGURENTALLERLISTASDOBLES_CALCULADORA_H
#define ARANGURENTALLERLISTASDOBLES_CALCULADORA_H

#include <string>
#include <ostream>

class Calculadora {
private:
    std::string marca;
    std::string color;
    std::string id;

public:
    Calculadora();

    Calculadora(const std::string &marca, const std::string &color, std::string id);

    const std::string &getBrand() const;

    void setMarca(const std::string &marca);

    const std::string &getColor() const;

    void setColor(const std::string &marca);

    std::string getId() const;

    void setId(const std::string &id);


    std::string toString();

    friend std::ostream &operator<<(std::ostream &os, const Calculadora &calculadora);

    virtual ~Calculadora();

};


#endif //ARANGURENTALLERLISTASDOBLES_CALCULADORA_H

#include <iostream>

#include "Calculadora.h"
#include "Gestion.h"

void test();

void list(bool);

void sortedList();

void selector();

Calculadora createCalculadora();

int main() {
    selector();
    return 0;
}

void selector() {
    int op;
    std::cout << "Seleccione el tipo de lista que desea utilizar: " << std::endl
              << "1. Por defincion" << std::endl
              << "2. Ordenada" << std::endl;
    std::cin >> op;
    int isSorted = op == 2;
    list(isSorted);

    std::cout << "Esta seguro?" << std::endl << "1. Si" << std::endl << "2. No" << std::endl;
    std::cin >> op;
    op == 1 ? selector() : exit(0);
}

void list(bool isSorted) {

    LinkedList<Calculadora> *calculadoras = new LinkedList<Calculadora>();
    LinkedList<Calculadora> *sorted = new LinkedList<Calculadora>();
    Gestion *gestion = new Gestion(isSorted ? sorted : calculadoras);
    int op = 0;
    Calculadora calculadora;
    do {
        std::cout << "------------BIENVENIDO-----------" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout
                << "1. Verificar si la lista esta vacia" << std::endl
                << "2. Agregar Nodo" << std::endl
                << "3. Encontrar Nodo" << std::endl
                << "4. Eliminar Nodo" << std::endl
                << "5. Obtener datos" << std::endl
                << "6. SALIR" << std::endl;
        std::cin >> op;
        switch (op) {
            case 1: {
                std::cout << "La lista esta: " << (gestion->isEmpty()?"Vacia":"Con objetos") << std::endl;
                break;
            }
            case 2: {
                if (!isSorted) {
                    int op2 = 0;
                    std::cout << "Donde desea agregarlo:" << std::endl
                              << "1. Al inicio" << std::endl
                              << "2. Al final" << std::endl
                              << "3. Despues de un nodo" << std::endl
                              << "4. Antes de un nodo" << std::endl;
                    std::cin >> op2;
                    calculadora = createCalculadora();
                    switch (op2) {
                        case 1:
                            gestion->addNodeFirst(calculadora);
                            std::cout << "La calculadora ha sido agregada al inicio con exito" << std::endl;
                            break;
                        case 2:
                            gestion->addNodeLast(calculadora);
                            std::cout << "La calculadora ha sido agregada al final con exito" << std::endl;
                            break;
                        case 3: {
                            std::string id;
                            std::cout << "Ingrese el id del nodo: " << std::endl;
                            std::cin >> id;
                            if (gestion->addNodeAfter(id, calculadora)) {
                                std::cout << "Nodo agregado despues del nodo con id " << id << std::endl;
                            } else {
                                std::cout << "Error al añadir nodo..." << std::endl;
                            }
                            break;
                        }
                        case 4: {
                            std::string id;
                            std::cout << "Ingrese el id del nodo: " << std::endl;
                            std::cin >> id;
                            if (gestion->addNodeBefore(id, calculadora)) {
                                std::cout << "Nodo agregado antes del nodo con id " << id << std::endl;
                            } else {
                                std::cout << "Error al añadir nodo..." << std::endl;
                            }
                            break;
                        }
                        default:
                            std::cout << "Opcion invalida, volviendo al menu..." << std::endl;
                            break;
                    }
                } else {
                    calculadora = createCalculadora();
                    gestion->addNodeSorted(calculadora);
                    std::cout << "Nodo agregado ordenado" << std::endl;
                }
                break;
            }
            case 3: {
                int op2 = 0;
                std::cout << "Seleccione una opcion:" << std::endl
                          << "1. Encontrar si existe el nodo" << std::endl
                          << "2. Ver la informacion del nodo" << std::endl;
                std::cin >> op2;
                std::string id;
                switch (op2) {
                    case 1: {
                        std::cout << "Ingrese el id del nodo: " << std::endl;
                        std::cin >> id;
                        std::cout << gestion->findNode(id) << std::endl;
                    }
                        break;
                    case 2:
                        std::cout << "Ingrese el id del nodo: " << std::endl;
                        std::cin >> id;
                        std::cout << gestion->findInfo(id);
                        break;
                    default:
                        std::cout << "Opción invalida..." << std::endl;
                        break;
                }
                break;
            }
            case 4: {
                std::string id;
                std::cout << "Ingrese el id de nodo a eliminar" << std::endl;
                std::cin >> id;
                std::cout << gestion->deleteNode(id) << std::endl;

            }
                break;
            case 5: {
                int op2 = 0;
                std::cout << "Seleccione una opcion:" << std::endl
                          << "1. Obtener la lista completa" << std::endl
                          << "2. Obtener el tamanio de la lista" << std::endl
                          << "3. Obtener el objeto por id" << std::endl
                          << "4. Obtener el primer nodo" << std::endl
                          << "5. Obtener el ultimo nodo" << std::endl;
                std::cin >> op2;
                switch (op2) {
                    case 1: {
                        int op3=1;
                        std::cout << gestion->getList(op3) << std::endl;
                        break;
                    }
                    case 2:
                        std::cout << "El tamanio de la lista es " << gestion->getSize() << std::endl;
                        break;
                    case 3: {
                        int id;
                        std::cout << "Ingrese el indice (id) del objeto que desea obtener: " << std::endl;
                        std::cin >> id;
                        Calculadora *calculadora = gestion->getObject(id);
                        if (calculadora != NULL) {
                            std::cout << "El objeto es " << calculadora << std::endl;
                        } else {
                            std::cout << "No se ha encontrado el objeto" << std::endl;
                        }
                        break;
                    }
                    case 4: {
                        std::cout << "El primer elemento es: " << gestion->getFirst() << std::endl;
                        break;
                    }
                    case 5: {
                        std::cout << "El ultimo elemento es: " << gestion->getLast() << std::endl;
                        break;
                    }
                }
                break;
            }
            case 6:
                break;
            default:
                std::cout << "Opción no valida, intentelo nuevamente..." << std::endl;
                break;
        }
    } while (op != 6);
}

Calculadora createCalculadora() {
    std::string marca;
    std::string color;
    std::string id;

    std::cout << "Ingrese el id de la calculadora: " << std::endl;
    std::cin >> id;
    std::cout << "Ingrese la marca de la calculadora: " << std::endl;
    std::cin >> marca;
    std::cout << "Ingrese el color de la calculadora: " << std::endl;
    std::cin >> color;

    return Calculadora(marca, color, id);
}

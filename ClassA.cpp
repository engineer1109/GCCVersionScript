#include "ClassA.h"
#include <iostream>

void funcA() {
    std::cout << "funcA" << std::endl;
}

void AA::funcB() {
    std::cout << "funcB" << std::endl;
}

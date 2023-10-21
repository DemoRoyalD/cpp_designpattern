//
// Created by yuanxuedong on 2023/10/21.
//

#include "fruit_factory.h"

void Apple::getName() {
    std::cout << "apple" << std::endl;
}

void Banana::getName() {
    std::cout << "banana" << std::endl;
}

void Pear::getName() {
    std::cout << "pear" << std::endl;
}

Fruit *FruitFactory::createFruit(std::string name) {
    if (name == "apple") {
        return new class Apple;
    } else if (name == "banana") {
        return new class Banana;
    } else if (name == "pear") {
        return new class Pear;
    }
    return NULL;
}


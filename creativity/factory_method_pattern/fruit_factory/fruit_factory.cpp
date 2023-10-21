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


Apple *AppleFactory::createFruit() {
    return new Apple;
}

Banana *BananaFactory::createFruit() {
    return new Banana;
}

Pear *PearFactory::createFruit() {
    return new Pear;
}
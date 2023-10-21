//
// Created by yuanxuedong on 2023/10/21.
//

#include "factory_method_pattern_main.h"
#include "fruit_factory.h"
#include<iostream>

int main() {
    AbstractFruitFactory *factory = NULL;
    Fruit *fruit = NULL;

    factory = new AppleFactory;
    fruit = factory->createFruit();
    fruit->getName();
    delete factory;
    delete fruit;

    factory = new BananaFactory;
    fruit = factory->createFruit();
    fruit->getName();
    delete factory;
    delete fruit;

    factory = new PearFactory;
    fruit = factory->createFruit();
    fruit->getName();
    delete factory;
    delete fruit;

    return 0;
}
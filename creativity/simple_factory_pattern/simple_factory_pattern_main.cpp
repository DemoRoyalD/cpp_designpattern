//
// Created by yuanxuedong on 2023/10/21.
//

#include "simple_factory_pattern_main.h"

#include "fruit_factory.h"


int main() {
    FruitFactory *factory = new FruitFactory;
    Fruit *fruit = NULL;

    fruit = factory->createFruit(FruitEnumToString(Apple));
    fruit->getName();
    delete fruit;
    fruit = NULL;

    fruit = factory->createFruit(FruitEnumToString(Banana));
    fruit->getName();
    delete fruit;
    fruit = NULL;

    fruit = factory->createFruit(FruitEnumToString(Pear));
    fruit->getName();
    delete fruit;
    fruit = NULL;

    return 0;
}

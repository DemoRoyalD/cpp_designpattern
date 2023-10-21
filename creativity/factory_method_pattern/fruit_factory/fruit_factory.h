//
// Created by yuanxuedong on 2023/10/21.
//

#ifndef CPP_DESIGNPATTERN_FRUIT_FACTORY_H
#define CPP_DESIGNPATTERN_FRUIT_FACTORY_H

#include<iostream>

class Fruit {
public:
    virtual void getName() = 0;
};

class Apple : public Fruit {
public:
    virtual void getName();
};

class Banana : public Fruit {
public:
    virtual void getName();
};

class Pear : public Fruit {
public:
    virtual void getName();
};

class AbstractFruitFactory {
public:
    virtual Fruit *createFruit() = 0;
};

class AppleFactory : public AbstractFruitFactory {
public:
    virtual Apple *createFruit();
};

class BananaFactory : public AbstractFruitFactory {
public:
    virtual Banana *createFruit();
};

class PearFactory : public AbstractFruitFactory {
public:
    virtual Pear *createFruit();
};


#endif //CPP_DESIGNPATTERN_FRUIT_FACTORY_H

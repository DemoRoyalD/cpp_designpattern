//
// Created by yuanxuedong on 2023/10/21.
//
#pragma once
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


class FruitFactory {
public:
    Fruit *createFruit(std::string name);
};


enum FruitEnum {
    Apple, Banana, Pear
};

static std::string FruitEnumToString(FruitEnum fruit) {
    switch (fruit) {
        case Apple:
            return "apple";
        case Banana:
            return "banana";
        case Pear:
            return "pear";
        default:
            return "unknown";
    }
}

#endif //CPP_DESIGNPATTERN_FRUIT_FACTORY_H

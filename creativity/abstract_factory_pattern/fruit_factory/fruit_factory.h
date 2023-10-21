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

class AbstractApple : public Fruit {
public:
    virtual void getName() = 0;
};

class AbstractBanana : public Fruit {
public:
    virtual void getName() = 0;
};

class AbstractPear : public Fruit {
public:
    virtual void getName() = 0;
};

class ChinaApple : public AbstractApple {
public:
    void getName();
};

class ChinaBanana : public AbstractBanana {
public:
    void getName();
};

class ChinaPear : public AbstractPear {
public:
    void getName();
};

class AmericaApple : public AbstractApple {
public:
    void getName();
};

class AmericaBanana : public AbstractBanana {
public:
    void getName();
};

class AmericaPear : public AbstractPear {
public:
    void getName();
};

class JapanApple : public AbstractApple {
public:
    void getName();
};

class JapanBanana : public AbstractBanana {
public:
    void getName();
};

class JapanPear : public AbstractPear {
public:
    void getName();
};

class AbstractFruitFactory {
public:
    virtual AbstractApple *createApple() = 0;

    virtual AbstractBanana *createBanana() = 0;

    virtual AbstractPear *createPear() = 0;
};

class ChinaFruitFactory : public AbstractFruitFactory {
public:
    AbstractApple *createApple();

    AbstractBanana *createBanana();

    AbstractPear *createPear();
};

class AmericaFruitFactory : public AbstractFruitFactory {
public:
    AbstractApple *createApple();

    AbstractBanana *createBanana();

    AbstractPear *createPear();
};

class JapanFruitFactory : public AbstractFruitFactory {
public:
    virtual AbstractApple *createApple();

    virtual AbstractBanana *createBanana();

    virtual AbstractPear *createPear();
};


void ChinaApple::getName() {
    std::cout << "china apple" << std::endl;
}

void ChinaBanana::getName() {
    std::cout << "china banana" << std::endl;
}

void ChinaPear::getName() {
    std::cout << "china pear" << std::endl;
}

void AmericaApple::getName() {
    std::cout << "america apple" << std::endl;
}

void AmericaBanana::getName() {
    std::cout << "america banana" << std::endl;
}

void AmericaPear::getName() {
    std::cout << "america pear" << std::endl;
}

void JapanApple::getName() {
    std::cout << "japan apple" << std::endl;
}

void JapanBanana::getName() {
    std::cout << "japan banana" << std::endl;
}

void JapanPear::getName() {
    std::cout << "japan pear" << std::endl;
}

AbstractApple *ChinaFruitFactory::createApple() {
    return new ChinaApple;
}

AbstractBanana *ChinaFruitFactory::createBanana() {
    return new ChinaBanana;
}

AbstractPear *ChinaFruitFactory::createPear() {
    return new ChinaPear;
}

AbstractApple *AmericaFruitFactory::createApple() {
    return new AmericaApple;
}

AbstractBanana *AmericaFruitFactory::createBanana() {
    return new AmericaBanana;
}

AbstractPear *AmericaFruitFactory::createPear() {
    return new AmericaPear;
}

AbstractApple *JapanFruitFactory::createApple() {
    return new JapanApple;
}

AbstractBanana *JapanFruitFactory::createBanana() {
    return new JapanBanana;
}

AbstractPear *JapanFruitFactory::createPear() {
    return new JapanPear;
}

#endif //CPP_DESIGNPATTERN_FRUIT_FACTORY_H

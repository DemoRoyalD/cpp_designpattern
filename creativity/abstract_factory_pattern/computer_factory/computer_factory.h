//
// Created by yuanxuedong on 2023/10/21.
//

#ifndef CPP_DESIGNPATTERN_COMPUTER_FACTORY_H
#define CPP_DESIGNPATTERN_COMPUTER_FACTORY_H

#include<iostream>

class AbstractDisplay {
public:
    virtual void display() = 0;
};

class AbstractMemory {
public:
    virtual void storage() = 0;
};

class AbstractCpu {
public:
    virtual void calculate() = 0;
};

class IntelDisplay : public AbstractDisplay {
public:
    void display();
};

class IntelMemory : public AbstractMemory {
public:
    void storage();
};

class IntelCpu : public AbstractCpu {
public:
    void calculate();
};


class AmdDisplay : public AbstractDisplay {
public:
    void display();
};

class AmdMemory : public AbstractMemory {
public:
    void storage();
};

class AmdCpu : public AbstractCpu {
public:
    void calculate();
};

class AbstractComputerSupplier {
public:
    virtual AbstractDisplay *createDisplay() = 0;

    virtual AbstractMemory *createMemory() = 0;

    virtual AbstractCpu *createCpu() = 0;
};

class IntelComputerSupplier : public AbstractComputerSupplier {
public:
    AbstractDisplay *createDisplay();

    AbstractMemory *createMemory();

    AbstractCpu *createCpu();
};

class AmdComputerSupplier : public AbstractComputerSupplier {
public:
    AbstractDisplay *createDisplay();

    AbstractMemory *createMemory();

    AbstractCpu *createCpu();
};

#endif //CPP_DESIGNPATTERN_COMPUTER_FACTORY_H

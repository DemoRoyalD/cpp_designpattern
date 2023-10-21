//
// Created by yuanxuedong on 2023/10/21.
//

#ifndef CPP_DESIGNPATTERN_COMPUTER_H
#define CPP_DESIGNPATTERN_COMPUTER_H

#include<iostream>

class HardDisk {
public:
    virtual void work() = 0;
};

class Memory {
public:
    virtual void work() = 0;
};

class CPU {
public:
    virtual void work() = 0;
};

class Computer {
public:
    Computer(CPU *cpu, Memory *mem, HardDisk *disk) {
        this->cpu = cpu;
        this->memory = mem;
        this->hardDisk = disk;
    }

    void work() {
        this->cpu->work();
        this->memory->work();
        this->hardDisk->work();
    }

private:
    CPU *cpu = NULL;
    Memory *memory = NULL;
    HardDisk *hardDisk = NULL;
};

#endif //CPP_DESIGNPATTERN_COMPUTER_H

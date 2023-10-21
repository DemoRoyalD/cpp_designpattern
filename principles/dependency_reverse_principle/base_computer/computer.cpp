//
// Created by yuanxuedong on 2023/10/21.
//

#include "computer.h"

class IntelCPU : public CPU {
public:
    virtual void work() {
        std::cout << "intel cpu is working " << std::endl;
    }
};

class IntelMemory : public Memory {
public:
    virtual void work() {
        std::cout << "intel mem is working " << std::endl;
    }
};

class IntelHardDisk : public HardDisk {
public:
    virtual void work() {
        std::cout << "intel disk is working " << std::endl;
    }
};


class AmdCPU : public CPU {
public:
    virtual void work() {
        std::cout << "Amd cpu is working " << std::endl;
    }
};

class AmdMemory : public Memory {
public:
    virtual void work() {
        std::cout << "intel mem is working " << std::endl;
    }
};

class AmdHardDisk : public HardDisk {
public:
    virtual void work() {
        std::cout << "intel disk is working " << std::endl;
    }
};
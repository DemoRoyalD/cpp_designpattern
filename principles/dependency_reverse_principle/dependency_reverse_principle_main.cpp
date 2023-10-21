//
// Created by yuanxuedong on 2023/10/21.
//

#include "dependency_reverse_principle_main.h"
#include "computer.h"
#include "computer.cpp"

int main() {
    CPU *cpu = new IntelCPU;
    Memory *memory = new IntelMemory;
    HardDisk *disk = new IntelHardDisk;

    Computer *myComputer = new Computer(cpu, memory, disk);

    myComputer->work();

    delete cpu;
    delete memory;
    delete disk;
    delete myComputer;
    return 0;
}

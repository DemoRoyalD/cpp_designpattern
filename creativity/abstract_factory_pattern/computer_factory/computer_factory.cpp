//
// Created by yuanxuedong on 2023/10/21.
//

#include "computer_factory.h"

void IntelDisplay::display() {
    std::cout << "intel display" << std::endl;
}

void IntelMemory::storage() {
    std::cout << "intel memory" << std::endl;
}

void IntelCpu::calculate() {
    std::cout << "intel cpu" << std::endl;
}

void AmdDisplay::display() {
    std::cout << "amd display" << std::endl;
}

void AmdMemory::storage() {
    std::cout << "amd memory" << std::endl;
}

void AmdCpu::calculate() {
    std::cout << "amd cpu" << std::endl;
}

AbstractDisplay *IntelComputerSupplier::createDisplay() {
    return new IntelDisplay;
}

AbstractMemory *IntelComputerSupplier::createMemory() {
    return new IntelMemory;
}

AbstractCpu *IntelComputerSupplier::createCpu() {
    return new IntelCpu;
}

AbstractDisplay *AmdComputerSupplier::createDisplay() {
    return new AmdDisplay;
}

AbstractMemory *AmdComputerSupplier::createMemory() {
    return new AmdMemory;
}

AbstractCpu *AmdComputerSupplier::createCpu() {
    return new AmdCpu;
}

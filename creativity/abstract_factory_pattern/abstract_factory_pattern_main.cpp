//
// Created by yuanxuedong on 2023/10/21.
//

#include "abstract_factory_pattern_main.h"
#include "fruit_factory.h"
#include "computer_factory.h"

int main() {
    AbstractApple *apple = NULL;
    AbstractBanana *banana = NULL;
    AbstractPear *pear = NULL;

    AbstractFruitFactory *factory = NULL;

    factory = new ChinaFruitFactory;

    apple = factory->createApple();
    banana = factory->createBanana();
    pear = factory->createPear();

    apple->getName();
    banana->getName();
    pear->getName();

    delete apple;
    delete banana;
    delete pear;

    AbstractDisplay *display = NULL;
    AbstractMemory *memory = NULL;
    AbstractCpu *cpu = NULL;

    AbstractComputerSupplier *supplier = NULL;

    supplier = new IntelComputerSupplier;
    display = supplier->createDisplay();
    memory = supplier->createMemory();
    cpu = supplier->createCpu();

    display->display();
    memory->storage();
    cpu->calculate();

    delete display;
    delete memory;
    delete cpu;

    return 0;
}
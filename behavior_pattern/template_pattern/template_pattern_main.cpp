//
// Created by yuanxuedong on 2023/10/21.
//

#include "template_pattern_main.h"
#include<iostream>

class Beverage {
public:
    void BoilWater() {
        std::cout << "boil water" << std::endl;
    }

    virtual void Brew() = 0;

    void PourInCup() {
        std::cout << "pour in cup" << std::endl;
    }

    virtual void AddCondiments() = 0;

    virtual bool CustomWantCondiments() {
        return true;
    }

    void PrepareBeverage() {
        BoilWater();
        Brew();
        PourInCup();
        if (CustomWantCondiments()) {
            AddCondiments();
        }
    }
};

class Coffee : public Beverage {
public:
    virtual void Brew() {
        std::cout << "brew coffee bean" << std::endl;
    }

    virtual void AddCondiments() {
        std::cout << "add sugar and milk " << std::endl;
    }
};

int main() {
    Beverage *coffee = new Coffee;
    coffee->PrepareBeverage();
    delete coffee;
    return 0;
}
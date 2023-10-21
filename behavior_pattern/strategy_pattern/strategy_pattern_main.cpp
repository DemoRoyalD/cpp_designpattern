//
// Created by yuanxuedong on 2023/10/21.
//

#include "strategy_pattern_main.h"
#include<iostream>

class WeaponStrategy {
public:
    virtual void useWeapon() = 0;
};

class AK47 : public WeaponStrategy {
public:
    virtual void useWeapon() {
        std::cout << "use ak47 to shoot" << std::endl;
    }
};

class Knife : public WeaponStrategy {
public:
    virtual void useWeapon() {
        std::cout << "use knife to shoot" << std::endl;
    }
};

/**
 * like context
 */
class Character {
public:
    void setWeapon(WeaponStrategy *strategy) {
        this->strategy = strategy;
    }

    void flight() {
        this->strategy->useWeapon();
    }

private:
    WeaponStrategy *strategy;
};

class CharacterKnife {
public:
    void flight() {
        knife.useWeapon();
    }

private:
    Knife knife;
};

class CharacterAK47 {
public:
    void flight() {
        ak47.useWeapon();
    }

private:
    AK47 ak47;
};

int main() {
    /**
     * not use strategy
     */
    CharacterKnife *c1 = new CharacterKnife;
    c1->flight();
    delete c1;

    CharacterAK47 *c2 = new CharacterAK47;
    c2->flight();
    delete c2;

    /**
     * use strategy
     */
    WeaponStrategy *strategy = nullptr;
    Character *c = new Character;
    strategy = new Knife;
    c->setWeapon(strategy);
    c->flight();
    delete strategy;

    strategy = new AK47;
    c->setWeapon(strategy);
    c->flight();
    delete strategy;

    delete c;
    return 0;
}
//
// Created by yuanxuedong on 2023/10/21.
//

#include "decorator_pattern_main.h"
#include<iostream>
#include<string>

class Phone {
public:
    virtual void show() = 0;
};

class Iphone : public Phone {
public:
    Iphone(std::string kind) {
        this->kind = kind;
    }

    virtual void show() {
        std::cout << "show iphone" << kind << ":" << std::endl;
    }

private:
    std::string kind;
};

class MiPhone : public Phone {
public:
    MiPhone(std::string kind) {
        this->kind = kind;
    }

    virtual void show() {
        std::cout << "show mi-" << this->kind << ":" << std::endl;
    }

private:
    std::string kind;
};

class DecoratorPhone : public Phone {
public:
    DecoratorPhone(){}
    DecoratorPhone(Phone *phone) {
        this->phone = phone;
    }

    virtual void show() {
        this->phone->show();
    }

private:
    Phone *phone;
};

class DecoratorPhoneMo : public DecoratorPhone {
public:
    DecoratorPhoneMo(Phone *phone) {
        this->phone = phone;
    }

    virtual void show() {
        this->phone->show();
        AddMo();
    }

    void AddMo() {
        std::cout << "decorator: phone mask " << std::endl;
    }

private:
    Phone *phone;
};

class DecoratorPhoneWrapper : public DecoratorPhone {
public:
    DecoratorPhoneWrapper(Phone *phone) {
        this->phone = phone;
    }

    virtual void show() {
        this->phone->show();
        AddWrapper();
    }

    void AddWrapper() {
        std::cout << "decorator: phone wrapper " << std::endl;
    }

private:
    Phone *phone;
};

int main() {
    Phone *phone = nullptr;
    DecoratorPhone *hasMoPhone = nullptr;
    DecoratorPhone *hasWrapPhone = nullptr;
    phone = new Iphone("6 plus");
    hasMoPhone = new DecoratorPhone(phone);
    hasWrapPhone = new DecoratorPhoneWrapper(phone);
    hasWrapPhone->show();
    return 0;
}
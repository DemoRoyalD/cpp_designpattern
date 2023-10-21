//
// Created by yuanxuedong on 2023/10/21.
//

#include "proxy_pattern_main.h"


#include<iostream>
#include<string>

class Item {
public:
    Item(std::string kind, bool fact) {
        this->kind = kind;
        this->fact = fact;
    }

    std::string kind;
    bool fact;
};

class Shopping {
public:
    virtual void buy(Item &item) = 0;
};

class KoreaShopping : public Shopping {
public:
    virtual void buy(Item &item) {
        std::cout << " go to korea shopping" << std::endl;
    }
};

class AmericaShopping : public Shopping {
public:
    virtual void buy(Item &item) {
        std::cout << " go to america shopping" << std::endl;
    }
};

class FranceShopping : public Shopping {
public:
    virtual void buy(Item &item) {
        std::cout << " go to france shopping" << std::endl;
    }
};

class OverseasProxy : public Shopping {
public:
    OverseasProxy(Shopping *shopping) {
        this->shopMode = shopping;
    }

    ~OverseasProxy() {
        delete this->shopMode;
    }

    virtual void buy(Item &item) {
        if (distinguish(item)) {
            this->shopMode->buy(item);
            check(item);
        } else {
            std::cout << " find [" << item.kind << "] is fake thing, can't buy" << std::endl;
        }
    }

    bool distinguish(Item &item) {
        std::cout << "scan product [" << item.kind << "] distinguish" << std::endl;
        return item.fact;
    }

    void check(Item &item) {
        std::cout << "Go through customs security and bring it back to china" << std::endl;
    }

private:
    Shopping *shopMode;
};

int main() {
    Item t1("iphone", true);
    Item t2("CET4 certificate", false);
    Shopping *shopping = nullptr;
    OverseasProxy *proxy = nullptr;
    proxy = new OverseasProxy(new KoreaShopping);
    proxy->buy(t1);
    proxy->buy(t2);
    delete proxy;

    return 0;
}

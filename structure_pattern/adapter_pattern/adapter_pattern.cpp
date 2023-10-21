//
// Created by yuanxuedong on 2023/10/21.
//

#include "adapter_pattern.h"
#include<iostream>

//target
class V5 {
public:
    virtual void useV5() = 0;
};

// Adaptee
class V220 {
public:
    virtual void use220() {
        std::cout << "use 220 elastic to charge" << std::endl;
    }
};


// Adapter
class ChargerAdapter : public V5 {
public:
    virtual void useV5() {
        std::cout << "running adapter" << std::endl;
        p220v.use220();
    }

private:
    V220 p220v;
};

class Phone {
public:
    Phone() {
        v5Adapter = new ChargerAdapter;
    }

    ~Phone() {
        if (v5Adapter != nullptr) {
            delete v5Adapter;
        }
    }

    void charge() {
        std::cout << "running charge" << std::endl;
        v5Adapter->useV5();
    }

private:
    V5 *v5Adapter;
};

int main() {
    Phone iphone;
    iphone.charge();
    return 0;
}
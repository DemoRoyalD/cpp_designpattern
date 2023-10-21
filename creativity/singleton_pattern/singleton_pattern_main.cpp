//
// Created by yuanxuedong on 2023/10/21.
//

#include "singleton_pattern_main.h"
#include<iostream>

/**
 * 懒汉模式
 */
class Singleton {
public:
    static Singleton *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton;
        }
        constructCount++;
        return instance;
    }

    int getConstructCount() {
        return constructCount;
    }

private:
    Singleton() {
        instance = nullptr;
        constructCount = 0;
        std::cout << "constructor can't execute" << std::endl;
    }

    static Singleton *instance;
    static int constructCount;
};

/**
 * 静态变量初始化，要放到类的外部
 */
Singleton *Singleton::instance = NULL;
int Singleton::constructCount = 0;

/**
 * 饿汉模式
 */
class Singleton2 {
public:
    static Singleton2 *getInstance() {
        return instance;
    }

    int getConstructCount() {
        return constructCount;
    }

private:
    Singleton2() {
        instance = NULL;
        constructCount = 0;
    }

    static Singleton2 *instance;
    static int constructCount;
};

Singleton2 *Singleton2::instance = NULL;
int Singleton2::constructCount = 0;

int main() {
    Singleton *instance1 = Singleton::getInstance();
    std::cout << instance1->getConstructCount() << std::endl;
    Singleton *instance2 = Singleton::getInstance();
    std::cout << instance2->getConstructCount() << std::endl;

    Singleton2 *instance3 = Singleton2::getInstance();
    std::cout << instance3->getConstructCount() << std::endl;
    Singleton2 *instance4 = Singleton2::getInstance();
    std::cout << instance4->getConstructCount() << std::endl;
}
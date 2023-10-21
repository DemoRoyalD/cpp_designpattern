//
// Created by yuanxuedong on 2023/10/21.
//

#include "bank_work.h"
#include <iostream>


class SaveBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        std::cout << "save money" << std::endl;
    }
};

class TransBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        std::cout << "trans money" << std::endl;
    }
};


class PayBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        std::cout << "pay money" << std::endl;
    }
};

class FundBankWorker : public AbstractBankWorker {
public:
    virtual void doBusiness() {
        std::cout << "fund money" << std::endl;
    }
};
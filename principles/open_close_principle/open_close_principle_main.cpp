//
// Created by yuanxuedong on 2023/10/21.
//

#include "open_close_principle_main.h"
#include "bank_work.h"
#include "bank_work.cpp"
#include<iostream>


int main() {
    AbstractBankWorker *abw = NULL;
    abw = new SaveBankWorker;
    abw->doBusiness();
    delete abw;
    abw = NULL;

    abw = new TransBankWorker;
    abw->doBusiness();
    delete abw;
    abw = NULL;

    abw = new PayBankWorker;
    abw->doBusiness();
    delete abw;
    abw = NULL;

    abw = new FundBankWorker;
    abw->doBusiness();
    delete abw;
    abw = NULL;
}
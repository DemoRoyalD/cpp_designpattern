//
// Created by yuanxuedong on 2023/10/21.
//

#include "iterator_pattern_main.h"
#include<iostream>
#include<list>

typedef int Object;
#define SIZE 5

class AbstractIterator {
public:
    virtual void First() = 0;

    virtual void Next() = 0;

    virtual bool isDone() = 0;

    virtual Object currentItem() = 0;
};

class AbstractObjectList {
public:
    virtual AbstractIterator *CreateIterator() = 0;

    virtual Object getItem(int index) = 0;

    virtual int getSize() = 0;
};

class ProductIterator : public AbstractIterator {
public:
    ProductIterator(AbstractObjectList *list) {
        this->list = list;
        index = 0;
    }

    ~ProductIterator() {
        this->list = nullptr;
        this->index = 0;
    }

    virtual void First() {
        this->index = 0;
    }

    virtual void Next() {
        if (this->index < list->getSize()) {
            this->index++;
        }
    }

    virtual bool isDone() {
        return this->index == list->getSize();
    }

    virtual Object currentItem() {
        return list->getItem(index);
    }

private:
    int index;
    AbstractObjectList *list;
};


class ProductList : public AbstractObjectList {
public:
    ProductList() {
        for (int i = 0; i < SIZE; ++i) {
            objects[i] = 100 + i;
        }
    }

    virtual Object getItem(int index) {
        return objects[index];
    }

    virtual int getSize() {
        return SIZE;
    }

    virtual AbstractIterator *CreateIterator() {
        return new ProductIterator(this);
    }

private:
    Object objects[SIZE];
};

int main() {
    AbstractObjectList *p_list = nullptr;
    p_list = new ProductList;
    AbstractIterator *it = p_list->CreateIterator();
    for (it->First(); !(it->isDone()); it->Next()) {
        std::cout << it->currentItem() << " ";
    }
    std::cout << std::endl;

    delete it;
    delete p_list;
    return 0;
}

//
// Created by yuanxuedong on 2023/10/21.
//

#include "compose_pattern.h"
#include<iostream>
#include<list>

// Component
class IFile {
public:
    virtual void display() = 0;

    virtual int add(IFile *file) = 0;

    virtual int remove(IFile *file) = 0;

    virtual std::list<IFile *> *getChild() = 0;
};

// Leaf
class File : public IFile {
public:
    File(std::string name) {
        this->name = name;
    }

    virtual void display() {
        std::cout << this->name << std::endl;
    }

    virtual int add(IFile *ifile) {
        return -1;
    }

    virtual int remove(IFile *ifile) {
        return -1;
    }

    virtual std::list<IFile *> *getChild() {
        return nullptr;
    }

private:
    std::string name;
};

// Composite
class Folder : public IFile {
public:
    Folder(std::string name) {
        this->name = name;
        this->m_list = new std::list<IFile *>;
    }

    ~Folder() {
        if (m_list != nullptr) {
            delete m_list;
        }
    }

    virtual void display() {
        std::cout << this->name << std::endl;
    }

    virtual int add(IFile *ifile) {
        this->m_list->push_back(ifile);
        return 0;
    }

    virtual int remove(IFile *ifile) {
        this->m_list->remove(ifile);
        return 0;
    }

    virtual std::list<IFile *> *getChild() {
        return this->m_list;
    }

private:
    std::string name;
    std::list<IFile *> *m_list;
};

void printDeep(int level) {
    for (int i = 0; i < level; ++i) {
        std::cout << "    ";
    }
}

void showTree(IFile *root, int level) {
    std::list<IFile *> *i_list = nullptr;
    printDeep(level);
    root->display();

    i_list = root->getChild();

    if (i_list != nullptr) {
        for (std::list<IFile *>::iterator it = i_list->begin(); it != i_list->end(); it++) {
            if ((*it)->getChild() == nullptr) {
                printDeep(level + 1);
                (*it)->display();
            } else {
                showTree((*it), level + 1);
            }
        }
    }
}

int main() {
    IFile *root, *image_dir, *txt_dir, *img1, *img2, *txt1, *txt2;
    root = new Folder("/");
    image_dir = new Folder("image_dir");
    txt_dir = new Folder("txt_dir");
    img1 = new File("img1");
    img2 = new File("img2");
    txt1 = new File("txt1");
    txt2 = new File("txt2");
    root->add(image_dir);
    root->add(txt_dir);
    image_dir->add(img1);
    image_dir->add(img2);
    txt_dir->add(txt1);
    txt_dir->add(txt2);
    showTree(root, 0);

    delete txt1;
    delete txt2;
    delete img1;
    delete img2;
    delete txt_dir;
    delete image_dir;
    delete root;
    return 0;
}




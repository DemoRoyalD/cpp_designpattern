//
// Created by yuanxuedong on 2023/10/21.
//

#include "observer_pattern_main.h"
#include <iostream>
#include<list>

class TeacherListener {
public:
    /**
     * when teach coming, show do action
     */
    virtual void onTeacherComing() = 0;

    virtual void doBadTing() = 0;

    virtual void stopBadTing() = 0;
};


class Student : public TeacherListener {
public:
    Student(std::string name, std::string badthing) {
        this->name = name;
        this->badthing = badthing;
    }

    virtual void onTeacherComing() {
        stopBadTing();
    }

    virtual void doBadTing() {
        std::cout << this->name << ", do " << this->badthing << std::endl;
    }

    virtual void stopBadTing() {
        std::cout << this->name << ", stop " << this->badthing << std::endl;
    }

private:
    std::string name;
    std::string badthing;
};

class INotifier {
public:
    virtual void addListener(TeacherListener *listener) = 0;

    virtual void removeListener(TeacherListener *listener) = 0;

    virtual void notify() = 0;
};

class Monitor : public INotifier {
public:
    virtual void addListener(TeacherListener *listener) {
        this->m_list.push_back(listener);
    }

    virtual void removeListener(TeacherListener *listener) {
        this->m_list.remove(listener);
    }

    virtual void notify() {
        std::list<TeacherListener *>::iterator it = m_list.begin();
        for (; it != m_list.end(); it++) {
            (*it)->onTeacherComing();
        }
    }

private:
    std::list<TeacherListener *> m_list;
};


int main() {
    Monitor monitor;
    Student trump("trump", "copy homework");
    Student alice("alice", "read novel");
    monitor.addListener(&trump);
    monitor.addListener(&alice);

    trump.doBadTing();
    alice.doBadTing();

    std::cout << "teacher is coming " << std::endl;
    monitor.notify();

    return 0;
}
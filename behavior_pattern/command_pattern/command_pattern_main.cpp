//
// Created by yuanxuedong on 2023/10/21.
//

#include "command_pattern_main.h"
#include<iostream>
#include<list>

class Doctor {
public:
    void treat_eye() {
        std::cout << "docker treat eye diseases" << std::endl;
    }

    void treat_nose() {
        std::cout << "docker treat nose diseases" << std::endl;
    }
};

class Command {
public:
    Command(Doctor *doctor) {
        this->doctor = doctor;
    }

    virtual void treat() = 0;

protected:
    Doctor *doctor;
};

class CommandTreatEye : public Command {
public:
    CommandTreatEye(Doctor *doctor) : Command(doctor) {}

    virtual void treat() {
        doctor->treat_eye();
    }
};

class CommandTreatNose : public Command {
public:
    CommandTreatNose(Doctor *doctor) : Command(doctor) {}

    virtual void treat() {
        doctor->treat_nose();
    }
};

class Nurse {
public:
    Nurse(Command *command) {
        this->command = command;
    }

    void Notify() {
        this->command->treat();
    }

private:
    Command *command;
};

class AdvNurse {
public:
    AdvNurse() {
        cmd_list.clear();
    }

    void setCommand(Command *cmd) {
        cmd_list.push_back(cmd);
    }

    void Notify() {
        for (std::list<Command *>::iterator it = cmd_list.begin(); it != cmd_list.end(); it++) {
            (*it)->treat();
        }
    }

private:
    std::list<Command *> cmd_list;
};

int main() {
    Doctor *doctor = new Doctor;
    Command *cmd1 = new CommandTreatEye(doctor);
    Command *cmd2 = new CommandTreatNose(doctor);
    AdvNurse *advNurse = new AdvNurse;

    advNurse->setCommand(cmd1);
    advNurse->setCommand(cmd2);
    advNurse->Notify();

    delete advNurse;
    delete cmd1;
    delete cmd2;
    delete doctor;
    return 0;
}


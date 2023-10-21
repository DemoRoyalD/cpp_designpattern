//
// Created by yuanxuedong on 2023/10/21.
//

#include "facade_patter_main.h"
#include<iostream>

class Switch {
public:
    virtual void On() = 0;

    virtual void Off() = 0;
};

class DvdPlay : public Switch {
public:
    void On() {
        std::cout << "open dvd play" << std::endl;
    }

    void Off() {
        std::cout << "off dvd play" << std::endl;
    }
};

class VoicePlay : public Switch {
public:
    void On() {
        std::cout << "on voice box" << std::endl;
    }

    void Off() {
        std::cout << "off voice box" << std::endl;
    }
};

class VoiceBox : public Switch {
public:
    void On() {
        std::cout << "on voice box" << std::endl;
    }

    void Off() {
        std::cout << "off voice box" << std::endl;
    }
};

class Microphone : public Switch {
public:
    void On() {
        std::cout << "on microphone" << std::endl;
    }

    void Off() {
        std::cout << "off microphone" << std::endl;
    }
};

class Light : public Switch {
public:
    void On() {
        std::cout << "on light" << std::endl;
    }

    void Off() {
        std::cout << "off light" << std::endl;
    }
};

class HomePlayFacade {
public:
    void DoFilm() {
        std::cout << "welcome to acknowledge home, look film mode" << std::endl;
        light.Off();
        microphone.On();
        voiceBox.On();
    }

    void Rest() {
        std::cout << "welcome to acknowledge home, look film mode" << std::endl;
        light.On();
        microphone.Off();
        voiceBox.Off();
    }

private:
    DvdPlay dvdPlay;
    VoicePlay voicePlay;
    VoiceBox voiceBox;
    Microphone microphone;
    Light light;
};

int main() {
    HomePlayFacade home;
    home.DoFilm();
    home.Rest();
    return 0;
}

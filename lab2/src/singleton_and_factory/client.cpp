#include "singleton.hpp"

WorldWideWeb *WorldWideWeb::instance = NULL;

int main(){
    WorldWideWeb *www = WorldWideWeb::getInstance();
    Factory factory;
    PhoneFactory phonef("iphone");
    PCFactory pcf("gaming pc");
    for(int i = 0; i < 3; i++){
        www->connectDevice(factory.createDevice());
        www->connectDevice(phonef.createDevice());
        www->connectDevice(pcf.createDevice());
    }
    www->pingDevices();
}
#include "abstract_factory.hpp"

int main(){
    GamingDeviceFactory gamingDevFactory;
    GamingPhone *gamingphone = gamingDevFactory.getPhone();
    GamingDesktopComputer *gamingcomputer = gamingDevFactory.getDesktopComputer();
    GamingLaptop *gaminglaptop = gamingDevFactory.getLaptop();
    return 0;
}
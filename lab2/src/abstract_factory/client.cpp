#include "abstract_factory.hpp"

int main(){
    DeviceFactory *gamingDevFactory = new WorkDeviceFactory();
    Phone *gamingphone = gamingDevFactory->getPhone();
    // GamingDesktopComputer *gamingcomputer = (GamingDesktopComputer *) gamingDevFactory->getDesktopComputer();
    // GamingLaptop *gaminglaptop = (GamingLaptop *) gamingDevFactory->getLaptop();
    return 0;
}
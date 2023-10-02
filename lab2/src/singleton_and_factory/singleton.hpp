#include "factory.hpp"

class WorldWideWeb{
    protected:
        Device *connectedDevices[100];
        int devicesAmm;
        static WorldWideWeb *instance;
        WorldWideWeb(){
            devicesAmm = 0;
        }
    public:
        static WorldWideWeb *getInstance(){
            if(instance == nullptr){
                instance = new WorldWideWeb();
                return instance;
            }else{
                return instance;
            }
        }
        void connectDevice(Device *device){
            if(devicesAmm == 100)
                cout << "Too many connected devices\n";
            else
                connectedDevices[devicesAmm++] = device;
        }
        void pingDevices(){
            for(int i = 0; i < devicesAmm; i++){
                connectedDevices[i]->respondToPing();
            }
        }
};
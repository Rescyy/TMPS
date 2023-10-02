#include <iostream>
using namespace std;

class Device{
    protected:
        string device_name;
    public:
        virtual void respondToPing(){
            cout << "This is a device\n";
        }
};

class Phone : public Device{
    public:
        Phone(string _device_name){
            device_name = _device_name;
        }
        void respondToPing(){
            cout << "This phone is called " << device_name << "\n";
        }
};

class PC : public Device{
    public:
        PC(string _device_name){
            device_name = _device_name;
        }
        void respondToPing(){
            cout << "This PC is called " << device_name << "\n";
        }        
};

class Factory{
    public:
        Factory(){
        }
        Device *createDevice(){
            return new Device();
        }
};

class PhoneFactory : public Factory{
    private:
        string device_names;
    public:
        PhoneFactory(string _device_names){
            device_names = _device_names;
        }
        Phone *createDevice(){
            return new Phone(device_names);
        }
};

class PCFactory : public Factory{
    private:
        string device_names;
    public:
        PCFactory(string _device_names){
            device_names = _device_names;
        }
        PC *createDevice(){
            return new PC(device_names);
        }
};
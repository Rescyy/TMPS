// device factory, Gaming, Work, Personal, Desktop Computer, Laptop, Phone, 
#include <iostream>
using namespace std;

class DesktopComputer{
    protected:
        int state;
    public:
        DesktopComputer(){
            state = 0;
        }
        void turnOnDesktopComputer(){
            state = 1;
            cout << "Computer turned on\n";
        }
        void turnOffDesktopComputer(){
            state = 0;
            cout << "Computer turned off\n";
        }
};

class GamingDesktopComputer : public DesktopComputer{
    public:
        void playDota2(){
            if(state == 1){
                cout << "Dota2 played\n";
            }else{
                cout << "Turn on the computer first\n";
            }
        }
};

class PersonalDesktopComputer : public DesktopComputer{
    public:
        void storeFamilyPhotos(){
            if(state == 1){
                cout << "Family photos stored\n";
            }else{
                cout << "Turn on the computer first\n";
            }
        }
};

class WorkDesktopComputer : public DesktopComputer{
    public:
        void code(){
            if(state == 1){
                cout << "Coding session went well, boss is happy\n";
            }else{
                cout << "Turn on the computer, or boss will be angry\n";
            }
        }
};

class Phone{
    public:
        void callGrandma(){
            cout << "Grandma called\n";
        }
};

class GamingPhone : public Phone{
    public:
        void callGrandma(){
            cout << "Too busy to call grandma, must play Subway Surfers\n";
        }
};

class PersonalPhone : public Phone{
    public:
        void callGrandma(){
            cout << "Too busy to call grandma, must watch TikTok\n";
        }
};

class WorkPhone : public Phone{
    public:
        void callGrandma(){
            cout << "Can't use phone to call grandma, boss will kill me\n";
        }
};

class Laptop{
    public:
        void carryAround();
};

class GamingLaptop : public Laptop{
    public:
        void carryAround(){
            cout << "This is pretty heavy to carry\n";
        }
};

class PersonalLaptop : public Laptop{
    public:
        void carryAround(){
            cout << "This is pretty easy to carry\n";
        }
};

class WorkLaptop : public Laptop{
    public:
        void carryAround(){
            cout << "Can't steal company's property\n";
        }
};

class DeviceFactory{
    public:
        virtual DesktopComputer *getDesktopComputer() = 0;
        virtual Laptop *getLaptop() = 0;
        virtual Phone *getPhone() = 0;
};

class GamingDeviceFactory : public DeviceFactory{
    public:
        GamingDesktopComputer *getDesktopComputer(){
            return new GamingDesktopComputer();
        };
        GamingLaptop *getLaptop(){
            return new GamingLaptop();
        };
        GamingPhone *getPhone(){
            cout << "Gaming phone\n";
            return new GamingPhone();
        };
};

class WorkDeviceFactory : public DeviceFactory{
    public:
        WorkDesktopComputer *getDesktopComputer(){
            return new WorkDesktopComputer();
        }
        WorkLaptop *getLaptop(){
            return new WorkLaptop();
        }
        WorkPhone *getPhone(){
            cout << "work phone";
            return new WorkPhone();
        }
};

class PersonalDeviceFactory : public DeviceFactory{
    public:
        PersonalDesktopComputer *getDesktopComputer(){
            return new PersonalDesktopComputer();
        }
        PersonalLaptop *getLaptop(){
            return new PersonalLaptop();
        }
        PersonalPhone *getPhone(){
            return new PersonalPhone();
        }
};
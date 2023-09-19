#include "programinterface.hpp"

class Device{
    protected:
        ProgramInterface *prg;
    public:
        void perform_program(){
            prg->execute();
        }
};

class Computer : public Device{
    public:
        Computer(ProgramInterface *program){
            prg = program;
        }
        void install_software(ProgramInterface *program){
            prg = program;
        }
};

class PhoneInterface{
    public:
        void call_grandma();
        void call_mom();
};

class Phone : public Device, public PhoneInterface{
    public:
        Phone(ProgramInterface *program){
            prg = program;
        }
        void call_grandma(){
            std::cout << "###   This number is busy   ###\n";
            std::cout << "### Please try again later. ###\n";
        }
        void call_mom(){
            std::cout << "### This number does not exist ###\n";
        }
};
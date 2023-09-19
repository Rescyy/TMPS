#include <iostream>
using namespace std;

class ProgramInterface{
    public:
        virtual void execute() = 0;
};

class AddingProgram : public ProgramInterface{
    private:
        std::string intro = "Adding Program\nPlease Input 2 Integers\n";
        std::string outro = "Your result is:\n";
    public:
        void execute(){
            int a, b;
            cout << intro;
            cin >> a >> b;
            cout << outro << a + b << "\n";
        }
};

class HelloWorldProgram : public ProgramInterface{
    private:
        string message = "Hello World!";
    public:
        void execute(){
            std::cout << message;
        }
};
#include <iostream>
using namespace std;

class ProgramInterface{
    public:
        void execute(){
            std::cout << "Code executed succesfully";
        };
};

class AddingProgram : public ProgramInterface{
    private:
        std::string intro;
        std::string outro;
    public:
        AddingProgram(string _intro, string _outro){
            intro = _intro;
            outro = _outro;
        };
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
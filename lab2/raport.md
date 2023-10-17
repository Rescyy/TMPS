# Topic: SOLID Principles


## Author: Crucerescu Vladislav

----

## Objectives:

&ensp; &ensp; __1. Study and understand the SOLID Principles.__

&ensp; &ensp; __2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.__

&ensp; &ensp;__3. Create a sample project that respects SOLID Principles.__ 

## Implementation

* __Factory__ - 
* __Abstract Factory__
* __Builder__
* __Singleton__

### Single Responsibility Principle

Every Class has only one responsibility.

```
class Phone : public Device, public PhoneInterface{
    public:
        Phone(ProgramInterface program){
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
```
Here we see, the class has two methods, you might argue it has multiple responsibilites. We could create 2 additional classes called GrandmaCallerPhone and MomCallerPhone, but that would be redundant. The only responsibility this class has is that it calls people, by using PhoneInterface interface class.

### Open-Closed Principle

The class Device and its subclasses are closed for modification, because we can introduce a Program in its attributes, we are able to do whatever we want with that class with the ```execute()``` method.

```
class HelloWorldProgram : public ProgramInterface{
    private:
        string message = "Hello World!\n";
    public:
        void execute(){
            std::cout << message;
        }
};

class Device{
    protected:
        ProgramInterface prg;
    public:
        void perform_program(){
            prg.execute();
        }
};

int main(){
    HelloWorldProgram hellou;
    Device macintosh(&hellou);
    macintosh.execute();
}
```
```
OUTPUT: Hello World!
```

### Liskov's Substitution Rule

The derived classes Phone and Computer from the Device class, act exactly the same as its parent.

```
class Computer : public Device{
    public:
        Computer(ProgramInterface program, int _cpu){
            prg = program;
        }
        void install_software(ProgramInterface program){
            prg = program;
        }
};

class Phone : public Device, public PhoneInterface{
    public:
        Phone(ProgramInterface program){
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

int main(){
    HelloWorldProgram program;

    Device device(&program);
    Computer computer(&program);
    Phone phone(&program);

    device.execute();
    computer.execute();
    phone.execute();
}
```

```
OUTPUT: Hello World!
Hello World!
Hello World!
```

### Interface Segregation Principle

The computer interface does not require to call its grandma or mom, that's why there is a separate PhoneInterface class that has all the methods necessary. 

```
class PhoneInterface{
    public:
        void call_grandma();
        void call_mom();
};

class Phone : public Device, public PhoneInterface{
    public:
        Phone(ProgramInterface program){
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
```

### Dependency Inversion Principle

The Device class and its derivatives depend on the abstraction ProgramInterface and any of its derivatives.

```
class Computer : public Device{
    public:
        Computer(ProgramInterface *program){
            prg = program;
        }
        void install_software(ProgramInterface *program){
            prg = program;
        }
};

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
int main(){
    AddingProgram adding;
    HelloWorldProgram hellou;
    Computer computer(&adding);
    computer.execute();
    // adding program output
    computer.install_software(&hellou);
    computer.execute();
    // hellou program output
}
```

## Conclusions / Screenshots / Results

In this laboratory work I studied the SOLID principles and why they are so important. By producing code and testing it, I have understood this topic even more. This topic is difficult, especially because examples on the internet do not show how this all the SOLID principles should look like altogether, and there are some examples that even though respect some of the rules, they violate others. SOLID principles should be used with care, you can still write bad code with it, like my first try.
#include <iostream>
using namespace std;

typedef int (*operation)(int, int);

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mult(int a, int b){
    return a * b;
}

class Element{
    public:
        virtual ~Element() {}
        virtual void addLeft() {}
        virtual void addRight() {}
        virtual int Compute() = 0;
};

class Operation : public Element {
    protected:
        operation op;
        Element *left;
        Element *right;
    public:
        Operation(operation op_, Element *left_, Element *right_){
            op = op_;
            left = left_;
            right = right_;
        }
        int Compute(){
            return op(left->Compute(), right->Compute());
        }
};

class Integer : public Element {
    protected:
        int val;
    public:
        Integer(int val_){
            val = val_;
        }
        int Compute(){
            return val;
        }
};

void ClientCode(string str, Element *element){
    cout << str << "Result: " << element->Compute() << "\n";
}

int main(){
    Integer *a1 = new Integer(1);
    Integer *a2 = new Integer(2);
    Integer *a3 = new Integer(3);
    ClientCode("Integer ", a1);
    Operation *op1 = new Operation(add, a1, a2);
    ClientCode("Op1 ", op1);
    Operation *op2 = new Operation(sub, a1, a3);
    ClientCode("Op2 ", op2);
    Operation *composite = new Operation(mult, op1, op2);
    ClientCode("Composite ", composite);
    return 0;
}
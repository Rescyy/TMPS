#include <iostream>
using namespace std;

class OperationInterface
{
public:
    virtual float doOperation(float a, float b) const = 0;
};

class Calculator
{
private:
    OperationInterface *strategy_;

public:
    Calculator(OperationInterface *strategy) : strategy_(strategy)
    {
    }

    void set_operation(OperationInterface *strategy)
    {
        strategy_ = strategy;
    }

    void doCalculation() const
    {
        if (strategy_)
        {
            cout << "Calculator: \n";
            float result = strategy_->doOperation(12.4, 30.1);
            cout << "Result " << result << "\n";
        }
    }
};

class Addition : public OperationInterface
{
    public:
        float doOperation(float a, float b) const override
        {
            return a + b;
        }
};
class Subtraction : public OperationInterface
{
    public:
        float doOperation(float a, float b) const override
        {
            return a - b;
        }
};

void clientCode()
{
    cout << "Calculator set to adding\n";
    Calculator Calculator(new Addition());
    Calculator.doCalculation();
    cout << "\n";
    cout << "Calculator set to subtraction\n";
    Calculator.set_operation(new Subtraction());
    Calculator.doCalculation();
}

int main()
{
    clientCode();
    return 0;
}
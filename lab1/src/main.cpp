#include <iostream>
#include "devices.hpp"
using namespace std;

int main(){

    AddingProgram adding;
    Phone phone(&adding);
    phone.call_grandma();
    phone.perform_program();
    return 0;
}
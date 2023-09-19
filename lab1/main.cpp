#include <iostream>
#include "devices.hpp"
using namespace std;

int main(){

    AddingProgram adding("Adding Program\nPlease Input 2 Integers\n", "Your result is:\n");
    Phone phone(adding);
    phone.call_grandma();
    phone.perform_program();
    return 0;
}
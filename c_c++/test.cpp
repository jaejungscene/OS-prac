#include <iostream>
#include <cmath>

using namespace std;

typedef struct car{
    string brand;
    string model;
    int year;
}car;

int main(int argc, char **argv)
{
    string food = "Pizza";  // A food variable of type string
    string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

    // Output the value of food (Pizza)
    cout << food << "\n";

    // Output the memory address of food (0x6dfed4)
    cout << &food << "\n";

    // Output the memory address of food with the pointer (0x6dfed4)
    cout << ptr << "\n";

    cout << *ptr << "\n";
    cout << (*ptr)[0] << "\n";
    return 0;
}
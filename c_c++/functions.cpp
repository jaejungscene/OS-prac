/**
 * C++ support function overloading
 * site: https://www.w3schools.com/cpp/cpp_function_overloading.asp
*/

#include <iostream>
using namespace std;

void tempFuc(string param1, string param2="hello"){
    cout << param1 <<" "<< param2 <<endl;
}

int overloadFunc(int x)
{
    cout << "int x" <<endl;
    return x + 1;
}

float overloadFunc(float x)
{
    cout << "float x" <<endl;
    return x + 1.0;
}

double overloadFunc(double x)
{
    cout << "double x" <<endl;
    return x + 1.0;
}

double overloadFunc(double x, double y)
{
    cout << "double x, double y" <<endl;
    return x+y;
}

int overloadFunc(int x, int y)
{
    cout << "int x, int y" <<endl;
    return x+y;
}

int main(int argc, char** argv)
{
    tempFuc("jaejung");
    tempFuc("jaejung", "welcome");
    cout << "-----------------------\n";
    overloadFunc(1);
    overloadFunc((float)2.3);
    overloadFunc((double)2.3);
    overloadFunc(3.2, 1.1);
    overloadFunc(1, 4);
    return 0;
}
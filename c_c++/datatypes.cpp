#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int myNum = 5;               // Integer (whole number)
    float myFloatNum = 5.99;     // Floating point number
    double myDoubleNum = 9.98;   // Floating point number
    char myLetter = 'D';         // Character
    bool myBoolean = true;       // Boolean
    string myText = "Hello";     // String      <<< not a built-in type, so you must include <string> libraray

    cout << "myNum: " << myNum << ", size: " << sizeof(myNum) << endl;
    cout << "myFloatNum: " << myFloatNum << ", size: " << sizeof(myFloatNum) << endl;
    cout << "myDoubleNum: " << myDoubleNum << ", size: " << sizeof(myDoubleNum) << endl;
    cout << "myLetter: " << myLetter << ", size: " << sizeof(myLetter) << endl;
    cout << "myBoolean: " << myBoolean << ", size: " << sizeof(myBoolean) << endl;
    cout << "myText: " << myText << ", size: " << myText.size() << endl;
    return 0;
}
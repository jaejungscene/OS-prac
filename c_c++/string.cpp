// #include <string>
#include <iostream>
using namespace std;

/**
 * "string" type is bring from namespace std
*/

int main(int argc, char **argv)
{
    string first = "jaejung";
    string last = "lee";
    string full = first + " " + last;
    cout << full << endl;

    cout << first[1] << endl;
    cout << "------------------------------" << endl;

    cout << first[-1] << endl;
    cout << "hello" << endl;
    return 0;
}
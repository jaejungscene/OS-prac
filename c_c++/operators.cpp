#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int x = 12;
    int temp;

    temp = x|5;
    cout << temp << endl; // 13

    temp = x%7;
    cout << temp << endl; // 5

    temp = x&4;
    cout << temp << endl; // 4

    temp = x^5;
    cout << temp << endl; // 9

    temp = 13>>1;
    cout << temp << endl; // 6

    temp = 13<<1;
    cout << temp << endl; // 26
    return 0;
}
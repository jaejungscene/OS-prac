#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<string> strarr;
    strarr.push_back("hello");
    strarr.push_back("world");
    
    cout << strarr[0] << endl;
    cout << strarr[1] << endl;
    return 0;
}
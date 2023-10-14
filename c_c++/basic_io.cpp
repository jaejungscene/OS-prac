#include <iostream>
#define _CONDITION

#ifdef _CONDITION
    /**
     * use "using namespace std"
    */
    using namespace std;
    int main(){
        
        int x;
        cout << "Type x: ";
        cin >> x;
        cout << "x is " << x << endl;


        string fullname;

        cout << "Type your full name: ";
        cin >> fullname; // <------------- get only one word in input stream
        cout << "fullname is " << fullname << endl;

        cout << "Type your full name: ";
        getline(cin, fullname); // <------ get line in input stream
        cout << "fullname is " << fullname << endl;
        return 0;
    }
#else
    int main(){
        int x;
        std::cin >> x;
        std::cout << "x is " << x << std::endl;
        return 0;
    }
#endif
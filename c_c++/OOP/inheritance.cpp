#include <iostream>

using namespace std;

class Vehicle{
    private:
    string privateValue = "private value";
    void privateMethod(){
        cout << "private value: "<< privateValue << " in private method()" << endl;
    }
    public:
    string brand = "Ford";
    void honk() {
        cout << "Tuut, tuut!\n";
        this->privateMethod();
    }
};

class Car: public Vehicle {
    public:
        string model = "Mustang";
};

int main(int argc, char **argv) {
    Car myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model <<endl;
    return 0;
}
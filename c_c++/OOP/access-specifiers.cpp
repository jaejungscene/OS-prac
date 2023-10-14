#include <iostream>
using namespace std;

// Base class
class Employee {
  //public:
  protected: // Protected access specifier
    int salary;
};

// Derived class
class Programmer: public Employee {
  public:
    int bonus;
    void setSalary(int s) {
      salary = s;
    }
    int getSalary() {
      return salary;
    }
};

int main() {
  Programmer myObj;
  myObj.setSalary(50000);
  myObj.bonus = 15000;
  cout << "Salary: " << myObj.getSalary() << "\n";
  cout << "Bonus: " << myObj.bonus << "\n";


  /**
   * if salary is "protected", you can not directly reach to salary,
   * but if salary is "public", you can directly reach to salary.
  */ 
  cout << "Directed access to salary: " << myObj.salary << endl; 

  return 0;
}
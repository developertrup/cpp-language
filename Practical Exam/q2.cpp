#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    float salary;
    string designation;

public:
    void setName(string n)
    {
        name = n;
    }

    void setSalary(float s)
    {
        salary = s;
    }

    void setDesignation(string d)
    {
        designation = d;
    }

    string getName()
    {
        return name;
    }

    float getSalary()
    {
        return salary;
    }

    string getDesignation()
    {
        return designation;
    }
};

int main()
{
    Employee e;

    string name, designation;
    float salary;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter salary: ";
    cin >> salary;

    cout << "Enter designation: ";
    cin >> designation;

    e.setName(name);
    e.setSalary(salary);
    e.setDesignation(designation);

    cout << "\nEmployee Details" << endl;
    cout << "Name: " << e.getName() << endl;
    cout << "Salary: " << e.getSalary() << endl;
    cout << "Designation: " << e.getDesignation() << endl;

    return 0;
}
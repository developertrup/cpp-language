#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void display()
    {
        cout << "This is a Shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void display()
    {
        cout << "This is a Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void display()
    {
        cout << "This is a Rectangle" << endl;
    }
};

int main()
{
    int choice;

    cout << "Enter 1 for Circle" << endl;
    cout << "Enter 2 for Rectangle" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    Circle c;
    Rectangle r;

    Shape *shape;

    if(choice == 1)
    {
        shape = &c;
        shape->display();
    }
    else if(choice == 2)
    {
        shape = &r;
        shape->display();
    }
    else
    {
        cout << "Invalid choice";
    }

    return 0;
}
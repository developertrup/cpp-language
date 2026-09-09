#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound() = 0;
    virtual void move() = 0;
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog says: Woof Woof" << endl;
    }

    void move()
    {
        cout << "Dog runs" << endl;
    }
};

class Bird : public Animal
{
public:
    void sound()
    {
        cout << "Bird says: Chirp Chirp" << endl;
    }

    void move()
    {
        cout << "Bird flies" << endl;
    }
};

int main()
{
    int choice;

    cout << "1. Dog" << endl;
    cout << "2. Bird" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    Dog d;
    Bird b;

    Animal *animal;

    if(choice == 1)
    {
        animal = &d;
    }
    else if(choice == 2)
    {
        animal = &b;
    }
    else
    {
        cout << "Invalid choice";
        return 0;
    }

    animal->sound();
    animal->move();

    return 0;
}
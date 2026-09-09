#include <iostream>
using namespace std;

class Shape
{
private:
    string color;

public:
    void setColor(string c)
    {
        color = c;
    }

    string getColor()
    {
        return color;
    }

    virtual void calculateArea() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void calculateArea()
    {
        cout << "Circle Area: " << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    void calculateArea()
    {
        cout << "Rectangle Area: " << length * width << endl;
    }
};

int main()
{
    float radius, length, width;
    string color1, color2;

    cout << "Enter circle radius: ";
    cin >> radius;

    cout << "Enter circle color: ";
    cin >> color1;

    cout << "Enter rectangle length: ";
    cin >> length;

    cout << "Enter rectangle width: ";
    cin >> width;

    cout << "Enter rectangle color: ";
    cin >> color2;

    Circle c(radius);
    Rectangle r(length, width);

    c.setColor(color1);
    r.setColor(color2);

    cout << "\nCircle Color: " << c.getColor() << endl;
    c.calculateArea();

    cout << "Rectangle Color: " << r.getColor() << endl;
    r.calculateArea();

    return 0;
}     
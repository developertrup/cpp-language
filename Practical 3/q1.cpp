#include <iostream>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

protected:
    // Protected getters for derived classes
    int getVehicleID()
    {
        return vehicleID;
    }

public:
    static int totalVehicles;

    // Default Constructor
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;

        totalVehicles++;
    }

    // Parameterized Constructor
    Vehicle(int id, string man, string mod, int y)
    {
        vehicleID = id;
        manufacturer = man;
        model = mod;
        year = y;

        totalVehicles++;
    }

    // Destructor
    ~Vehicle()
    {
        // Destructor
    }

    // Setters
    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string man)
    {
        manufacturer = man;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    void setYear(int y)
    {
        year = y;
    }

    // Getters
    int getID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    // Display Vehicle information
    virtual void display()
    {
        cout << "\nVehicle ID   : " << vehicleID;
        cout << "\nManufacturer : " << manufacturer;
        cout << "\nModel        : " << model;
        cout << "\nYear         : " << year;
    }
};

// Definition of static member
int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
private:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "";
    }

    Car(int id, string man, string mod, int y, string fuel)
        : Vehicle(id, man, mod, y)
    {
        fuelType = fuel;
    }

    // Setter
    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    // Getter
    string getFuelType()
    {
        return fuelType;
    }

    void display() override
    {
        Vehicle::display();
        cout << "\nFuel Type    : " << fuelType;
    }
};

class ElectricCar : public Car
{
private:
    float batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string man, string mod, int y,
                string fuel, float battery)
        : Car(id, man, mod, y, fuel)
    {
        batteryCapacity = battery;
    }

    // Setter
    void setBatteryCapacity(float battery)
    {
        batteryCapacity = battery;
    }

    // Getter
    float getBatteryCapacity()
    {
        return batteryCapacity;
    }

    void display() override
    {
        Car::display();
        cout << "\nBattery      : " << batteryCapacity << " kWh";
    }
};

class Aircraft
{
private:
    float flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(float range)
    {
        flightRange = range;
    }

    // Setter
    void setFlightRange(float range)
    {
        flightRange = range;
    }

    // Getter
    float getFlightRange()
    {
        return flightRange;
    }

    void displayAircraft()
    {
        cout << "\nFlight Range : " << flightRange << " km";
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft()
    {
    }

    FlyingCar(int id, string man, string mod, int y,
              string fuel, float range)
        : Car(id, man, mod, y, fuel),
          Aircraft(range)
    {
    }

    void display() override
    {
        Car::display();
        Aircraft::displayAircraft();
    }
};

class SportsCar : public ElectricCar
{
private:
    float topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportsCar(int id, string man, string mod, int y,
              string fuel, float battery, float speed)
        : ElectricCar(id, man, mod, y, fuel, battery)
    {
        topSpeed = speed;
    }

    // Setter
    void setTopSpeed(float speed)
    {
        topSpeed = speed;
    }

    // Getter
    float getTopSpeed()
    {
        return topSpeed;
    }

    void display() override
    {
        ElectricCar::display();
        cout << "\nTop Speed    : " << topSpeed << " km/h";
    }
};

class Sedan : public Car
{
public:
    Sedan() : Car()
    {
    }

    Sedan(int id, string man, string mod, int y, string fuel)
        : Car(id, man, mod, y, fuel)
    {
    }

    void display() override
    {
        Car::display();
        cout << "\nVehicle Type : Sedan";
    }
};

class SUV : public Car
{
public:
    SUV() : Car()
    {
    }

    SUV(int id, string man, string mod, int y, string fuel)
        : Car(id, man, mod, y, fuel)
    {
    }

    void display() override
    {
        Car::display();
        cout << "\nVehicle Type : SUV";
    }
};

class VehicleRegistry
{
private:
    // Array of Vehicle pointers
    Vehicle *vehicles[100];

    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    // Add Vehicle
    void addVehicle(Vehicle *v)
    {
        if (count < 100)
        {
            vehicles[count] = v;
            count++;

            cout << "\nVehicle added successfully!";
        }
        else
        {
            cout << "\nRegistry is full!";
        }
    }

    // Display all vehicles
    void displayAll()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles found!";
            return;
        }

        cout << "\n\n========== ALL VEHICLES ==========\n";

        for (int i = 0; i < count; i++)
        {
            cout << "\n----------------------------------";
            vehicles[i]->display();
            cout << "\n----------------------------------";
        }
    }

    // Search Vehicle by ID
    void searchVehicle(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getID() == id)
            {
                cout << "\n\nVehicle Found!";
                cout << "\n==============================";

                vehicles[i]->display();

                cout << "\n==============================";
                return;
            }
        }

        cout << "\nVehicle with ID " << id << " not found!";
    }
};

int main()
{
    VehicleRegistry registry;

    int choice;

    do
    {
        cout << "\n\n====================================";
        cout << "\n       VEHICLE REGISTRY SYSTEM";
        cout << "\n====================================";

        cout << "\n1. Add Car";
        cout << "\n2. Add Electric Car";
        cout << "\n3. Add Flying Car";
        cout << "\n4. Add Sports Car";
        cout << "\n5. Add Sedan";
        cout << "\n6. Add SUV";
        cout << "\n7. View All Vehicles";
        cout << "\n8. Search Vehicle by ID";
        cout << "\n9. Total Vehicles";
        cout << "\n0. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, year;
            string manufacturer, model, fuel;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            Car *c = new Car(id, manufacturer, model, year, fuel);

            registry.addVehicle(c);
        }

        else if (choice == 2)
        {
            int id, year;
            string manufacturer, model, fuel;
            float battery;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            ElectricCar *e = new ElectricCar(
                id, manufacturer, model, year, fuel, battery);

            registry.addVehicle(e);
        }

        else if (choice == 3)
        {
            int id, year;
            string manufacturer, model, fuel;
            float range;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            cout << "Enter Flight Range (km): ";
            cin >> range;

            FlyingCar *f = new FlyingCar(
                id, manufacturer, model, year, fuel, range);

            registry.addVehicle(f);
        }

        else if (choice == 4)
        {
            int id, year;
            string manufacturer, model, fuel;
            float battery, speed;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            cout << "Enter Top Speed (km/h): ";
            cin >> speed;

            SportsCar *s = new SportsCar(
                id, manufacturer, model, year,
                fuel, battery, speed);

            registry.addVehicle(s);
        }

        else if (choice == 5)
        {
            int id, year;
            string manufacturer, model, fuel;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            Sedan *s = new Sedan(
                id, manufacturer, model, year, fuel);

            registry.addVehicle(s);
        }

        else if (choice == 6)
        {
            int id, year;
            string manufacturer, model, fuel;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            SUV *s = new SUV(
                id, manufacturer, model, year, fuel);

            registry.addVehicle(s);
        }

        else if (choice == 7)
        {
            registry.displayAll();
        }

        else if (choice == 8)
        {
            int id;

            cout << "\nEnter Vehicle ID to search: ";
            cin >> id;

            registry.searchVehicle(id);
        }

        else if (choice == 9)
        {
            cout << "\nTotal Vehicles Created: "
                 << Vehicle::totalVehicles;
        }

        else if (choice == 0)
        {
            cout << "\nThank you for using Vehicle Registry System!";
        }

        else
        {
            cout << "\nInvalid choice!";
        }

    } while (choice != 0);

    return 0;
}
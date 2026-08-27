#include <iostream>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    // Default Constructor //
    Train()
    {
        trainNumber = 0;
        trainName[0] = '\0';
        source[0] = '\0';
        destination[0] = '\0';
        trainTime[0] = '\0';

        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, char name[], char src[], char dest[], char time[])
    {
        trainNumber = number;

        int i = 0;
        while (name[i] != '\0')
        {
            trainName[i] = name[i];
            i++;
        }
        trainName[i] = '\0';

        i = 0;
        while (src[i] != '\0')
        {
            source[i] = src[i];
            i++;
        }
        source[i] = '\0';

        i = 0;
        while (dest[i] != '\0')
        {
            destination[i] = dest[i];
            i++;
        }
        destination[i] = '\0';

        i = 0;
        while (time[i] != '\0')
        {
            trainTime[i] = time[i];
            i++;
        }
        trainTime[i] = '\0';

        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setter
    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(char name[])
    {
        int i = 0;

        while (name[i] != '\0')
        {
            trainName[i] = name[i];
            i++;
        }

        trainName[i] = '\0';
    }

    void setSource(char src[])
    {
        int i = 0;

        while (src[i] != '\0')
        {
            source[i] = src[i];
            i++;
        }

        source[i] = '\0';
    }

    void setDestination(char dest[])
    {
        int i = 0;

        while (dest[i] != '\0')
        {
            destination[i] = dest[i];
            i++;
        }

        destination[i] = '\0';
    }

    void setTrainTime(char time[])
    {
        int i = 0;

        while (time[i] != '\0')
        {
            trainTime[i] = time[i];
            i++;
        }

        trainTime[i] = '\0';
    }

    // Getters
    int getTrainNumber()
    {
        return trainNumber;
    }

    char* getTrainName()
    {
        return trainName;
    }

    char* getSource()
    {
        return source;
    }

    char* getDestination()
    {
        return destination;
    }

    char* getTrainTime()
    {
        return trainTime;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Train Details
    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    // Static Function
    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;


class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;

            cout << "Train record added successfully!" << endl;
        }
        else
        {
            cout << "No more space!" << endl;
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records found!" << endl;
        }
        else
        {
            for (int i = 0; i < totalTrains; i++)
            {
                cout << "Train " << i + 1 << " details:" << endl;

                trains[i].displayTrainDetails();

                cout << endl;
            }
        }
    }

    void searchTrainByNumber(int number)
    {
        int found = 0;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "Train " << i + 1 << " details:" << endl;

                trains[i].displayTrainDetails();

                found = 1;
            }
        }

        if (found == 0)
        {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
};


int main()
{
    RailwaySystem railway;

    int choice;
    int number;

    while (true)
    {
        cout << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            railway.addTrain();
        }
        else if (choice == 2)
        {
            railway.displayAllTrains();
        }
        else if (choice == 3)
        {
            cout << "Enter Train Number to search: ";
            cin >> number;

            railway.searchTrainByNumber(number);
        }
        else if (choice == 4)
        {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        cout << endl;
    }

    return 0;
}
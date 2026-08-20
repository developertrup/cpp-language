#include <iostream>
using namespace std;

class timeConverter {
public:
    void convertSeconds() {
        int totalSeconds;
        
        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        int hours = totalSeconds / 3600;
        totalSeconds = totalSeconds % 3600;

        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << minutes << ":"
             << seconds << endl;
    }
};

int main() {
    timeConverter t;
    t.convertSeconds();

    return 0;
}   
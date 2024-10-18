
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <conio.h>
using namespace std;


class Time {
private:
    short sec;
    short min;
    short hours;

public:
    Time(short h, short m, short s) {
        if (s >= 0 && s < 60) {
            sec = s;
        }
        else {
            std::cout << "Invalid seconds. Setting to 0.\n";
            sec = 0;
        }

        if (m >= 0 && m < 60) {
            min = m;
        }
        else {
            std::cout << "Invalid minutes. Setting to 0.\n";
            min = 0;
        }

        if (h >= 0 && h < 24) {
            hours = h;
        }
        else {
            std::cout << "Invalid hours. Setting to 0.\n";
            hours = 0;
        }

    }

        void displayTime() const
        {
            std::cout << "Time remains : "
                << (hours < 10 ? "0" : "") << hours << ":"
                << (min < 10 ? "0" : "") << min << ":"
                << (sec < 10 ? "0" : "") << sec << std::endl;
        }
        void time()
        {
            if (sec > 0)
                sec--;
            else if (min > 0)
            {
                min--;
                sec = 59;
            }
            else if (hours > 0)
            {
                hours--;
                min = 59;
                sec = 59;
            }
        }
        bool timeup()
        {
            if (sec == 0 && min == 0 && hours == 0)
                return false;
            return true;
        }
    
};

int main() {
    short hours, minutes, seconds;
    std::cout << "Enter hours (0-23): ";
    std::cin >> hours;
    std::cout << "Enter minutes (0-59): ";
    std::cin >> minutes;
    std::cout << "Enter seconds (0-59): ";
    std::cin >> seconds;

    Time t(hours, minutes, seconds);
  
        cout << "enter P to pause ";
        while (t.timeup())
        {
            t.displayTime();
            this_thread::sleep_for(chrono::seconds(1)) ;

           system("cls");
            t.time();
        }
      
    cout << "00:00:00 \n TIME IS UP ";

    return 0;
}

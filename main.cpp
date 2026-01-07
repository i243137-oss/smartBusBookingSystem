#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Person {
public:
    string name;
    int age;
    char gender;

    Person() {
        name = "";
        age = 0;
        gender = ' ';
    }
};

class Seat {
public:
    static int seatNumber;
    int seat;
    bool isBooked;
    Person bookedBy;

    Seat() {
        seat = seatNumber++;
        isBooked = false;
    }

    void printSeatInfo() {
        cout << "|";
        if (isBooked) {
            cout << " " << bookedBy.gender;
        } else {
            if (seat < 10) cout << " ";
            cout << seat;
        }
        cout << "|";
    }
};

int Seat::seatNumber = 1;

class Bus {
private:
    Seat **seats;
    static int id;

public:
    Bus() {
        seats = new Seat*[20];
        for (int i = 0; i < 20; i++) {
            seats[i] = new Seat[2];
        }
        id++;
    }

    void bookSeat(Person p, int seatNumber) {
        if (seatNumber < 1 || seatNumber > 40) {
            cout << "Invalid seat number" << endl;
            return;
        }

        int row, col;

        if (seatNumber % 2 == 0) {
            row = seatNumber / 2 - 1;
            col = 1;
        } else {
            row = seatNumber / 2;
            col = 0;
        }

        if (seats[row][col].isBooked) {
            cout << "Seat already booked!" << endl;
            return;
        }

        seats[row][col].isBooked = true;
        seats[row][col].bookedBy = p;

        cout << "Seat booked successfully!" << endl;
    }

    void displayBus() {
        cout<<"|---------------|"<<endl;
        cout<<"|               |"<<endl;
        for (int i = 0; i < 20; i++) {
            cout<<"|   ";
            for (int j = 0; j < 2; j++) {
                seats[i][j].printSeatInfo();
            }
            cout<<"    |";
            cout << endl;
        }
          cout<<"|               |"<<endl;
         cout<<"|---------------|"<<endl;
    }
};

int Bus::id = 0;

int main() {
    Bus b;

    cout << "-------------------------------------" << endl;
    cout << "Welcome to the Bus Reservation System" << endl;
    cout << "-------------------------------------" << endl;

    while (true) {
        cout << "Please Select an option:" << endl;
        cout << "1. Book a Seat" << endl;
        cout << "2. Display Bus Seats" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            Person p;
            cout << "Enter your name: ";
            cin >> p.name;
            cout << "Enter your age: ";
            cin >> p.age;
            cout << "Enter your gender (M/F): ";
            cin >> p.gender;

            int seatNumber;
            cout << "Enter seat number (1-40): ";
            cin >> seatNumber;

            b.bookSeat(p, seatNumber);
        }
        else if (choice == 2) {
            b.displayBus();
        }
        else if (choice == 3) {
            cout << "Thank you for using the Bus Reservation System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

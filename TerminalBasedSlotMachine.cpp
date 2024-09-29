#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class SlotMachine {
private:
    int balance; // user's current balance
    int bet; // current bet amount

public:
    SlotMachine(int initialBalance = 100) : balance(initialBalance), bet(0) {}

    // set the bet amount
    void setBet(int amount) {
        if (amount > 0 && amount <= balance) {
            bet = amount;
        } else {
            cout << "Invalid bet amount. Please try again." << endl;
        }
    }

    // spin the slots
    void spin() {
        srand(time(0)); // seed the random number generator
        int slot1 = rand() % 3; // generate a random number between 0 and 2
        int slot2 = rand() % 3;
        int slot3 = rand() % 3;

        cout << "Spinning..." << endl;
        cout << "Slot 1: " << getSymbol(slot1) << endl;
        cout << "Slot 2: " << getSymbol(slot2) << endl;
        cout << "Slot 3: " << getSymbol(slot3) << endl;

        if (slot1 == slot2 && slot2 == slot3) {
            cout << "Congratulations, you won!" << endl;
            balance += bet * 2; // double the bet amount
        } else {
            cout << "Sorry, you lost." << endl;
            balance -= bet;
        }

        cout << "Your current balance: $" << balance << endl;
    }

    // get a symbol based on the random number
    string getSymbol(int num) {
        switch (num) {
            case 0:
                return "Cherry";
            case 1:
                return "Seven";
            case 2:
                return "Bar";
            default:
                return "Unknown";
        }
    }

    // display the current balance
    void displayBalance() {
        cout << "Your current balance: $" << balance << endl;
    }
};

int main() {
    SlotMachine machine; // create a slot machine object

    while (true) {
        machine.displayBalance();
        cout << "Enter your bet (or 0 to quit): ";
        int bet;
        cin >> bet;
        if (bet == 0) {
            break;
        }
        machine.setBet(bet);
        machine.spin();
    }

    return 0;
}
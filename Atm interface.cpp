#include <iostream>
#include <string>
#include <map>
using namespace std;

class ATM {
private:
    map<string, double> accounts; // Account number and balance
    string currentAccount;

public:
    ATM() {
        // Sample accounts
        accounts["12345"] = 1000.0;
        accounts["67890"] = 1500.0;
    }

    bool login(const string& accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            currentAccount = accountNumber;
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Invalid account number.\n";
            return false;
        }
    }

    void checkBalance() {
        if (!currentAccount.empty()) {
            cout << "Your balance is: $" << accounts[currentAccount] << "\n";
        } else {
            cout << "Please log in first.\n";
        }
    }

    void deposit(double amount) {
        if (!currentAccount.empty() && amount > 0) {
            accounts[currentAccount] += amount;
            cout << "$" << amount << " deposited successfully.\n";
            checkBalance();
        } else {
            cout << "Invalid operation.\n";
        }
    }

    void withdraw(double amount) {
        if (!currentAccount.empty() && amount > 0 && accounts[currentAccount] >= amount) {
            accounts[currentAccount] -= amount;
            cout << "$" << amount << " withdrawn successfully.\n";
            checkBalance();
        } else {
            cout << "Invalid operation or insufficient balance.\n";
        }
    }

    void logout() {
        currentAccount.clear();
        cout << "Logged out successfully.\n";
    }
};

int main() {
    ATM atm;
    int choice;
    string accountNumber;
    double amount;

    cout << "Welcome to the ATM!\n";
    cout << "Please enter your account number: ";
    cin >> accountNumber;

    if (!atm.login(accountNumber)) {
        return 0;
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 4:
                atm.logout();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string accNum, string accHolder, double bal) {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = bal;
    }

    string getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid amount or insufficient funds." << endl;
        }
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount(string accNum, string accHolder, double initialBalance) {
        accounts.push_back(Account(accNum, accHolder, initialBalance));
        cout << "Account created successfully!" << endl;
    }

    Account* findAccount(string accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    void showAccounts() const {
        cout << "\nList of Accounts:" << endl;
        for (const auto &account : accounts) {
            cout << "Account Number: " << account.getAccountNumber() 
                 << ", Holder: " << account.getAccountHolderName() 
                 << ", Balance: " << account.getBalance() << endl;
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;
    string accNum, accHolder;
    double amount;

    do {
        cout << "\nOnline Banking System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Show All Accounts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, accHolder);
                cout << "Enter Initial Balance: ";
                cin >> amount;
                bank.createAccount(accNum, accHolder, amount);
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                if (auto acc = bank.findAccount(accNum)) {
                    acc->deposit(amount);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                if (auto acc = bank.findAccount(accNum)) {
                    acc->withdraw(amount);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 4:
                bank.showAccounts();
                break;
            case 5:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

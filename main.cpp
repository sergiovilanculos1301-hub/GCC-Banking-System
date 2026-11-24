
#include <iostream>
#include <string>
using namespace std;

// Store details of three bank users
string names[3] = {"John", "Peter", "Mary"};
int accountNumbers[3] = {1001, 1002, 1003};
int pins[3] = {1234, 2345, 3456};
double balances[3] = {5000.00, 3000.00, 4500.00};

// Function to find a user using account number
int findUser(int accountNumber)
{
    for (int i = 0; i < 3; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

// Display banking menu
void displayMenu()
{
    cout << "\n===== GCC BANK =====" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Send Cash" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// Deposit money
void deposit(int user)
{
    double amount;

    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (amount > 0)
    {
        balances[user] += amount;
        cout << "Deposit successful!" << endl;
        cout << "New balance: R" << balances[user] << endl;
    }
    else
    {
        cout << "Invalid amount. Please enter more than zero." << endl;
    }
}

// Withdraw money
void withdraw(int user)
{
    double amount;

    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount." << endl;
    }
    else if (amount > balances[user])
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        balances[user] -= amount;
        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: R" << balances[user] << endl;
    }
}

// Send cash to another account
void sendCash(int user)
{
    int receiverAccount;
    double amount;

    cout << "Enter receiver account number: ";
    cin >> receiverAccount;

    int receiver = findUser(receiverAccount);

    if (receiver == -1)
    {
        cout << "Account number not found!" << endl;
        return;
    }

    if (receiver == user)
    {
        cout << "You cannot send money to your own account." << endl;
        return;
    }

    cout << "Enter amount to send: R";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount!" << endl;
    }
    else if (amount > balances[user])
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        balances[user] -= amount;
        balances[receiver] += amount;

        cout << "Money sent successfully!" << endl;
        cout << "Receiver: " << names[receiver] << endl;
        cout << "Your remaining balance: R"
             << balances[user] << endl;
    }
}

// Check account balance
void checkBalance(int user)
{
    cout << "\nAccount Holder: " << names[user] << endl;
    cout << "Account Number: " << accountNumbers[user] << endl;
    cout << "Current Balance: R" << balances[user] << endl;
}

// Main program
int main()
{
    int accountNumber;
    int pin;
    int choice;
    int currentUser;

    cout << "================================" << endl;
    cout << "       WELCOME TO GCC BANK" << endl;
    cout << "================================" << endl;

    // Login section
    cout << "Enter account number: ";
    cin >> accountNumber;

    currentUser = findUser(accountNumber);

    if (currentUser == -1)
    {
        cout << "Account not found!" << endl;
        return 0;
    }

    cout << "Enter PIN: ";
    cin >> pin;

    if (pin != pins[currentUser])
    {
        cout << "Incorrect PIN!" << endl;
        return 0;
    }

    cout << "\nWelcome, " << names[currentUser] << "!" << endl;

    // Menu repeats until the user exits
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                deposit(currentUser);
                break;

            case 2:
                withdraw(currentUser);
                break;

            case 3:
                sendCash(currentUser);
                break;

            case 4:
                checkBalance(currentUser);
                break;

            case 5:
                cout << "Thank you for using GCC Bank!" << endl;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}


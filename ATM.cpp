//Bank Account ATM:
#include <iostream>
#include <ctime>
using namespace std;

class ATM {
protected:
    double balance;
    int pin;

public:
    ATM(double initialBalance, int userPin) : balance(initialBalance), pin(userPin) {}

    void showWelcome()
	 {
        cout << "\nWelcome To ATM" << endl;
        time_t now = time(0);
        cout << "Date & Time: " << ctime(&now) << endl;
        cout << "1. Enter PIN\n2. Help\n3. Exit\n";
    }

    bool checkPin(int enteredPin) 
	{
        return enteredPin == pin;
    }

    void showHelp()
    {
        cout << "\nHelp: Enter the correct PIN to access features." << endl;
    }

    virtual void showMenu() 
	{  
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
    }

    void deposit(double amount)
	{
        balance += amount;
        cout << "Deposited! New Balance: Rs. " << balance << endl;
    }

    void withdraw(double amount) 
	{
        if (amount > balance) 
		{
            cout << "Insufficient Balance!" << endl;
        } 
		else
		 {
            balance -= amount;
            cout << "Withdrawn! Remaining Balance: Rs. " << balance << endl;
         }
    }

    void checkBalance() 
	{
        cout << "Your Balance: Rs. " << balance << endl;
    }
};

// Derived class 
class SecureATM : public ATM {
public:
    SecureATM(double initialBalance, int userPin) : ATM(initialBalance, userPin) {}

    void showMenu() override
	{
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Change PIN\n5. Exit\n";
    }

    void changePin()
	 {
        int oldPin, newPin;
        cout << "Enter Old PIN: ";
        cin >> oldPin;
        if (oldPin == pin) 
		{
            cout << "Enter New PIN: ";
            cin >> newPin;
            pin = newPin;
            cout << "PIN Changed Successfully!" << endl;
        } 
		else
		{
            cout << "Incorrect Old PIN!" << endl;
        }
    }
};

int main() 
{
    int choice, pin;
    SecureATM atm(200000, 12345); // Using derived class

    atm.showWelcome();
    cin >> choice;

    if (choice == 1) 
	{
        cout << "Enter PIN: ";
        cin >> pin;
        if (!atm.checkPin(pin))
		{
            cout << "INCORRECT PIN! EXITING..." << endl;
            return 0;
        }
    }
	 else if (choice == 2)
	{
        atm.showHelp();
        return 0;
    } 
	else 
	{
        cout << "\nExiting...";
        return 0;
    }

    while (true) 
	{
        atm.showMenu();
        cin >> choice;

        if (choice == 1) 
		{
            double amount;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            atm.deposit(amount);
        } 
		else if (choice == 2) 
		{
            double amount;
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            atm.withdraw(amount);
        } 
		else if (choice == 3) 
		{
            atm.checkBalance();
        } 
		else if (choice == 4) 
		{
            atm.changePin();
        } 
		else
	    {
            cout << "Thank you!" << endl;
            break;
        }
    }
    return 0;
}


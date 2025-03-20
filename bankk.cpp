#include <iostream>
#include <ctime>
using namespace std;
void showWelcome() 
{
    cout <<"\nWelcome To ATM" << endl;
    time_t now = time(0);
    cout << "Date & Time: " << ctime(&now) << endl;
    cout << "1. Enter PIN\n2. Help\n3. Exit\n";
}

bool checkPin(int enteredPin) 
{
    return enteredPin == 12345;
}

void showHelp() 
{
    cout << "\nHelp: Enter the correct PIN to access features" << endl;
}

void showMenu() 
{
    cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
}

int main() 
{
    int choice, pin;
    double balance = 200000;
    bool authenticated = false;

    showWelcome();
    cin >> choice;

    if (choice == 1) 
	{
        cout << "Enter PIN: ";
        cin >> pin;
        if (checkPin(pin)) authenticated = true;
        else 
		{
            cout << "INCORRECT PIN! EXITING..." << endl;
            return 0;
        }
    } 
    else if (choice == 2) 
	{
        showHelp();
        return 0;
    } 
    else 
	{
        cout << "\nExiting...";
        return 0;
    }

    while (authenticated) 
	{
        showMenu();
        cin >> choice;
        
        if (choice == 1) 
		{
            double amount;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            balance += amount;
            cout << "Deposited! New Balance: Rs. "<< balance <<endl;
        } 
        else if (choice == 2) 
		{
            double amount;
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            if (amount > balance) 
			{
                cout << "Insufficient Balance!" << endl;
            } 
			else 
			{
                balance -= amount;
                cout << "Withdrawn! Remaining Balance: Rs. " << balance <<endl;
            }
        } 
        else if (choice == 3)
		{
            cout << "Your Balance: Rs. " << balance <<endl;
        } 
        else 
		{
            cout << "Thank you!"<<endl;
            break;
        }
    }
    
    return 0;
}


#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Bank.h"
#include <string>

using namespace std;

void ShowMenu()
{
	cout << "1     List customers " << endl;
	cout << "2     Add new customer " << endl;
	cout << "3     Delete customer " << endl;
	cout << "4     List all accounts " << endl;
	cout << "5     List customer accounts " << endl;
	cout << "6     Add new account" << endl;
	cout << "7     Delete account " << endl;
	cout << "8     Withdraw from account " << endl;
	cout << "9     Deposit to account " << endl;
	cout << "10    Transfer " << endl;
	cout << "11    Display info for the bank " << endl;
	cout << "12    Quit " << endl;
	cout << endl;
}

int main()
{
	Bank myBank;
	int command;
	ShowMenu();
	do
	{

		cin >> command;
		switch (command)
		{
		case 1:
		{
			myBank.listCustomers();
			break;
		}
		case 2:
		{
			int id = 0;
			cout << "New id: " << endl;
			cin >> id;
			cin.ignore();


			cout << "Name of the new customer: " << endl;
			string name;
			getline(cin, name);

			cout << "Address of the new customer: " << endl;
			string address;
			getline(cin, address);
			myBank.addCustomer(id, name, address);
			break;
		}
		case 3:
		{
			int id = 0;
			cout << "Write the ID of the customer to delete" << endl;
			cin >> id;
			cin.ignore();
			myBank.deleteCustomer(id);
			break;
		}
		case 4:
		{
			myBank.listAccounts();
			break;
		}
		case 5: // list customer account
		{
			cout << "Input the customer's ID: " << endl;
			int customerID;
			cin >> customerID;
			cin.ignore();
			myBank.listCustomerAccount(customerID);
			break;
		}
		case 6: // new account
		{
			cout << "Choose the type of account to add: " << endl;
			cout << "1. Current" << endl;
			cout << "2. Savings" << endl;
			cout << "3. Privilege" << endl;
			Bank::AccountType type;

			int AccountTypeChoice;
			cin >> AccountTypeChoice;
			cin.ignore();

			switch (AccountTypeChoice)
			{
			case 1: 
			{
				type = Bank::AccountType::Current;
				break;
			}
			case 2:
			{
				type = Bank::AccountType::Savings;
				break;
			}
			default:
			{
				type = Bank::AccountType::Privilege;
				break;
			}
			}
			unsigned long int IBAN = 0;
			cout << "New IBAN: " << endl;
			cin >> IBAN;
			cin.ignore();

			int ID = 0;
			cout << "New ID: " << endl;
			cin >> ID;
			cin.ignore();

			double amount = 0;
			cout << " New amount: " << endl;
			cin >> amount;
			cin.ignore();
			
			myBank.addAccount(type,IBAN, ID, amount);
			break;
		}
		case 7: // delete account
		{
			int Iban = 0;
			cout << "Write the IBAN of the account to delete" << endl;
			cin >> Iban;
			cin.ignore();
			myBank.deleteAccount(Iban);
			break;
		}
		case 8: //withdraw from account
		{
			cout << "Input the IBAN: " << endl;
			cout << "Input the amount to withdraw: " << endl;
			unsigned long int ibanChoice;
			double amount;
			cin >> ibanChoice >> amount;
			cin.ignore();
			myBank.withdrawFromAccount(ibanChoice, amount);
			break;
		}
		case 9: //deposit to account
		{
			cout << "Input the IBAN: " << endl;
			cout << "Input the amount to deposit: " << endl;
			unsigned long int ibanChoice;
			double amount;
			cin >> ibanChoice >> amount;
			cin.ignore();
			myBank.depositToAccount(ibanChoice, amount);

			break;


		}
		case 10: // transfer
		{
			unsigned int fromIBAN = 0;
			cout << "Input the IBAN to withdraw: " << endl;
			cin >> fromIBAN;
			cin.ignore();

			unsigned int toIBAN = 0;
			cout << "Input the IBAN to deposit: " << endl;
			cin >> toIBAN;
			cin.ignore();

			double amount = 0;
			cout << "Input the amount: " << endl;
			cin >> amount;
			cin.ignore();
			
			myBank.transfer(fromIBAN,toIBAN,amount);
			break;
		}
		case 11: // display info for the bank
		{
			myBank.display();
			break;
		}
		default:break;
		}

		ShowMenu();
	} while (command != 12);

}
#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(unsigned long iban, int ownerID, double amount)
{
	this->IBAN = iban;
	this->ownerID = ownerID;
	this->amount = amount;
}

double PrivilegeAccount::getOverdraft()
{
	return overdraft;
}

void PrivilegeAccount::deposit(double newAmount)
{
	this->amount = amount + newAmount;
}

bool PrivilegeAccount::withdraw(double newAmount)
{
	if (newAmount > (this->amount+overdraft))
	{
		return false;
	}
	else
	{
		this->amount = amount - newAmount;
		return true;
	}
}

void PrivilegeAccount::display()
{
	using namespace std;
	cout << "Information for the Privilege account" << endl;
	cout << "IBAN: " << IBAN << endl;
	cout << "Owner`s ID: " << ownerID << endl;
	cout << "Balance: " << amount << endl;
	cout << "Overdraft: " << overdraft << endl;
}

#include "CurrentAccount.h"
#include<iostream>
using namespace std;

CurrentAccount::CurrentAccount(unsigned long iban, int ownerID, double amount)
{
	this->IBAN = iban;
	this->ownerID = ownerID;
	this->amount = amount;
}

void CurrentAccount::deposit(double newAmount)
{
	this->amount = amount + newAmount;
}

bool CurrentAccount::withdraw(double newAmount)
{
	if (newAmount > this->amount)
	{
		return false;
	}
	else
	{
		this->amount = amount - newAmount;
		return true;
	}
}

void CurrentAccount::display()
{
	cout << "Information for the Current account" << endl;
	cout << "IBAN: " << IBAN << endl;
	cout << "Owner`s ID: " << ownerID << endl;
	cout << "Balance: " << amount << endl;
}

#include "SavingsAccount.h"
#include<iostream>

SavingsAccount::SavingsAccount(unsigned long iban, int ownerID, double amount)
{
	this->IBAN = iban;
	this->ownerID = ownerID;
	this->amount = amount;
}

double SavingsAccount::getInterestRate()
{
	return interestRate;
}

void SavingsAccount::deposit(double newAmount)
{
	this->amount = amount + newAmount;
}

bool SavingsAccount::withdraw(double newAmount)
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

void SavingsAccount::display()
{
	using namespace std;
	cout << "Information for the Savings account" << endl;
	cout << "IBAN: " << IBAN << endl;
	cout << "Owner`s ID: " << ownerID << endl;
	cout << "Balance: " << amount << endl;
	cout << "Ineterest Rate: " << interestRate << endl;

}

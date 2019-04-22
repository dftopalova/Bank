#include "Account.h"

Account::Account(unsigned long iban, int ownerID, double amount)
{
	this->IBAN = iban;
	this->ownerID = ownerID;
	this->amount = amount;

}

Account::Account()
{
	this->IBAN = 0;
	this->ownerID = 0;
	this->amount = 0;
}

Account::Account(Account & other)
{
	this->IBAN = other.IBAN;
	this->ownerID = other.ownerID;
	this->amount = other.amount;

}

double Account::getBalance()
{
	return amount;
}

unsigned long Account::getIBAN()
{
	return IBAN;
}

int Account::getOwnerID()
{
	return ownerID;
}

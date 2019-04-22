#pragma once

class Account
{
public:
	Account(unsigned long iban, int ownerID, double amount);
	Account();
	Account(Account &other);
	virtual ~Account()=default;

	virtual void deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;
	virtual void display() = 0;
	double getBalance();
	unsigned long getIBAN();
	int getOwnerID();
	

protected:
	unsigned long int IBAN;
	int ownerID;
	double amount;
};
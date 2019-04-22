#pragma once
#include"Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(unsigned long iban, int ownerID, double amount);
	double getInterestRate();
	void deposit(double newAmount);
	bool withdraw(double newAmount);
	void display();
protected:
	double interestRate;
};

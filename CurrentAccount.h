#pragma once
#include"Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(unsigned long iban, int ownerID, double amount);
	void deposit(double newAmount);
	bool withdraw(double newAmount);
	void display();
};
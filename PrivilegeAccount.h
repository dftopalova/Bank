#pragma once
#include<iostream>
#include"Account.h"

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount(unsigned long iban, int ownerID, double amount);
	double getOverdraft();
	void deposit(double newAmount);
	bool withdraw(double newAmount);
	void display();
protected:
	double overdraft;
};

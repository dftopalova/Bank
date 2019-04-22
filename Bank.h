#pragma once

#include<string>
#include<vector>
#include"Account.h"
#include"Customer.h"
using namespace std;

class Bank
{
public:
	enum AccountType {
		Current,
		Savings,
		Privilege
	};
	Bank() = default;
	Bank(string Name, string Address, vector<Customer*> Customers, vector<Account*> Accounts);
	~Bank();
	string getName();
	string getAddress();
	void addCustomer(int customerID, string name, string address);
	void listCustomers();
	void deleteCustomer(int customerID);
	void addAccount(AccountType type, int IBAN, int ownerID, double amount);
	void deleteAccount(int IBAN);
	void listAccounts();
	void listCustomerAccount(int customerID);
	bool transfer(unsigned int, unsigned, double);
	void display();
	bool withdrawFromAccount(unsigned long int IBAN, double amount);
	void depositToAccount(unsigned long int IBAN, double amount);
	 
protected:
	string name;
	string address;
	vector<Customer*> customers;
	vector<Account*> accounts;
};

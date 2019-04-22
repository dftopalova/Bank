#include<iostream>
#include "Bank.h"
#include"Customer.h"
#include"CurrentAccount.h"
#include"SavingsAccount.h"
#include"PrivilegeAccount.h"


Bank::Bank(string Name, string Address, vector<Customer*> Customers, vector<Account*> Accounts)
{
	this->name = Name;
	this->address = Address;
	this->customers = Customers;
	this->accounts = Accounts;

}

Bank::~Bank()
{
	for (size_t i = 0; i <= customers.size(); i++)
	{
		delete customers[i];
	}
	for (size_t j = 0; j <= accounts.size(); j++)
	{
		delete accounts[j];
	}
	accounts.erase(accounts.begin(), accounts.end());
	customers.erase(customers.begin(), customers.end());
}

string Bank::getName()
{
	return name;
}

string Bank::getAddress()
{
	return address;
}

void Bank::addCustomer(int customerID, string name, string address)
{
	Customer *newCustomer = new Customer(customerID, name, address);
	customers.push_back(newCustomer);
}

void Bank::listCustomers()
{
	for (size_t i = 0; i < customers.size(); i++)
	{
		customers[i]->display();
	}
}

void Bank::deleteCustomer(int customerID)
{
	for (size_t i = 0; i < customers.size(); i++) 
	{
		if (customerID == customers[i]->getID())
		{
			customers.erase(customers.begin()+i);
			break;
		}
	}
}

void Bank::addAccount(AccountType type, int IBAN, int ownerID, double amount)
{
	if (type == Current)
	{
		CurrentAccount *newAccount = new CurrentAccount(IBAN, ownerID, amount);
		accounts.push_back(newAccount);
	}
	else if (type == Savings)
	{
		SavingsAccount *newSaveAccount = new SavingsAccount(IBAN, ownerID, amount);
		accounts.push_back(newSaveAccount);
	}
	else if (type == Privilege)
	{
		PrivilegeAccount *newPrivAccount = new PrivilegeAccount(IBAN, ownerID, amount);
		accounts.push_back(newPrivAccount);
	}

}

void Bank::deleteAccount(int IBAN)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (IBAN == accounts[i]->getIBAN())
		{
			accounts.erase(accounts.begin() + i);
			break;
		}
	}
}

void Bank::listAccounts()
{
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(int customerID)
{
	for (size_t i = 0; i < accounts.size(); i++) 
	{
		if (customerID == accounts[i]->getOwnerID())
		{
			accounts[i]->display();
		}
	}
}

bool Bank::transfer(unsigned int fromIBAN, unsigned toIBAN, double amount)
{
	
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (fromIBAN == accounts[i]->getIBAN())
		{
			accounts[i]->withdraw(amount);
			if (!accounts[i]->withdraw(amount))
			{
				return false;
			}
			break;
		}
	}
	
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (toIBAN == accounts[i]->getIBAN())
		{
			accounts[i]->deposit(amount);
		}
	}

}

void Bank::display()
{
	cout << "Name of the bank: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Count of the customers: " << customers.size() << endl;
	cout << "Count of the accounts: " << accounts.size() << endl;
}

bool Bank::withdrawFromAccount(unsigned long int IBAN, double amount)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (IBAN == accounts[i]->getIBAN())
		{
			return accounts[i]->withdraw(amount);
		}
	}
	return false;
}

void Bank::depositToAccount(unsigned long int IBAN, double amount)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (IBAN == accounts[i]->getIBAN())
		{
			accounts[i]->deposit(amount);
			return;
		}
	}
}



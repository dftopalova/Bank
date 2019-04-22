#include "Customer.h"

Customer::Customer(int id, string name, string address)
{
	this->id = id;
	this->name = name;
	this->address = address;

}

int Customer::getID()
{
	return id;
}

string Customer::getName()
{
	return name;
}

string Customer::getAddress()
{
	return address;
}

void Customer::display()
{
	cout << "Customer: " << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
}

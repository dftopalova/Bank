#pragma once
#include<iostream>
#include<string>
using namespace std;

class Customer
{
public:
	Customer(int id, string name, string address);
	int getID();
	string getName();
	string getAddress();
	void display();
protected:
	int id;
	string name;
	string address;

};

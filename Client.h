#pragma once
#include "Person.h"
#include <vector>
#include <iterator>

class Client : public Person{
private:
	//Attribute
	double balance;
public:
	//Constructors
	Client() : Person(){
		this->balance = 0.0;
	}
	Client(string name, int id, string password, double balance) : Person(name, id, password) {
		this->balance = balance;
	}
	//Setter
	void setBalance(double balance) {
		this->balance = balance;
	}
	//Getter
	double getBalance() {
		return this->balance;
	}
	//Methods
	void display() {
		Person::display();
		cout << "Balance: " << this->balance << endl;
	}
	void deposit(double amount) {
		this->balance += amount;
		cout << "\nSuccessful transaction.\n";
	}
	void withdraw(double amount) {
		if (amount <= this->balance) { 
			this->balance -= amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
	void transferTo(double amount, Client& recipient) {
		if (amount <= balance) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
	void checkBalance() {
		cout << "Balance: " << this->balance << endl;
	}
};

 static vector<Client> allClients;
 static vector<Client>::iterator clIt;
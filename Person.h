#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
	//Attributes
	string name;
	int id;
	string password;
public:
	//Constructors
	Person() {
		this->name = " ";
		this->id = 0;
		this->password = " ";
	}
	Person(string name, int id, string password) {
		this->name = name;
		this->id = id;
		this->password = password;
	}
	//Setters
	void setName(string name) {
		this->name = name;
	}
	void setId(int id) {
		this->id = id;
	}
	void setPassword(string password) {
		this->password = password;
	}
	//Getters
	string getName() {
		return this->name;
	}
	int getId() {
		return this->id;
	}
	string getPassword() {
		return this->password;
	}
	//Method
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Id: " << this->id << endl;
		cout << "Password: " << this->password << endl;
	}
};
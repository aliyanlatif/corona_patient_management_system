#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
class LoginNode {
public:
	string Fname;
	string Lname;
	string AccountName;
	string password;
	LoginNode* next;
	LoginNode();
};
class LoginList {
public:
	LoginNode* head;
	LoginList();
	void insert_end(string FirstName, string LastName, string AccountName, string Password);
	void createAccount();
	bool AccountLogin();
	void createList();
	void display();
};


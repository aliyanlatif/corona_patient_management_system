#pragma once
#include<iostream>
#include<conio.h>
#include"Login.h"
#include<string>
#include<fstream>
using namespace std; 
class applicant {
public:
	string studentName;
	string id;
	string degree;
	string domain;
	string book_name;
	string book_No;
	int registeredBooks;
	applicant();
};
class bookNode {
public:
	string bookName;
	string author;
	string domain;
	string publishDate;
	string bookNumber;
	bookNode* left;
	bookNode* right;
	bookNode();
};
class bookTree {
public:
	bookNode* root;
	bookTree();
	bookNode* getroot();
	void insert(string BookName, string Author, string Domain, string PublishDate, string BookNo);
	void createList();
	void add_books();
	void search_book();
	void delete_book();
	void modify_book();
	void traverse(bookNode* temp);
	int compute_books(bookNode* temp);
	void register_books();
};

#include<iostream>
#include<conio.h>
#include"Login.h"
#include"book.h"
#include<string>
#include<fstream>
using namespace std;
void LibraryMenu()
{
	int choice2;
	int a = 1;
	while (a)
	{
		system("cls");
		cout << "\t\t\t\t***Library MANAGEMENT SYSTEM***\n\n";
		cout << "... MENU ...\n";
		cout << "  ->Press 1 for Adding record of a book.\n"
			"  ->Press 2 for Deleting record of a book.\n"
			"  ->Press 3 for Searching record of a book.\n"
			"  ->Press 4 for Modifying record of a book.\n"
			"  ->Press 5 to see how many books are in the library.\n"
			"  ->Press 6 to see how many books of specific domain has been chosen by the applicant.\n"
			"  ->Press 7 for exit.\n\n"
			"  ->Your Choice:";
		cin >> choice2;
		bookTree* obj1 = new bookTree;
		switch (choice2)
		{
			case 1: {
				obj1->add_books();
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				obj1->delete_book();
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				obj1->search_book();
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				obj1->modify_book();
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				bookTree* obj2 = new bookTree;
				obj2->createList();
				cout <<"\nThere are "<< obj2->compute_books(obj2->getroot())<<" books in Library.\n";
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				obj1->register_books();
				system("pause");
				system("cls");
				break;
			}
			case 7: {
				a = 0;
				break;
			}
			default: {
				cout << "Invalid Choice entered.\n";
				system("cls");
				break;
			}
		}
	}
}
void LoginMenu()
{
	int loopEnd = 1;
	int choice1 = 0;
	LoginList* obj1 = new LoginList;
	while (loopEnd)
	{
		cout << "\t\t\t\t***LIBRARY MANAGEMENT SYSTEM***\n\n";
		cout << "  Login Screen...\n";
		cout << "  ->Press 1 for Creating an account.\n"
			"  ->Press 2 for Login.\n"
			"  ->Press 3 for Exit.\n\n"
			"  ->Your Choice:";
		cin >> choice1;
		switch (choice1)
		{
		case 1: {
			obj1->createAccount();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			if (obj1->AccountLogin())
			{
				cout << "* Login Successfull *";
				LibraryMenu();
			}
			else
			{
				cout << "Login Failed invalid credentials entered !!!";
			}
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			loopEnd = 0;
			break;
		}
		default: {
			cout << "Invalid Choice entered.\n";
			system("cls");
			break;
		}
		}
	}
}
int main()
{
	LoginMenu();
	return 0;
}

//	
//obj1->register_books();
	//cout << "\nBook Name\t\tAuthor\t\tDomain\t\tPublish date\t\tBook No\n\n";
	//obj1->createList();
	//obj1->traverse(obj1->getroot());
	//cout<<obj1->compute_books(obj1->getroot());
	//
	//
	//
//LoginList* obj1 = new LoginList;
////obj1->createAccount();
//if (obj1->AccountLogin())
//{
//	cout << "* Login Successfull *";
//	LoginList* obj2 = new LoginList;
//	obj2->createList();
//	obj2->display();
//}
//else
//{
//	cout << "Login Failed invalid credentials entered !!!";
//}
//string name,string Author,string Domain,string PublishDate,string BookNo
	//LoginList* obj2 = new LoginList;
	//obj2->createList();
	//obj2->display();
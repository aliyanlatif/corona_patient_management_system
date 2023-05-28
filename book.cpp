#include"book.h"
applicant::applicant()
{
	studentName = " ";
	id = " ";
	degree = " ";
	domain = " ";
	book_name = " ";
	book_name = " ";
	book_No = " ";
	registeredBooks = 0;
}
bookNode::bookNode()
{
	bookName = " ";
	author = " ";
	domain = " ";
	publishDate = " ";
	bookNumber = " ";
	left = right = NULL;
}
bookTree::bookTree()
{
	root = NULL;
}
bookNode* bookTree:: getroot()
{
	return root;
}
void bookTree :: insert(string BookName, string Author, string Domain, string PublishDate, string BookNo)
{

	bookNode* temp = root;
	bookNode* prev = NULL;
	while (temp != NULL)
	{
		prev = temp;
		if (BookName.compare(temp->bookName) == 1)
		{
			temp = temp->right;
		}
		else if (BookName.compare(temp->bookName) == -1)
		{
			temp = temp->left;
		}
		else
		{
			if (BookNo.compare(temp->bookNumber) == 1)
				temp = temp->right;
			else if (BookNo.compare(temp->bookNumber) == -1)
				temp = temp->left;
			else
			{
				cout << "\nBook with the following book number already exists.\n";
				return;
			}
		}
	}
	bookNode* ptr = new bookNode;
	ptr->bookName = BookName;
	ptr->author = Author;
	ptr->domain = Domain;
	ptr->publishDate = PublishDate;
	ptr->bookNumber = BookNo;
	ptr->left = ptr->right = NULL;
	if (prev == NULL)
		root = ptr;
	else if (BookName.compare(prev->bookName) == 1)
		prev->right = ptr;
	else if (BookNo.compare(prev->bookNumber) == -1)
		prev->left = ptr;
}
void bookTree:: createList()
{
	bookNode* temp = new bookNode;
	ifstream IfStreamObj("BookFile.dat", ios::in);
	if (IfStreamObj.fail())
	{
		cout << "\nFailed to create List because file not opened !!!\n";
		return;
	}
	else
	{
		while (IfStreamObj >> temp->bookName >> temp->author >> temp->domain >> temp->publishDate >> temp->bookNumber)
		{
			insert(temp->bookName, temp->author, temp->domain, temp->publishDate, temp->bookNumber);
		}
		IfStreamObj.close();
	}
}
void bookTree:: add_books()
{
	ofstream OfStreamObj("BookFile.dat", ios::out | ios::app);
	if (OfStreamObj.fail())
	{
		cout << "Failed to add book because file not opened.";
		return;
	}
	else
	{
		bookNode* temp = new bookNode;
		cout << "\nPlease enter book details\n";
		cout << "Book Name: ";
		getline(cin >> ws, temp->bookName);
		cout << "Author: ";
		getline(cin >> ws, temp->author);
		cout << "Domain: ";
		getline(cin >> ws, temp->domain);
		cout << "Publish Date: ";
		getline(cin >> ws, temp->publishDate);
		cout << "Book Number: ";
		getline(cin >> ws, temp->bookNumber);
		OfStreamObj << temp->bookName << "\t" << temp->author << "\t" << temp->domain << "\t" <<
			temp->publishDate << "\t" << temp->bookNumber << endl;
		OfStreamObj.close();
	}
}
void bookTree:: search_book()
{
	int a = 1;
	string searchNumber;
	ifstream IfStreamObj("BookFile.dat", ios::in);
	cout << "\nPlease enter book number which you want to search: ";
	getline(cin >> ws, searchNumber);
	if (IfStreamObj.fail())
	{
		cout << "Failed to Search book because file not opened.";
		return;
	}
	else
	{
		bookNode* temp = new bookNode;
		while (IfStreamObj >> temp->bookName >> temp->author >> temp->domain >> temp->publishDate >> temp->bookNumber)
		{
			if (searchNumber.compare(temp->bookNumber) == 0)
			{
				cout << "\nBook Name\t\tAuthor\t\tDomain\t\tPublish Date\t\tBook Number\n";
				cout << temp->bookName << "\t\t\t" << temp->author << "\t\t" << temp->domain <<
					"\t\t" << temp->publishDate << "\t\t" << temp->bookNumber << endl;
				a = 0;
				break;
			}

		}
		if (a)
		{
			cout << "\n\n No Record Found under the given Book Number.\n\n";
		}
		IfStreamObj.close();
	}
}
void bookTree::modify_book()
{
	int a = 1;
	string modifyString;
	cout << "\nPlease enter book number which you want to delete: ";
	getline(cin >> ws, modifyString);
	ifstream IfStreamObj("BookFile.dat", ios::in);
	if (IfStreamObj.fail())
	{
		cout << "Failed to modify book because file not opened.";
		return;
	}
	else
	{
		bookNode* temp = new bookNode;
		ofstream OfStreamObj("tempFile.dat", ios::out | ios::app);
		while (IfStreamObj >> temp->bookName >> temp->author >> temp->domain >> temp->publishDate >> temp->bookNumber)
		{
			if (modifyString.compare(temp->bookNumber) == 0)
			{
				cout << "\nPrevious Record ***\n";
				cout << "\nBook Name\t\tAuthor\t\tDomain\t\tPublish date\t\tBook No\n\n";
				cout << "\n" << temp->bookName << "\t\t\t" << temp->author << "\t\t" << temp->domain
					<< "\t\t" << temp->publishDate << "\t\t" << temp->bookNumber;
				bookNode* temp = new bookNode;
				cout << "\nPlease enter book details\n";
				cout << "Book Name: ";
				getline(cin >> ws, temp->bookName);
				cout << "Author: ";
				getline(cin >> ws, temp->author);
				cout << "Domain: ";
				getline(cin >> ws, temp->domain);
				cout << "Publish Date: ";
				getline(cin >> ws, temp->publishDate);
				cout << "Book Number: ";
				getline(cin >> ws, temp->bookNumber);
				OfStreamObj << temp->bookName << "\t" << temp->author << "\t" << temp->domain << "\t" <<
					temp->publishDate << "\t" << temp->bookNumber << endl;
				OfStreamObj.close();
				a = 0;
			}
			else
			{
				OfStreamObj << temp->bookName << "\t" << temp->author << "\t" << temp->domain << "\t" <<
					temp->publishDate << "\t" << temp->bookNumber << endl;
			}
		}
		if (a)
		{
			cout << "\n.No record found under the given book number.\n";
		}
		OfStreamObj.close();
		IfStreamObj.close();
		remove("BookFile.dat");
		rename("tempFile.dat", "BookFile.dat");
	}

}
void bookTree::delete_book()
{
	int a = 1;
	string deleteString;
	cout << "\nPlease enter book number which you want to delete: ";
	getline(cin >> ws, deleteString);
	ifstream IfStreamObj("BookFile.dat", ios::in);
	if (IfStreamObj.fail())
	{
		cout << "Failed to delete book because file not opened.";
		return;
	}
	else
	{
		bookNode* temp = new bookNode;
		ofstream OfStreamObj("tempFile.dat", ios::out | ios::app);
		while (IfStreamObj >> temp->bookName >> temp->author >> temp->domain >> temp->publishDate >> temp->bookNumber)
		{
			if (deleteString.compare(temp->bookNumber) == 0)
			{
				cout << "Record with the book number " << temp->bookNumber << " has been deleted successfully *" << endl;
				a = 0;
			}
			else
			{
				OfStreamObj << temp->bookName << "\t" << temp->author << "\t" << temp->domain << "\t" <<
					temp->publishDate << "\t" << temp->bookNumber << endl;
			}
		}
		if (a)
		{
			cout << "\n.No record found under the given book number.\n";
		}
		OfStreamObj.close();
		IfStreamObj.close();
		remove("BookFile.dat");
		rename("tempFile.dat", "BookFile.dat");
	}
}
void bookTree:: traverse(bookNode* temp)
{
	if (temp == NULL)
	{
		cout << "\nNo record found.\n";
		return;
	}
	else
	{
		if (temp->left != NULL)
			traverse(temp->left);
		cout << "\n"<<temp->bookName << "\t\t\t" << temp->author << "\t\t" << temp->domain
			<< "\t\t" << temp->publishDate << "\t\t" << temp->bookNumber;
		if (temp->right != NULL)
			traverse(temp->right);
	}
}
int bookTree::compute_books(bookNode* temp)
{
	if (temp == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + compute_books(temp->left) + compute_books(temp->right);
	}
}
void bookTree:: register_books()
{
	applicant obj;
	int pointer = 0;
	ofstream OfStreamObj("applicantRecord.dat", ios::out | ios::app);
	if (OfStreamObj.fail())
	{
		cout << "\nCannot enter record because file not opened.\n";
	}
	else
	{
		cout << "\nPlease enter Applicants details.\n";
		cout << "Student Name: ";
		cin >> obj.studentName;
		cout << "Student ID: ";
		cin >> obj.id;
		cout << "Degree (BS / MS): ";
		cin >> obj.degree;
		cout << "Domain: ";
		cin >> obj.domain;
		cout << "Book Name: ";
		cin >> obj.book_name;
		cout << "Book No: ";
		cin >> obj.book_No;
		obj.registeredBooks++;
		ofstream OfStreamObj("applicantRecord.dat", ios::out | ios::app);
		OfStreamObj << obj.studentName << "\t" << obj.id << "\t" << obj.degree << "\t"
			<< obj.domain << "\t" << obj.book_name << "\t" << obj.book_No << "\t"
			<< obj.registeredBooks << endl;
		OfStreamObj.close();
	}
	string ID;
	int flag = 1;
	cout << "\nPlease enter student ID: ";
	cin >> ID;
	ifstream IfStreamObj("applicantRecord.dat", ios::in);
	while (IfStreamObj >> obj.studentName >> obj.id >> obj.degree >> obj.domain
		>> obj.book_name >> obj.book_No >> obj.registeredBooks)
	{
		if (ID.compare(obj.id) == 0)
		{
			flag = 0;
			cout << "\nStudent have issued " << obj.registeredBooks << " books." << endl;
		}
	}
	IfStreamObj.close();
}
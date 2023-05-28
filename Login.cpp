#include"Login.h"
LoginNode::LoginNode()
{
	Fname = " ";
	Lname = " ";
	AccountName = " ";
	password = " ";
	next = NULL;
}
LoginList::LoginList()
{
	head = NULL;
}
void LoginList:: insert_end(string FirstName,string LastName,string AccountName,string Password)
{
	LoginNode* temp = new LoginNode;
	temp = head;
	LoginNode* temp2 = new LoginNode;
	temp2->Fname = FirstName;
	temp2->Lname = LastName;
	temp2->AccountName = AccountName;
	temp2->password = Password;
	temp2->next = NULL;
	if (head == NULL)
	{
		head = temp2;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = temp2;
	}
}
void LoginList:: createAccount()
{
	ofstream OfStreamObj("LoginFile.dat", ios::out | ios::app);
	if (OfStreamObj.fail())	//Condition to check whether the file is opened or not
	{
		cout << "Failed to create account because file not opened.";
		return;
	}
	else
	{
		LoginNode* temp = new LoginNode;
		cout << "*** Please Enter Account Details ***\n";
		cout << "First Name :";
		getline(cin >> ws, temp->Fname);
		cout << "Last Name :";
		getline(cin >> ws, temp->Lname);
		cout << "Account Name :";
		getline(cin >> ws, temp->AccountName);
		cout << "Password :";
		getline(cin >> ws, temp->password);
		OfStreamObj << temp->Fname << "\t" << temp->Lname << "\t" << temp->AccountName << "\t" << temp->password << endl;
		OfStreamObj.close();
		cout << "\nAccoount has been created successfully.\n";
	}
}
bool LoginList:: AccountLogin()
{
	int a=1;
	LoginNode* temp = new LoginNode;
	string AccName, password;
	cout << "Account Name: ";
	getline(cin >> ws, AccName);
	cout << "Password: ";
	getline(cin >> ws, password);
	ifstream IfStreamObj("LoginFile.dat", ios::in);
	if (IfStreamObj.fail())
	{
		cout << "Failed to login because file not opened.";
	}
	else
	{
		while (IfStreamObj >> temp->Fname >> temp->Lname >> temp->AccountName >> temp->password)
		{
			if (temp->AccountName.compare(AccName) == 0 && temp->password.compare(password) == 0)
			{
				IfStreamObj.close();//file closing
				a = 0;/*incase if name and password matches then setting a to 0,
					so that the condition below wont run.*/
				return true;
			}
		}
		if (a)
		{
			IfStreamObj.close();
			return false;
		}
	}
}
void LoginList::createList()
{
	LoginNode* temp = new LoginNode;
	ifstream IfStreamObj("LoginFile.dat", ios::in);
	if (IfStreamObj.fail())
	{
		cout << "Failed to login because file not opened.";
	}
	else
	{
		while (IfStreamObj >> temp->Fname >> temp->Lname >> temp->AccountName >> temp->password)
		{
			insert_end(temp->Fname, temp->Lname, temp->AccountName, temp->password);
		}
	}
}
void LoginList::display()
{
	LoginNode* temp = new LoginNode;
	temp = head;
	if (temp == NULL)
	{
		cout << "\nNo Account found !!!";
		return;
	}
	else
	{
		while (temp != NULL)
		{
			cout << "\nFirst Name: " << temp->Fname;
			cout << "\nLast Name: " << temp->Lname;
			cout << "\nAccount Name: " << temp->AccountName;
			cout << "\nPassword: " << temp->password << endl;
			temp = temp->next;
		}
	}
}

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Account
{
protected:
	string _login;
	string _password;
	string _name;
	string _surname;
public:
	Account();
	Account(string login, string password);
	Account(string login, string password, string name, string surname);
	void setLogin(string login);
	void setPassword(string password);
	void setName(string name);
	void setSurname(string surname);
	string getLogin();
	string getPassword();
	string getName();
	string getSurname();

	void print();
	void change();

	bool operator==(const Account& A);
	friend ostream& operator<<(ostream& output, const Account& A);
};

class Users
{
private:
	int m_length;
	Account* m_data;
public:
	Users();
	~Users();

	Users& operator=(const Users& A);
	Account& operator[](int index);

	void erase();
	void reallocate(int newLegth);
	void resize(int nweLength);

	void Acc(string login, string password, string name, string surname);
	void NewAcc();

	int getLength() const;

	int findAccount(string login, string password);
	Account& friendsList(int index);
	int Login();
};
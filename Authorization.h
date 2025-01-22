#pragma once
#include <iostream>
#include <string>
#include <vector>
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

	string friendsList(int index);
};


class Message
{
protected:
	string* c_mes;
	int c_size;
	string log_acc1;
	string log_acc2;
public:
	Message()
	{
		c_size = 0;
		c_mes = new string[c_size]();
		log_acc1 = "";
		log_acc2 = "";
	}
	Message(string acc1, string acc2)
	{
		log_acc1 = acc1;
		log_acc2 = acc2;
		c_size = 0;
		c_mes = new string[c_size]();
	}
	~Message()
	{
		delete[] c_mes;
	}

	bool operator==(const Message& chat)
	{
		if (this->log_acc1 == chat.log_acc1 && this->log_acc2 == chat.log_acc2)
			return true;
		else
			return false;
	}

	void setAcc1(string acc1)
	{
		log_acc1 = acc1;
	}
	void setAcc2(string acc2)
	{
		log_acc2 = acc2;
	}

	void newMes()
	{
		string str;
		string* mes0 = new string[c_size + 1];

		cout << "Введите сообщение: ";
		copy_n(c_mes, c_size, mes0);
		cin >> str;
		mes0[c_size] = str;

		delete[] c_mes;
		c_mes = mes0;
		++c_size;
		cout << "Сообщение отправлено!";
	}
	void printMes()
	{
		for (int i = 0; i < c_size; ++i)
		{
			cout << "- " << c_mes[i] << endl;
		}
	}
};



class Chat
{
private:
	Message* m_chat;
	int m_length;
public:
	Chat()
	{
		m_length = 0;
		m_chat = new Message[m_length]();
	}
	~Chat()
	{
		delete[] m_chat;
	}

	void openChat(string acc1, string acc2)
	{
		int count = 0;
		Message mes1(acc1, acc2);
		Message mes2(acc2, acc1);
		for (int i = 0; i < m_length; ++i)
		{
			if (m_chat[i] == mes1 || m_chat[i] == mes2)
			{
				int choice;
				m_chat[i].printMes();
				cout << "Вы хотите написать сообщение?" << endl
					<< "1. Да" << endl
					<< "2. Нет" << endl;
				cin >> choice;
				if (choice == 1)
				{
					m_chat[i].newMes();
				}
			}
			else
				++count;
		}
		if (count == m_length)
		{

			Message* chat = new Message[m_length + 1];

			copy_n(m_chat, m_length, chat);
			chat[m_length].setAcc1(acc1);
			chat[m_length].setAcc2(acc2);

			cout << "Чат создан!";

			int choice;
			cout << "Вы хотите написать сообщение?" << endl
				<< "1. Да" << endl
				<< "2. Нет" << endl;
			cin >> choice;
			if (choice == 1)
			{
				chat[m_length].newMes();
			}

			delete[] m_chat;
			m_chat = chat;
			++m_length;
		}
	}


	void chat(string acc1, string acc2)
	{
		int count = 0;
		Message me1(acc1, acc2);
		Message me2(acc2, acc1);
		for (int i = 0; i < m_length; ++i)
		{
			if (m_chat[i] == me1 || m_chat[i] == me2)
			{
				cout << "Чат уже создан!" << endl;
			}
			else
				++count;
		}

		if (count == m_length)
		{
			Message* chat = new Message[m_length + 1];
			copy_n(m_chat, m_length, chat);
			chat[m_length].setAcc1(acc1);
			chat[m_length].setAcc2(acc2);

			delete[] m_chat;
			m_chat = chat;
			++m_length;

			cout << "Чат создан!";
		}
	}
};
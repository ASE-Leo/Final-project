#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Authorization.h"
using namespace std;

class Chat
{
protected:
	string* c_mes;
	string* c_name;
	int c_length;
	Account c_acc1;
	Account c_acc2;
public:
	Chat();
	Chat(const Account& acc1, const Account& acc2);
	~Chat();

	Chat& operator=(const Chat& ms);
	bool operator==(const Chat& chat);

	void erase();
	void reallocate(int newLength);
	void resize(int newLength);
	int getLength() const;

	void setAcc1(const Account& acc1);
	void setAcc2(const Account& acc2);

	void newMes(string send);
	void printMes(const Account& acc);
};

class Messenger
{
private:
	Chat* m_chat;
	int m_length;
public:
	Messenger();
	~Messenger();

	Messenger& operator=(const Messenger& ch);
	Chat& operator[](int index);

	void erase();
	void reallocate(int newLength);
	void resize(int newLength);
	int getLength() const;

	void openChat(const Account& acc1, const Account& acc2, string send);
};
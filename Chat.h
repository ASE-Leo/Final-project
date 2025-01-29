#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Authorization.h"
using namespace std;

// Класс, который хранит сообщения определенных людей (или сообщения общего чата)

class Chat
{
protected:
	string* c_mes; // сообщения
	string* c_name; // имя отправителя (для вывода на кансоль вместе с сообщением)
	int c_length; // кол-во чатов
	Account<std::string> c_acc1; // отправитель
	Account<std::string> c_acc2; // получатель 
public:
	Chat();
	Chat(const Account<std::string>& acc1, const Account<std::string>& acc2);
	~Chat();

	Chat& operator=(const Chat& ms);
	bool operator==(const Chat& chat);

	void erase();
	void reallocate(int newLength);
	void resize(int newLength);
	int getLength() const;

	void setAcc1(const Account<std::string>& acc1);
	void setAcc2(const Account<std::string>& acc2);

	void newMes(string send); // Здесь мы создаем новое сообщение в чате, а аргументом передаем имя отправителя, чтобы также его сохранить 
	void printMes(); // вывод всей переписки на кансоль вместе с именем отправителя 
};

// Класс, который хранит все чаты

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

	void general(); // Тут создается общий чат, открыть который может каждый

	void erase();
	void reallocate(int newLength);
	void resize(int newLength);
	int getLength() const;

	// Эта функция открывает определнный чат для каждого пользователя,
	// создает новый чат если необходимый ещё не создан,
	// а если такой имеется, то выводит все сообщениия в чате и дает возможность написать новое
	void openChat(const Account<std::string>& acc1, const Account<std::string>& acc2, string send);
	// Такая же функция, но только для общего чата
	void openChat(string send);
};
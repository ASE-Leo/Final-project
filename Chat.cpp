#include "Chat.h"

Chat::Chat()
{
	c_length = 0;
	c_mes = new string[c_length]();
	c_name = new string[c_length]();
}
Chat::Chat(const Account& acc1, const Account& acc2)
{
	c_acc1 = acc1;
	c_acc2 = acc2;
	c_length = 0;
	c_mes = new string[c_length]();
	c_name = new string[c_length]();
}
Chat::~Chat()
{
	delete[] c_mes;
	delete[] c_name;
}

Chat& Chat::operator=(const Chat& ms)
{
	if (&ms == this)
		return *this;
	reallocate(ms.getLength());
	c_acc1 = ms.c_acc1;
	c_acc2 = ms.c_acc2;
	copy_n(ms.c_mes, c_length, c_mes);
	copy_n(ms.c_name, c_length, c_name);
	return *this;
}
bool Chat::operator==(const Chat& chat)
{
	if (this->c_acc1 == chat.c_acc1 && this->c_acc2 == chat.c_acc2)
		return true;
	else
		return false;
}

void Chat::erase()
{
	delete[] c_mes;
	delete[] c_name;
	c_mes = nullptr;
	c_name = nullptr;
	c_length = 0;
}
void Chat::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
	{
		return;
	}
	c_mes = new string[newLength];
	c_name = new string[newLength];
	c_length = newLength;
}
void Chat::resize(int newLength)
{
	if (newLength == c_length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	string* mes = new string[newLength];

	if (c_length > 0)
	{
		int elementsToCopy = (newLength > c_length) ? c_length : newLength;
		copy_n(c_mes, elementsToCopy, mes);
	}

	string* name = new string[newLength];

	if (c_length > 0)
	{
		int elementsToCopy = (newLength > c_length) ? c_length : newLength;
		copy_n(c_name, elementsToCopy, name);
	}

	delete[] c_mes;
	delete[] c_name;

	c_mes = mes;
	c_name = name;
	c_length = newLength;
}
int Chat::getLength() const
{
	return c_length;
}

void Chat::setAcc1(const Account& acc1)
{
	c_acc1 = acc1;
}
void Chat::setAcc2(const Account& acc2)
{
	c_acc2 = acc2;
}

void Chat::newMes(string send)
{
	string* name = new string[c_length + 1];

	copy_n(c_name, c_length, name);
	name[c_length] = send;
	delete[] c_name;
	c_name = name;

	string str;
	string* mes0 = new string[c_length + 1];

	cout << "Введите сообщение: ";
	copy_n(c_mes, c_length, mes0);
	cin.get();
	getline(cin, str);
	mes0[c_length] = str;

	delete[] c_mes;
	c_mes = mes0;
	++c_length;
	cout << "Сообщение отправлено!" << endl << endl;
}
void Chat::printMes(const Account& acc)
{
	cout << endl << "Ваш чат:" << endl;
	for (int i = 0; i < c_length; ++i)
	{
		cout << c_name[i] << ": " << c_mes[i] << endl;
	}
}



Messenger::Messenger()
{
	m_length = 0;
	m_chat = new Chat[m_length]();
}
Messenger::~Messenger()
{
	delete[] m_chat;
}

Messenger& Messenger::operator=(const Messenger& ch)
{
	if (&ch == this)
		return *this;
	reallocate(ch.getLength());
	copy_n(ch.m_chat, m_length, m_chat);
	return *this;
}
Chat& Messenger::operator[](int index)
{
	if (index < 0 || index >= m_length)
	{
	}
	return m_chat[index];
}

void Messenger::erase()
{
	delete[] m_chat;
	m_chat = nullptr;
	m_length = 0;
}
void Messenger::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
	{
		return;
	}
	m_chat = new Chat[newLength];
	m_length = newLength;
}
void Messenger::resize(int newLength)
{
	if (newLength == m_length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	Chat* chat = new Chat[newLength];

	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		copy_n(m_chat, elementsToCopy, chat);
	}

	delete[] m_chat;

	m_chat = chat;
	m_length = newLength;
}
int Messenger::getLength() const
{
	return m_length;
}

void Messenger::openChat(const Account& acc1, const Account& acc2, string send)
{
	int count = 0;
	Chat mes1(acc1, acc2);
	Chat mes2(acc2, acc1);
	for (int i = 0; i < m_length; ++i)
	{
		if (m_chat[i] == mes1 || m_chat[i] == mes2)
		{
			int choice;
			m_chat[i].printMes(acc1);
			cout << endl << "Вы хотите написать сообщение?" << endl
				<< "1. Да" << endl
				<< "2. Нет" << endl;
			cin >> choice;
			if (choice == 1)
			{
				m_chat[i].newMes(send);
			}
		}
		else
			++count;
	}
	if (count == m_length)
	{
		Chat* chat = new Chat[m_length + 1]();

		copy_n(m_chat, m_length, chat);

		chat[m_length].setAcc1(acc1);
		chat[m_length].setAcc2(acc2);

		cout << endl << "Чат создан!" << endl;

		int choice;
		cout << "Вы хотите написать сообщение?" << endl
			<< "1. Да" << endl
			<< "2. Нет" << endl;
		cin >> choice;
		if (choice == 1)
		{
			chat[m_length].newMes(send);
		}

		delete[] m_chat;
		m_chat = chat;
		++m_length;
	}
}
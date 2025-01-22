#include "Authorization.h"

Account::Account() = default;
Account::Account(string login, string password)
{
	_login = login;
	_password = password;
	_name = "";
	_surname = "";
}
Account::Account(string login, string password, string name, string surname)
{
	_login = login;
	_password = password;
	_name = name;
	_surname = surname;
}
void Account::setLogin(string login)
{
	_login = login;
}
void Account::setPassword(string password)
{
	_password = password;
}
void Account::setName(string name)
{
	_name = name;
}
void Account::setSurname(string surname)
{
	_surname = surname;
}
string Account::getLogin()
{
	return _login;
}
string Account::getPassword()
{
	return _password;
}
string Account::getName()
{
	return _name;
}
string Account::getSurname()
{
	return _surname;
}



bool Account::operator==(const Account& A)
{
	if (this->_login == A._login && this->_password == A._password)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& output, const Account& A)
{
	output << A._name << " " << A._surname << endl;

	return output;
}



Users::Users()
{
	m_length = 0;
	m_data = new Account[m_length]();
}
Users::~Users()
{
	delete[] m_data;
}

Users& Users::operator=(const Users& A)
{
	if (&A == this)
	{
		return *this;
	}
	reallocate(A.getLength());
	copy_n(A.m_data, m_length, m_data);
	return *this;
}
Account& Users::operator[](int index)
{
	if (index < 0 || index >= m_length)
	{
	}
	return m_data[index];
}

void Users::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}
void Users::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
	{
		return;
	}
	m_data = new Account[newLength];
	m_length = newLength;
}
void Users::resize(int newLength)
{
	if (newLength == m_length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	Account* data = new Account[newLength];

	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		copy_n(m_data, elementsToCopy, data);
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

void Users::Acc(string login, string password, string name, string surname)
{
	Account Acc(login, password, name, surname);
	
	Account* data = new Account[m_length + 1];
	copy_n(m_data, m_length, data);
	data[m_length] = Acc;

	delete[] m_data;
	m_data = data;
	++m_length;
}
void Users::NewAcc()
{
	Account Acc;
	string accData;
	cout << "Регистрация" << endl << endl
		<< "Введите Ваше имя: ";
	cin >> accData;
	Acc.setName(accData);
	cout << "Фамилия: ";
	cin >> accData;
	Acc.setSurname(accData);
	cout << "Придумайте логин: ";
	cin >> accData;
	Acc.setLogin(accData);
	cout << "Придумайте пароль: ";
	cin >> accData;
	Acc.setPassword(accData);

	Account* data = new Account[m_length + 1];
	copy_n(m_data, m_length, data);
	data[m_length] = Acc;

	delete[] m_data;
	m_data = data;
	++m_length;
}

int Users::getLength() const
{
	return m_length;
}

int Users::findAccount(string login, string password)
{
	Account Acc(login, password);

	bool A = false;
	
	for (int i = 0; i < m_length; i++)
	{
		if (m_data[i] == Acc)
		{
			return i;
			A = true;
		}
	}
	if (!A)
	{
		return -1;
		cout << endl << "Неверно введен логин или пароль.." << endl;
	}
}

string Users::friendsList(int index)
{
	int choice;
	for (int i = 0; i < m_length; ++i)
	{
		if (i == index)
			continue;
		cout << i + 1 << ". " << m_data[i] << endl;
	}
	cout << "С кем открыть чат?" << endl;
	cin >> choice;
	return m_data[choice - 1].getLogin();
}
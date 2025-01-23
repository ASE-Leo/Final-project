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

void Account::print()
{
	bool open = true;
	while (open)
	{
		cout << "Мой профиль:" << endl << endl
			<< "Имя: " << getName() << endl
			<< "Фамилия: " << getSurname() << endl << endl;

		int choice;
		cout << "1. Изменить данные" << endl
			<< "2. Назад" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			change();
			break;
		case 2:
			open = false;
			break;
		default:
			cout << "Такого варианта нет.. Попробуйте ещё раз" << endl;
			break;
		}
	}
}
void Account::change()
{
	int choice_2;
	string data;
	cout << endl << "Какие данные хотите изменить?" << endl
		<< "1. Имя" << endl
		<< "2. Фамилия" << endl
		<< "3. Изменить логин" << endl
		<< "4. Изменить пароль" << endl
		<< "5. Назад" << endl;
	std::cin >> choice_2;
	switch (choice_2)
	{
	case 1:
		cout << "Введите новое имя: ";
		std::cin >> data;
		setName(data);
		break;
	case 2:
		cout << "Введите новую фамилию: ";
		std::cin >> data;
		setSurname(data);
		break;
	case 3:
		cout << "Введите новый логин: ";
		std::cin >> data;
		setLogin(data);
		break;
	case 4:
		cout << "Введите новый пароль: ";
		std::cin >> data;
		setPassword(data);
		break;
	case 5:
		break;
	default:
		cout << "Такого варианта нет.. Попробуйте ещё раз" << endl;
		break;
	}
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
	std::cin >> accData;
	Acc.setName(accData);
	cout << "Фамилия: ";
	std::cin >> accData;
	Acc.setSurname(accData);
	cout << "Придумайте логин: ";
	std::cin >> accData;
	Acc.setLogin(accData);
	cout << "Придумайте пароль: ";
	std::cin >> accData;
	Acc.setPassword(accData);

	Account* data = new Account[m_length + 1];
	copy_n(m_data, m_length, data);
	data[m_length] = Acc;

	delete[] m_data;
	m_data = data;
	++m_length;

	cout << endl << "Ваш аккаунт успешно создан!" << endl << endl;
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
		return -1;
}
Account& Users::friendsList(int index)
{
	int choice;
	for (int i = 0; i < m_length; ++i)
	{
		if (i == index)
			continue;
		cout << i + 1 << ". " << m_data[i];
	}

	std::cin >> choice;
	return m_data[choice - 1];
}
int Users::Login()
{
	string login, password;
	cout << "Для входа необходимо ввести логин: ";
	std::cin >> login;
	cout << "Введите пароль: ";
	std::cin >> password;
	return findAccount(login, password);
}
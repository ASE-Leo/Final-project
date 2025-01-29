#include "Authorization.h"

Users::Users()
{
	m_length = 0;
	m_data = new Account<std::string>[m_length]();
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
	std::copy_n(A.m_data, m_length, m_data);
	return *this;
}
Account<std::string>& Users::operator[](int index)
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
	m_data = new Account<std::string>[newLength];
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

	Account<std::string>* data = new Account<std::string>[newLength];

	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		std::copy_n(m_data, elementsToCopy, data);
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

void Users::Acc(std::string login, std::string password, std::string name, std::string surname)
{
	Account<std::string> Acc(login, password, name, surname);
	
	Account<std::string>* data = new Account<std::string>[m_length + 1];
	std::copy_n(m_data, m_length, data);
	data[m_length] = Acc;

	delete[] m_data;
	m_data = data;
	++m_length;
}
void Users::NewAcc()
{
	Account<std::string> Acc;
	std::string accData;
	bool open = true;
	std::cout << "Регистрация" << std::endl << std::endl
		<<  "Придумайте логин: ";
	std::cin >> accData;
	for (int i = 0; i < m_length; ++i)
	{
		if (accData == m_data[i].getLogin())
		{
			std::cout << std::endl << "Аккаунт с таким логином уже существует.." << std::endl;
			open = false;
		}
	}
	if (open)
	{
		Acc.setLogin(accData);
		std::cout << "Введите Ваше имя : ";
		std::cin >> accData;
		Acc.setName(accData);
		std::cout << "Фамилия: ";
		std::cin >> accData;
		Acc.setSurname(accData);
		std::cout << "Придумайте пароль: ";
		std::cin >> accData;
		Acc.setPassword(accData);

		Account<std::string>* data = new Account<std::string>[m_length + 1];
		std::copy_n(m_data, m_length, data);
		data[m_length] = Acc;

		delete[] m_data;
		m_data = data;
		++m_length;

		std::cout << std::endl << "Ваш аккаунт успешно создан!" << std::endl << std::endl;
	}
}
void Users::recovery()
{
	char choice;
	std::string login, password, name, surname;
	int count = 0;
	std::cout << std::endl << "Восстановить пароль по: " << std::endl << "1. По логину" << std::endl
		<< "2. По имени и фамилии" << std::endl << std::endl
		<< "3. Назад" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case '1':
		std::cout << std::endl << "Введите логин: ";
		std::cin >> login;
		for (int i = 0; i < m_length; ++i)
		{
			if (m_data[i].getLogin() == login)
			{
				char choice_2;
				std::cout << std::endl << m_data[i] << "Это ваш аккаунт?" << std::endl
					<< "1. Да" << std::endl << "2. Нет" << std::endl;
				std::cin >> choice_2;
				if (choice_2 == '1')
				{
					std::cout << std::endl << "Введите новый пароль:";
					std::cin >> password;
					m_data[i].setPassword(password);
					std::cout << "Ваш пароль успешно изменен!" << std::endl;
				}
			}
			else
				++count;
		}
		if (count == m_length)
			std::cout << std::endl << "Такого аккаунта не существует.." << std::endl;
		break;
	case '2':
		std::cout << std::endl << "Ваше имя: ";
		std::cin >> name;
		std::cout << "Ваша фамилия: ";
		std::cin >> surname;
		for (int i = 0; i < m_length; ++i)
		{
			if (m_data[i].getName() == name && m_data[i].getSurname() == surname)
			{
				char choice_2;
				std::cout << std::endl << "Логин - " << m_data[i].getLogin() << std::endl
					<< m_data[i] << "Это ваш аккаунт?" << std::endl
					<< "1. Да" << std::endl << "2. Нет" << std::endl;
				std::cin >> choice_2;
				if (choice_2 == '1')
				{
					std::cout << std::endl << "Введите новый пароль:";
					std::cin >> password;
					m_data[i].setPassword(password);
					std::cout << "Ваш пароль успешно изменен!" << std::endl;
				}
			}
			else
				++count;
		}
		if (count == m_length)
			std::cout << std::endl << "Такого аккаунта не существует.." << std::endl;
		break;
	default:
		break;
	}
}

int Users::getLength() const
{
	return m_length;
}

int Users::findAccount(std::string login, std::string password)
{
	Account<std::string> Acc(login, password);

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
int Users::friendsList(int index)
{
	bool open = true;
	while (open)
	{
		int choice;
		for (int i = 0; i < m_length; ++i)
		{
			if (i == index)
				continue;
			std::cout << i + 1 << ". " << m_data[i];
		}

		std::cout << m_length + 1 << ". Общий чат" << std::endl
			<< m_length + 2 << ". Назад" << std::endl;
		std::cin >> choice;
		if (choice > 0 && choice <= m_length + 2)
			return choice - 1;
		else
			std::cout << "Такого варианта нет.. Попробуйте ещё раз" << std::endl;
	}
}
int Users::Login()
{
	std::string login, password;
	std::cout << "Для входа необходимо ввести логин: ";
	std::cin >> login;
	std::cout << "Введите пароль: ";
	std::cin >> password;
	return findAccount(login, password);
}
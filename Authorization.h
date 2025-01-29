// В данном файле хранятся аккаунты, здесь осуществляется вход в определенный аккаунт и управление им.

#pragma once
#include <iostream>
#include <string>
#include <algorithm>


                               // Класс, который хранит всю информацию об аккаунте
							   // (данный класс не задумывался как шаблон,
							   // поэтому и реализация данного класа была прописана в файле Authorization.ccp,
							   // но позже для демонстрации того, что тема шаблонов была усвоена,
							   // пришлось пожертвовать реализацие в Authorization.ccp, тк наблюдались ошибки)

template <typename T> 
class Account
{
protected:
	T _login;
	T _password;
	T _name;
	T _surname;
public:
	Account<T>() = default;
	Account(T login, T password)
	{
		_login = login;
		_password = password;
		_name = "";
		_surname = "";
	}
	Account(T login, T password, T name, T surname)
	{
		_login = login;
		_password = password;
		_name = name;
		_surname = surname;
	}
	void setLogin(T login)
	{
		_login = login;
	}
	void setPassword(T password)
	{
		_password = password;
	}
	void setName(T name)
	{
		_name = name;
	}
	void setSurname(T surname)
	{
		_surname = surname;
	}
	T getLogin()
	{
		return _login;
	}
	T getPassword()
	{
		return _password;
	}
	T getName()
	{
		return _name;
	}
	T getSurname()
	{
		return _surname;
	}

	// Эта выводит всю информацию об аккаунте
	// и при необходимости вызывает функцию, 
	// которая позволяет вносить изменения в данные
	void print()
	{
		bool open = true;
		while (open)
		{
			std::cout << "Мой профиль:" << std::endl << std::endl
				<< "Имя: " << getName() << std::endl
				<< "Фамилия: " << getSurname() << std::endl << std::endl;

			char choice;
			std::cout << "1. Изменить данные" << std::endl
				<< "2. Назад" << std::endl;
			std::cin >> choice;

			switch (choice)
			{
			case '1':
				change();
				break;
			case '2':
				open = false;
				break;
			default:
				std::cout << "Такого варианта нет.. Попробуйте ещё раз" << std::endl;
				break;
			}
		}
	}  
	// функция, для изменения данных
	void change()
	{
		char choice_2;
		T data;
		std::cout << std::endl << "Какие данные хотите изменить?" << std::endl
			<< "1. Имя" << std::endl
			<< "2. Фамилия" << std::endl
			<< "3. Изменить логин" << std::endl
			<< "4. Изменить пароль" << std::endl
			<< "5. Назад" << std::endl;
		std::cin >> choice_2;
		switch (choice_2)
		{
		case '1':
			std::cout << "Введите новое имя: ";
			std::cin >> data;
			setName(data);
			break;
		case '2':
			std::cout << "Введите новую фамилию: ";
			std::cin >> data;
			setSurname(data);
			break;
		case '3':
			std::cout << "Введите новый логин: ";
			std::cin >> data;
			setLogin(data);
			break;
		case '4':
			std::cout << "Введите новый пароль: ";
			std::cin >> data;
			setPassword(data);
			break;
		case '5':
			break;
		default:
			std::cout << "Такого варианта нет.. Попробуйте ещё раз" << std::endl;
			break;
		}
	}

	bool operator==(const Account<std::string>& A)
	{
		if (this->_login == A._login && this->_password == A._password) 
			return true;
		else
			return false;
	}
	friend std::ostream& operator<<(std::ostream& output, const Account<std::string>& A)
	{
		output << A._name << " " << A._surname << std::endl;
		//Данный вывод я использовал только для вывода списка друзей, поэтому вывожу только имя и фамилию

		return output;
	}
};

                            // Класс, который хранит в себе все аккаунты и управляет ими

class Users
{
private:
	int m_length;
	Account<std::string>* m_data;
public:
	Users();
	~Users();

	Users& operator=(const Users& A);
	Account<std::string>& operator[](int index);

	void erase();
	void reallocate(int newLegth);
	void resize(int nweLength);

	void Acc(std::string login, std::string password, std::string name, std::string surname); // Создаем аккаунт с данными, которые передаем аргументами
	void NewAcc(); // Создаем новый аккаунт и заполняем данные с консоли (т.е. Регистрация)
	void recovery(); // Функция восстановления пароля 

	int getLength() const; 

	int findAccount(std::string login, std::string password); // При помощи этой функции осуществляется вход в аккаунт. Она вохвращает номер аккаунта в контейнере данных
	int friendsList(int index); // Список всех друзей + общий чат
	int Login(); // Авторизация
};
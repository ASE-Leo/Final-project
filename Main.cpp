#include "Authorization.h"


int main(int argc, char* argv[])
{
	bool open = true;
	Users Us;
	Chat Ch;
	Us.Acc("qwe", "123", "Victor", "Moon");
	Us.Acc("ewq", "321", "Semion", "Bob");
	while (open)
	{
		int choice;
		cout << "Добрый день!" << endl
			<< "Мы рады видеть Вас в нашем чате." << endl
			<< "Для начала работы Вам необходимо войти в свой аккаунт или зарегистрироваться, если Вы ещё не пользовались нашим чатом." << endl << endl
			<< "1. Вход" << endl << "2. Зарегистрироваться" << endl << "3. Выход из программы" << endl;
		cin >> choice;
		if (choice == 1)
		{
			string login, password;
			int i;
			cout << "Для входа необходимо ввести логин: ";
			cin >> login;
			cout << "Введите пароль: ";
			cin >> password;
			i = Us.findAccount(login, password);
			if (i < 0)
				return 0;
			cout << "Здравствуйте, " << Us[i].getName() << "!" << endl;

			//bool open_2 = true;
			//while (open_2)
			{
				int choice_2;
				cout << "1. Мой аккаунт" << endl
					<< "2. Сообщения" << endl
					<< "3. Выйти" << endl;
				cin >> choice_2;

				if (choice_2 == 2)
				{
					cout << "Кому Вы хотите написать сообщение?" << endl;
					string fr = Us.friendsList(i);
					Ch.openChat(Us[i].getLogin(), fr);
					//Ch.newChat(Us[i].getLogin(), fr);
				}
			}
		}
		if (choice == 2)
		{
			Us.NewAcc();
		}
		if (choice == 3)
		{
			cout << "Хорошего дня!";
			open = false;
			break;
		}
	}
	return 0;
}
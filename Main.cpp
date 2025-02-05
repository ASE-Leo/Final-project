#include "Authorization.h"
#include "Chat.h"


int main(int argc, char* argv[])
{
	bool open = true;
	Users Us;
	Messenger Ch;
	Us.Acc("qwe", "123", "Victor", "Moon");
	Us.Acc("ewq", "321", "Semion", "Bob");
	Ch.general();
	while (open)
	{
		char choice;
		cout << endl << "Добрый день!" << endl
			<< "Мы рады видеть Вас в нашем чате." << endl
			<< "Для начала работы Вам необходимо войти в свой аккаунт или зарегистрироваться, если Вы ещё не пользовались нашим чатом." << endl << endl
			<< "1. Вход" << endl << "2. Зарегистрироваться" << endl << endl << "3. Забыли пароль?" << endl << "4. Выход из программы" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			int i = Us.Login();
			if (i >= 0)
			{
				cout << endl << "Здравствуйте, " << Us[i].getName() << "!" << endl;

				bool open_2 = true;
				while (open_2)
				{
					char choice_2;
					int k;
					cout << endl << "1. Мой профиль" << endl
						<< "2. Сообщения" << endl
						<< "3. Выйти" << endl;
					cin >> choice_2;

					switch (choice_2)
					{
					case '1':
						Us[i].print();
						break;
					case '2':
						cout << endl << "С кем открыть чат?" << endl;
						k = Us.friendsList(i);
						if (k < Us.getLength())
							Ch.openChat(Us[i], Us[k], Us[i].getName());
						if (k == Us.getLength())
							Ch.openChat(Us[i].getName());
						break;
					case '3':
						open_2 = false;
						cout << "До свидания, " << Us[i].getName() << "!" << endl << endl;
						break;
					default:
						cout << "Такого варианта нет.. Попробуйте ещё раз" << endl;
						break;
					}
				}
			}
			else
			{
				cout << endl << "Неверно введен логин или пароль.. Попробуйте ещё раз" << endl << endl;
				continue;
			}
			break;
		}
		case '2':
			Us.NewAcc();
			continue;
			break;
		case '3':
			Us.recovery();
			break;
		case '4':
			cout << "Хорошего дня!";
			open = false;
			break;
		default:
			cout << "Такого варианта нет.. Попробуйте ещё раз" << endl << endl;
			break;
		}
	}
	return 0;
}
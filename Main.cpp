#include "Authorization.h"


int main(int argc, char* argv[])
{
	Users Us;
	Us.Acc("qwe", "123", "Victor", "Moon");
	Us.Acc("ewq", "321", "Semion", "Bob");
	int choice;
	cout << "Добрый день!" << endl
		<< "Мы рады видеть Вас в нашем чате." << endl
		<< "Для начала работы Вам необходимо войти в свой аккаунт или зарегистрироваться, если Вы ещё не пользовались нашим чатом." << endl << endl
		<< "1. Вход" << endl << "2. Зарегистрироваться" << endl << endl;
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
		cout << "Здравствуйте, " << Us[i].getName() << "!";
	}
	if (choice == 2)
	{
		Us.NewAcc();
	}
	return 0;
}
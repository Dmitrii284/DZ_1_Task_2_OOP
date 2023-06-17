#include"PhoneBook.h"
#include"PhonInfo.h"
#include <string>

int main()
{
	setlocale(LC_ALL, "Rus");
	PhoneBook A;	
	int selectFrom = 0;
	do
	{
		selectFrom = A.Select();
		if (selectFrom == 1) // вывод на экран
		{
		A.PrintAllAbonents();
		}
		else if (selectFrom == 2)// добавление записи
		{
			A.PrintAllAbonents();
			A.AddAbonent();
		}
		else if (selectFrom == 3) // удаление записи
		{
			A.PrintAllAbonents();
			int num1;
				std::cout << "Введите номер для удаления -> ";
				std::cin >> num1;			
				A.EraseRec(num1 - 1);
		}
		else if (selectFrom == 4) //Найти запись.
		{
			A.PrintAllAbonents();
			std::string str;
			std::cout << "Введите ФИО для поиска абонента\n";
			std::cin.ignore();
			std::getline(std::cin, str);
			A.SubscriberSearch(str);
			break;
		}
	} while (selectFrom != 5);
	return 0;
}
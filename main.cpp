#include <iostream>
#include "Auto_repair_station.h"
#include "Motorcycle.h"
#include "Car.h"
#include <Windows.h>
#include <deque>

using namespace::std;

int show_menu()
{
	int a;
	cout << "Выберете действие:" << endl;
	cout << "1 - просмотр транспорта на ремонте" << endl;
	cout << "2 - добавить в мастерскую" << endl;
	cout << "3 - забрать из мастерской" << endl;
	cout << "4 - изменить информацию о ТС" << endl;
	cout << "5 - показать проблемы и стоимость ремонта" << endl;
	cout << "0 - Завершение программы" << endl << endl;
	cin >> a;
	return (a);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	deque<Car> variabl1;
	deque<Motorcycle> variabl2;
	do
	{
		int a = show_menu();
		switch (a)
		{
		case 1: 
		{
			cout << "Автомобили: " << endl << "____________________________________________________" << endl;
			for (deque<Car>::iterator i = variabl1.begin(); i != variabl1.end(); i++)
			{
				cout << *i;
			};
			cout << "Мотоциклы: " << endl << "____________________________________________________" << endl;;
			for (deque<Motorcycle>::iterator i = variabl2.begin(); i != variabl2.end(); i++)
			{
				cout << *i;
			};
			break;
		}
		case 2: 
			{
			cout << "Если у вас автомобиль нажмите 1, если мотоцикл 2: ";
			int p;
			cin >> p;
			if (p == 1)
			{
				cout << "Введите данные" << endl;
				Car q;
				cin >> q;
				variabl1.push_back(q);
			}
			else
			{
				cout << "Введите данные" << endl;
				Motorcycle q;
				cin >> q;
				variabl2.push_back(q);
			}
		}
			 break;
		case 3: 
			{
				cout << "Если хотите забрать автомобиль нажмите 1, если мотоцикл 2: ";
				int p;
				cin >> p;
				if (p == 1) 
				{
					cout << "Автомобили: " << endl << "____________________________________________________" << endl;
					for (deque<Car>::iterator i = variabl1.begin(); i != variabl1.end(); i++)
					{
						cout << (*i).get_name() << "\t";
					};
					cout << "Введите название автомобиля котороый хотите забрать: " << endl;
					string q;
					cin >> q;
					int flag = 0;
					for (deque<Car>::iterator i = variabl1.begin(); i != variabl1.end(); i++)
					{
						if (q == (*i).get_name())
						{
							variabl1.erase(i);
							flag = 1;
							break;
						}
					}
					if (!flag) cout << "Нет такого автомобиля, возможно вы ошиблись" << endl;
				}
				else
				{
					cout << "Мотоциклы: " << endl << "____________________________________________________" << endl;
					for (deque<Motorcycle>::iterator i = variabl2.begin(); i != variabl2.end(); i++)
					{
						cout << (*i).get_name() << "\t";
					};
					cout << "Введите название мотоццикла который хотите забрать: " << endl;
					string q;
					cin >> q;
					int flag = 0;
					for (deque<Car>::iterator i = variabl1.begin(); i != variabl1.end(); i++)
					{
						if (q == (*i).get_name())
						{
							variabl1.erase(i);
							flag = 1;
							break;
						}
					}
					if (!flag) cout << "Нет такого мотоцикла, возможно вы ошиблись" << endl;
				}
			  }
			 break;
		case 4:
			{
				  cout << "Если хотите что-то поменять у автомобиля нажмите 1, если мотоцикл 2: ";
				  int p;
				  cin >> p;
				  if (p == 1)
				  {
					  cout << "Автомобили: " << endl << "____________________________________________________" << endl;
					  for (deque<Car>::iterator i = variabl1.begin(); i != variabl1.end(); i++)
					  {
						  cout << (*i).get_name() << "\t";
					  };
					  cout << "Введите название автомобиля котороый хотите заменить: " << endl;
					  string q;
					  cin >> q;
					  int flag = 0;
					  for (deque<Car>::iterator i = variabl1.begin(); i != variabl1.end(); i++)
					  {
						  if (q == (*i).get_name())
						  {
							  cout << "Введите новые значения: ";
							  Car a;
							  cin >> a;
							  variabl1.insert(i, a);
							  variabl1.erase(i + 1);
							  flag = 1;
							  break;
						  }
					  }
					  if (!flag) cout << "Нет такого автомобиля, возможно вы ошиблись" << endl;
				  }
				  else
				  {
					  cout << "Мотоциклы: " << endl << "____________________________________________________" << endl;
					  for (deque<Motorcycle>::iterator i = variabl2.begin(); i != variabl2.end(); i++)
					  {
						  cout << (*i).get_name() << "\t";
					  };
					  cout << "Введите название мотоцикла котороый хотите заменить: " << endl;
					  string q;
					  cin >> q;
					  int flag = 0;
					  for (deque<Motorcycle>::iterator i = variabl2.begin(); i != variabl2.end(); i++)
					  {
						  if (q == (*i).get_name())
						  {
							  cout << "Введите новые значения: ";
							  Motorcycle a;
							  cin >> a;
							  variabl2.insert(i, a);
							  variabl2.erase(i + 1);
							  flag = 1;
							  break;
						  }
					  }
					  if (!flag) cout << "Нет такого мотоцикла, возможно вы ошиблись" << endl;
				  }
			  }
			 break;
		case 5 :
			{
			cout << "Если хотите посмотреть поломки автомобиля нажмите 1, если мотоцикла 2: ";
			int p;
			cin >> p;
			if (p == 1)
			{
				deque<Car>::iterator i = variabl1.begin();
				(*i).show_problems();
				(*i).show_cost();
			}
			else
			{
				deque<Motorcycle>::iterator i = variabl2.begin();
				(*i).show_problems();
				(*i).show_cost();
			}
		}
			break;
		case 0: return 0;
		}
	} while (1);
}
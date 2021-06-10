#include "Motorcycle.h"
#include <ctime>

Motorcycle::Motorcycle(string a, int b) : Vehicle(a, b)
{

}

Motorcycle::Motorcycle()
{

}

Motorcycle::~Motorcycle() {}

void Motorcycle::show_problems()
{
	int i = rand() % 3 + 1;
	list_of_problems(i);
}

void Motorcycle::show_cost()
{
	double i = (rand() % 9001 + 100) / (rand() % 10 + 1);
	cout << "Стоимость ремонта мотоцикла: " << i;
}

string Motorcycle::get_type()
{
	return type;
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other)
{
	this->name = other.name;
	this->year = other.year;
	return (*this);
}

ostream& operator<<(ostream& out, Motorcycle& other)
{
	out << other.get_type() << endl << "Название мотоцикл: " << other.get_name() << endl
		<< "Год выпуска: " << other.get_year() << endl;
	return out;
}

void Motorcycle::list_of_problems(int j)
{
	int i;
	int* z = new int[j];
	for (int k = 0; k < j; k++)
		z[k] = 0;
	for (int q = 0; q < j; q++)
	{
		int flag;
		do
		{
			srand(time(NULL));
			i = rand() % 6 + 1;
			for (int k = 0; k < j; k++)
			{
				if (z[k] == i)
				{
					flag = 1;
					break;
				}
				else flag = 0;
			}
		} while (flag);
		z[q] = i;
		switch (i)
		{
		case 1: cout << "Неисправна рабочая тормозная система" << endl; break;
		case 2:	cout << "Неисправна ситема питания" << endl; break;
		case 3: cout << "Неисправен рулевоей демпфер" << endl; break;
		case 4: cout << "Неиспрана передняя фара" << endl; break;
		case 5: cout << "Неисправна выхлопная система" << endl; break;
		case 6: cout << "Неисправность двигателя" << endl; break;
		}
	}
}
#include "Car.h"
#include <ctime>

Car::Car(string a, int b) : Vehicle(a, b)
{

}

Car::Car()
{
	part.set_name("Unknown");
	part.set_cost(0);
}

Car ::~Car() {}

string Car::get_type()
{
	return type;
}

void Car::show_problems()
{
	int i = rand() % 4 + 1;
	list_of_problems(i);
}

void Car::show_cost()
{
	double i = (rand() % 9001 + 100) * (rand() % 10 + 1) / ((rand() % 10 + 1) + (rand() % 11 + 5));
	cout << "Стоимость ремонта автомобиля: " << i;
}

Car& Car::operator=(const Car& other)
{
	this->name = other.name;
	this->year = other.year;
	this->part = other.part;
	return (*this);
}

ostream& operator<<(ostream& out, Car& other)
{
	out << other.get_type() << endl << "Название автомобиля: " << other.get_name() << endl
		<< "Год выпуска: " << other.get_year() << endl << other.part << endl;
	return out;
}

istream& operator>>(istream& in, Car& other)
{
	cout << "Введите название автомобиля: ";
	in >> other.name;
	cout << "Введите год выпуска автомобиля: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.year));
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.part));
	cout << endl;
	return in;
}

//_______________________________________________________


Spare_parts::Spare_parts()
{
	name = "Unknown";
	cost = 0;
}

Spare_parts::Spare_parts(string a, double b)
{
	name = a;
	cost = b;
}

void Spare_parts::set_name(string a)
{
	name = a;
}

void Spare_parts::set_cost(double a)
{
	cost = a;
}

Spare_parts::~Spare_parts() {}

string Spare_parts::get_name()
{
	return name;
}

double Spare_parts::get_cost()
{
	return cost;
}

Spare_parts& Spare_parts::operator=(const Spare_parts& other)
{
	this->name = other.name;
	this->cost = other.cost;
	return (*this);
}

bool Spare_parts::operator==(const Spare_parts& other)
{
	if (this->name == other.name && this->cost == other.cost)
		return (1);
	return (0);
}

ostream& operator<<(ostream& out, const Spare_parts& other)
{
	out << "Запчасть: " << endl << "Название: " << other.name << endl <<
		"Стоимость: " << other.cost << endl << endl;
	return out;
}

istream& operator>>(istream& in, Spare_parts& other)
{
	cout << "Введите название запчасти: ";
	in >> other.name;
	cout << "Введите стоимость запчасти : ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.cost));
	cout << endl;
	return in;
}



void Car::list_of_problems(int j)
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
		case 2:	cout << "Неисправна стояночнная тормозная система " << endl; break;
		case 3: cout << "Неисправно рулевое управление" << endl; break;
		case 4: cout << "Неиспраны дневные ходовые огни" << endl; break;
		case 5: cout << "Неисправны стеклоочистители" << endl; break;
		case 6: cout << "Неисправность двигателя" << endl; break;
		}
	}
}
#include "Vehicle.h"

Vehicle::Vehicle()
{
	name = "Unknown";
	year = 0;
}

Vehicle::Vehicle(string a, int b)
{
	name = a;
	year = b;
}

string Vehicle::get_name()
{
	return name;
}

int Vehicle::get_year()
{
	return year;
}

void Vehicle::set_name(string a)
{
	this->name = a;
}

void Vehicle::set_year(int a)
{
	this->year = a;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	this->name = other.name;
	this->year = other.year;
	return (*this);
}

bool Vehicle::operator==(const Vehicle& other)
{
	if (this->name == other.name && this->year == other.year)
		return (1);
	return (0);
}

ostream& operator<<(ostream& out, const Vehicle& other)
{
	out << "�������� ��: " << other.name << endl << "��� �������: " << other.year << endl;
	return out;
}

istream& operator>>(istream& in, Vehicle& other)
{
	cout << "������� �������� ��: ";
	in >> other.name;
	cout << "������� ��� ������� ��: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.year));
	cout << endl;
	return in;
}

void Vehicle::show_problems()
{

};
void Vehicle::show_cost()
{

};
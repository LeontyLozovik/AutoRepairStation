#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace::std;

class Spare_parts
{
private:
	string name;
	double cost;
public:
	Spare_parts();
	Spare_parts(string a, double b);
	~Spare_parts();
	string get_name();
	double get_cost();
	void set_name(string);
	void set_cost(double);
	Spare_parts& operator=(const Spare_parts& other);
	bool operator==(const Spare_parts& other);
	friend ostream& operator<<(ostream& out, const Spare_parts& other);
	friend istream& operator>>(istream& in, Spare_parts& other);
};


class Car : public Vehicle
{
private:
	const string type = "Автомобиль";
	Spare_parts part;
public:
	Car();
	Car(string a, int b);
	~Car();
	void show_problems() override;
	void show_cost() override;
	string get_type();
	Car& operator=(const Car& other);
	friend ostream& operator<<(ostream& out, Car& other);
	friend istream& operator>>(istream& in, Car& other);
	void list_of_problems(int);
};
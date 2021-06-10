#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace::std;

class Motorcycle : public Vehicle
{
private:
	const string type = "Mотоцикл";
public:
	Motorcycle(string a, int b);
	Motorcycle();
	~Motorcycle();
	void show_problems() override;
	void show_cost() override;
	string get_type();
	Motorcycle& operator=(const Motorcycle& other);
	friend ostream& operator<<(ostream& out, Motorcycle& other);
	void list_of_problems(int);
};
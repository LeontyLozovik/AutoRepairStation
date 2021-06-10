#pragma once
#include"Auto_repair_station.h"
#include <iostream>
using namespace::std;

class Vehicle : public Auto_repair_station
{
protected:
	string name;
	int year;
public:
	Vehicle();
	Vehicle(string, int);
	~Vehicle() {};
	string get_name();
	int get_year();
	void set_name(string);
	void set_year(int);
	Vehicle& operator=(const Vehicle& other);
	bool operator==(const Vehicle& other);
	friend ostream& operator<<(ostream& out, const Vehicle& other);
	friend istream& operator>>(istream& in, Vehicle& other);

	void show_problems();
	void show_cost();
};

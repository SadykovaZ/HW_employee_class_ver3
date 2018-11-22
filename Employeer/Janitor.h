#pragma once
#include "Employee.h"
class Janitor :
	public Employee
{
	bool harmConditions;
public:
	Janitor(string name, int age, string sex, int workYears, bool harmConditions);
	void setConditions(bool harmConditions);
	bool getConditions() const { return harmConditions;	}

	void info()const override;
	double getSalary()const override;
};


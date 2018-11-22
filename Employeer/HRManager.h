#pragma once
#include "Employee.h"
class HRManager :
	public Employee
{
	bool hasEdu;
public:
	HRManager(string name, int age, string sex, int workYears, bool hasEdu);
	void setHasEdu(bool hasEdu);
	bool getHasEdu()const { return hasEdu; }

	void info()const override;
	double getSalary()const override;

	
};


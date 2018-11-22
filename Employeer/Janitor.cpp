#include "Janitor.h"
Janitor::Janitor(string name, int age, string sex, int workYears, bool harmConditions)
	:Employee(name, age, sex, workYears)
{
	this->harmConditions = harmConditions;
}
void Janitor::setConditions(bool harmConditions)
{
	this->harmConditions = harmConditions;
}
void Janitor::info() const
{
	Employee::info();
	cout << "Janitor works in harmful conditions?: " << boolalpha << harmConditions << endl;
}
double Janitor::getSalary() const
{
	double coef = harmConditions * 0.15;
	coef += getWorkYears()*0.05;
	return coef;
}

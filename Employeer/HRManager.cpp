#include "HRManager.h"
HRManager::HRManager(string name, int age, string sex, int workYears, bool hasEdu)
	:Employee(name, age, sex, workYears)
{
	this->hasEdu = hasEdu;
}

void HRManager::setHasEdu(bool hasEdu)
{
	this->hasEdu = hasEdu;
}
void HRManager::info() const
{
	Employee::info();
	cout << "Has education: " << boolalpha << hasEdu << endl;
	
}
double HRManager::getSalary() const
{
	double coef = hasEdu * 0.02;
	coef += getWorkYears()*0.05;
	return coef;
}

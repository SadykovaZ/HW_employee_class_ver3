#pragma once
#include "Organization.h"
#include <iostream>
#include "Acounter.h"
#include "Director.h"
#include "Proger.h"
#include <Windows.h>
#include <conio.h>
#include "HRManager.h"
#include"Janitor.h"
using namespace std;

class OrganizationConsole
{
	
public:
	Organization org;
	OrganizationConsole();
	void start();
private:
	void startMenu();
	void mainMenu();
	void addEmpMenu();
	void removeEmpMenu();
	void showInfo()const;

	void setOrgNameMenu();
	void setSalaryMenu();
	void setEmpInfoMenu();
	void showShortInfo() const;
	void clearScreen()const { system("cls"); }
	void pause()const { system("pause"); }
	void editEmpMenu(Employee* emp);
	void editEmpInfo(Employee* emp);
	void changePosition(Employee* emp);

};


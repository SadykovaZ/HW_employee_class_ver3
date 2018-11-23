#include "OrganizationConsole.h"
#include<iomanip>


OrganizationConsole::OrganizationConsole()
	:org("", 0)
{	
	startMenu();	
}
void OrganizationConsole::start()
{
	mainMenu();
}
void OrganizationConsole::startMenu()
{
	system("cls");
	cout << "Welcome!";
	Sleep(2000);
	this->setOrgNameMenu();
	this->setSalaryMenu();
}
void OrganizationConsole::mainMenu()
{
	int choise = 0;
	while (choise != 5)
	{
		system("cls");
		MainM:
		cout << "Organization name: " << org.getName();
		cout << "\nSalary: " << org.getBaseSalary();
		cout << "\nCount of employee: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\
		1. add new employee\n\
		2. dismiss employee\n\
		3. show employee info\n\
                4. show selected employee info\n\
		5. exit\n"
			;
		cin >> choise;
		switch (choise)
		{
		case 1:
			addEmpMenu();
			break;
		case 2:
			removeEmpMenu();
			break;
		case 3:
			showInfo();
			system("pause");
			break;
		case 4:
			for (int i = 0; i < org.getCountOfEmployee(); i++)
			{
				cout << setw(3) << left << org[i].getId()
					<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
					<< setw(10) << left << org[i].getName() << endl;
			}
			cout << "Choose employee to show info: ";
			int id;
			cin >> id;
			org.showEmpInfo(id);
			cout << "Want to change information or dismiss? (1- yes change info, 2- no just dismiss, 3- no, back to main menu): ";
			int ch1;
			cin >> ch1;
			if (ch1 == 1)
			{
				org.changeEmpInfo(id);
				cout << endl;
				cout << "Information changed!" << endl;
				cout << "----------------------------\n";
				org.showEmpInfo(id);
				cout << "Press 1 to return to Main menu: ";
				int ch2;
				cin >> ch2;
				if (ch2 == 1)
				{
					system("cls");
					goto MainM;
				}
			}
			else if (ch1 == 2)
			{
				org.removeEmployeeById(id);
				cout << "Employee dismissed!\n";
				cout << "----------------------------\n";
				cout << "Press 1 to return to Main menu: ";
				int ch2;
				cin >> ch2;
				if (ch2 == 1)
				{
					system("cls");
					goto MainM;
				}
			}
			else if (ch1 == 3)
			{
				system("cls");
				goto MainM;
			}
			system("pause");
			break;
		case 5:
			break;
		default:
			cout << "Unknown command\npress any key to continue\n";
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "Bye bye\n";
}
void OrganizationConsole::addEmpMenu()
{
	size_t ch;
	while (1) {
		system("cls");
		cout << "choose position\n";
		cout << "1. Accounter\n2. Proger\n3. Director\n4. HR Manager\n5.Janitor\n6.Main menu";
		cin >> ch;
		if (ch > 6) {
			cout << "uknown position\n";
			system("pause");
		}
		else
			break;

	}
	if (ch == 6)
		return;
	string name;
	int age;
	string sex;
	int exp;
	system("cls");
	cout << "Set employee name\n";
	cin >> name;
	cout << "set employee age\n";
	cin >> age;
	cout << "set employee sex\n";
	cin >> sex;
	cout << "set employee experience\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool k1c;
		cout << "1c experience? 1 or 0\n";
		cin >> k1c;
		emp = new Acounter(name, age, sex, exp, k1c);
		break;
	case 2:
		int cntLang;
		bool edu;
		cout << "Set count of known languages\n";
		cin >> cntLang;
		cout << "High education? 1 or 0\n";
		cin >> edu;
		emp = new Proger(name, age, sex, exp, cntLang, edu);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		bool edu1;
		cout << "Education?" << endl;
		cin >> edu1;
		emp = new HRManager(name, age, sex, exp, edu1);
		break;
	case 5:
		bool harm;
		cout << "Harmful conditions?" << endl;
		cin >> harm;
		emp = new Janitor(name, age, sex, exp, harm);
		break;
	}
	system("cls");
	org.addEmployee(emp);
	cout << "Employee added!\n";
	system("pause");
}
void OrganizationConsole::removeEmpMenu()
{
	while (1) {
		system("cls");
		cout << "Choose Id of employee to remove" << endl;
		for (int i = 0; i < org.getCountOfEmployee(); i++)
		{
			cout << setw(3) << left << org[i].getId()
				<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
				<< setw(10) << left << org[i].getName() << endl;

		}
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		cout << "Employee dismissed!\n";
		system("pause");
		return;
	}
}
void OrganizationConsole::showInfo() const
{
	system("cls");
	org.getInfo();
}
void OrganizationConsole::setOrgNameMenu()
{
	system("cls");
	cout << "Set organization name\n";
	string name;
	cin >> name;
	org.setName(name);
}
void OrganizationConsole::setSalaryMenu()
{
	system("cls");
	cout << "Set salary\n";
	int sal;
	cin >> sal;
	org.setBaseSalary(sal);
}



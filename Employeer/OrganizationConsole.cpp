#include "OrganizationConsole.h"
#include<iomanip>


OrganizationConsole::OrganizationConsole()
	:org("", 0)
{
	//startMenu();
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
		3. show organization info\n\
                4. show employee info\n\
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
			setEmpInfoMenu();
			/*for (int i = 0; i < org.getCountOfEmployee(); i++)
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
			system("pause");*/
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
		showShortInfo();
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

void OrganizationConsole::setEmpInfoMenu()
{
	while (1)
	{
		clearScreen();
		showShortInfo();
		cout << "0- Go back";

		cout << "Choose employee\'s id: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmpById(ch);

		if (e == nullptr)
		{
			cout << "incorrectd id\n";
			pause();
			continue;
		}

		editEmpMenu(e);
		//break;
	}

}

void OrganizationConsole::showShortInfo() const
{
	for (int i = 0; i < org.getCountOfEmployee(); i++)
	{
		cout << setw(3) << left << org[i].getId()
			<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
			<< setw(10) << left << org[i].getName() << endl;

	}
}

void OrganizationConsole::editEmpMenu(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*emp).name()).substr(6) << endl;
		emp->info();
		cout << "1. Change employee info\n";
		cout << "2. Dismiss employee info\n";
		cout << "3. Change position\n";
		cout << "0. Back\n";
		int ch;
		cin >> ch;



		switch (ch)
		{
		case 0:
			return;
		case 1:
			editEmpInfo(emp);
			break;
		case 2:
			org.removeEmployeeById(emp->getId());
			cout << "Employee dissmised!" << endl;
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;


		default:
			cout << "Unknown command";
			break;

		}
	}


}

void OrganizationConsole::editEmpInfo(Employee * emp)
{

	while (1)
	{
		clearScreen();
		emp->info();
		int index = 0;
		cout << "\nChoose information to change\n ";
		cout << ++index << ". Name\n";
		cout << ++index << ". Age\n";
		cout << ++index << ". Sex\n";
		cout << ++index << ". Experinece in years\n";
		int pos;
		if (typeid(*emp) == typeid(Proger))
		{
			pos = 1;
			cout << ++index << ". count of known languages\n";
			cout << ++index << ". has education\n";
		}
		else if (typeid(*emp) == typeid(Acounter))
		{
			pos = 2;
			cout << ++index << ". 1C experience \n";
		}
		else if (typeid(*emp) == typeid(HRManager))
		{
			pos = 3;
			cout << ++index << ". Education \n";
		}
		else if (typeid(*emp) == typeid(Janitor))
		{
			pos = 4;
			cout << ++index << ". Works in harmful conditions \n";
		}
		cout << "0. go back";

		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "Unknown command";
			pause();
			continue;
		}


		switch (ch)
		{
		case 0: return;
			break;
		case 1:
		{
			string name;
			cout << "\n Enter new name: ";
			cin >> name;
			emp->setName(name);

			break;
		}
		case 2:
		{
			int age;
			cout << "\n Enter new age: ";
			cin >> age;
			emp->setAge(age);

			break;
		}
		case 3:

		{
			string sex;
			cout << "\n Enter new sex: ";
			cin >> sex;
			emp->setSex(sex);

			break;
		}
		case 4:
		{
			int exp;
			cout << "\n Enter new exp: ";
			cin >> exp;
			emp->setWorkYears(exp);

			break;
		}
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 5)
				{
					cout << "Enter new count of known languages\n";
					int cnt;
					cin >> cnt;
					((Proger*)emp)->setCntLang(cnt);
				}
				else
				{
					cout << "Eductaion (1-y, 2-0)";
					bool ed;
					cin >> ed;
					((Proger*)emp)->setHasEdu(ed);
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				break;
			}
		}

		break;
		}
	}
	pause();
}

void OrganizationConsole::changePosition(Employee * emp)
{

	while (1)
	{
		clearScreen();
		cout << "Choose new position of " << emp->getPosition() << " " << emp->getName();
		cout << "1. Proger\n";
		cout << "2. Acounter\n";
		cout << "3. Janitor\n";
		cout << "4. Direcor\n";
		cout << "5. HR Manager\n";
		cout << "0. Go back";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5)
		{
			cout << "Unknown command\n";
			pause();
			continue;
		}
		Employee *e = nullptr;
		switch (ch)
		{
		case 1:
			e = new Proger(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		case 2:
			e = new Acounter(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 3:
			e = new Janitor(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 4:
			e = new Proger(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		case 5:
			e = new Proger(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		}
		org.addEmployee(e);
		org.removeEmployeeById(emp->getId());
		
		return;
	}
}



#include <iostream>
#include <Windows.h>

using namespace std;

class Employee
{
protected:
	string name;
public:
	Employee(string Name) : name(Name) {}

	virtual double Salary_calculation() = 0;

	virtual void ShowInfo()
	{
		cout << "��'�: " << name << endl;
	}
};

class EmployeeWithHourlyPay : public Employee
{
private:
	double salary_per_hour;
	int hours;
public:
	EmployeeWithHourlyPay(string name, double salary, int hours_worked) : Employee(name), salary_per_hour(salary), hours(hours_worked) {}

	double Salary_calculation() override
	{
		return salary_per_hour * hours;
	}

	void ShowInfo() override
	{
		Employee::ShowInfo();
		cout << "��� ��������: ����������\n��������: " << Salary_calculation() << " ���" << endl;
	}
};

class EmployeeWithMonthlyPay : public Employee
{
private:
	double salary_per_mouth;
public:
	EmployeeWithMonthlyPay(string name, double salary) : Employee(name), salary_per_mouth(salary) {}

	double Salary_calculation() override
	{
		return salary_per_mouth;
	}

	void ShowInfo() override
	{
		Employee::ShowInfo();
		cout << "��� ��������: �����\n��������: " << Salary_calculation() << " ���" << endl;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	EmployeeWithHourlyPay employee1("����", 400, 108);
	EmployeeWithMonthlyPay employee2("����", 60000);

	employee1.ShowInfo();
	employee2.ShowInfo();

	return 0;

}


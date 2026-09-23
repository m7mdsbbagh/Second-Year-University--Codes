#include <iostream>
#include <vector>

struct stEmployee
{
	std::string firstName = "";
	std::string lastName = "";
	float salary = 0;
};

bool shouldContinue(std::string message)
{
	char choice = ' ';

	std::cout << "\n" << message << "? ";
	std::cin >> choice;
	std::cout << std::endl;

	return choice == 'y' || choice == 'Y';
}

void readEmployeeInfo(std::string& firstName, std::string& lastName, float &salary)
{
	std::cout << "Enter the First Name : ";
	std::cin >> firstName;             

	std::cout << "Enter the Last Name  : ";
	std::cin >> lastName;

	std::cout << "Enter the Salary     : ";
	std::cin >> salary;
}

void readEmployeesInfo(std::vector <stEmployee> &vEmployees)
{
	stEmployee temp;

	bool isContinue = false;

	do {
		readEmployeeInfo(temp.firstName, temp.lastName, temp.salary);
		vEmployees.push_back(temp);

		isContinue = shouldContinue("Do you want to read more employees? Y/N ");
	} while (isContinue);
}

void printEmployeesInfo(std::vector <stEmployee>& vEmployees)
{
	std::cout << "\n\n      Employees Vector\n";
	std::cout << "--------------------------------\n";
	for (const stEmployee& employee : vEmployees)
	{
		std::cout << "First Name : " << employee.firstName << "\n";
		std::cout << "Last Name  : " << employee.lastName << "\n";
		std::cout << "Salary     : " << employee.salary;
		std::cout << "\n--------------------------------\n";
	}
}

int main()
{
	std::vector <stEmployee> vEmployees;

	readEmployeesInfo(vEmployees);
	printEmployeesInfo(vEmployees);

	return 0;
}

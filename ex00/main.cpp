#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat Bureaucrat1("Timmy", 150);
	Bureaucrat Bureaucrat2(Bureaucrat1);
	Bureaucrat Bureaucrat3("Timmy", 140);

	Bureaucrat3 = Bureaucrat1;

	std::cout << Bureaucrat1 << std::endl;
	std::cout << Bureaucrat2 << std::endl;
	std::cout << Bureaucrat3 << std::endl;


	try {
		Bureaucrat Bureaucrat4("Timmy", 500);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat Bureaucrat4("Timmy", 0);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	Bureaucrat1.incrementGrade();
	std::cout << Bureaucrat1 << std::endl;
	Bureaucrat1.decrementGrade();
	std::cout << Bureaucrat1 << std::endl;

	try {
		Bureaucrat1.decrementGrade();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat Bureaucrat4("Timmy", 1);
		Bureaucrat4.incrementGrade();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
}

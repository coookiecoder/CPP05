#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat Bureaucrat1("Timmy", 150);
	Bureaucrat Bureaucrat2("Timmy", 20);

	std::cout << Bureaucrat1 << std::endl;
	std::cout << Bureaucrat2 << std::endl;

	ShrubberyCreationForm Form1;
	ShrubberyCreationForm Form2;
	ShrubberyCreationForm Form3;

	Form1.beSigned(Bureaucrat2);
	Form2.beSigned(Bureaucrat1);

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;

	RobotomyRequestForm Form4;
	RobotomyRequestForm Form5;
	RobotomyRequestForm Form6;

	Form4.beSigned(Bureaucrat2);
	Form4.beSigned(Bureaucrat1);

	std::cout << Form4 << std::endl;
	std::cout << Form5 << std::endl;
	std::cout << Form6 << std::endl;

	PresidentialPardonForm Form7;
	PresidentialPardonForm Form8;
	PresidentialPardonForm Form9;

	Form7.beSigned(Bureaucrat2);
	Form7.beSigned(Bureaucrat1);

	std::cout << Form7 << std::endl;
	std::cout << Form8 << std::endl;
	std::cout << Form9 << std::endl;
}
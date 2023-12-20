#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat Bureaucrat1("Timmy", 150);
	Bureaucrat Bureaucrat2("Timmy", 1);

	std::cout << Bureaucrat1 << std::endl;
	std::cout << Bureaucrat2 << std::endl;

	ShrubberyCreationForm Form1("house1");
	ShrubberyCreationForm Form2("house2");
	ShrubberyCreationForm Form3("house3");

	Form1.beSigned(Bureaucrat2);
	Form2.beSigned(Bureaucrat1);

	Form1.execute(Bureaucrat1);
	Form1.execute(Bureaucrat2);
	Form2.execute(Bureaucrat2);

	Bureaucrat1.executeForm(Form1);
	Bureaucrat2.executeForm(Form1);
	Bureaucrat2.executeForm(Form2);

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;

	RobotomyRequestForm Form4("idiot1");
	RobotomyRequestForm Form5("idiot2");
	RobotomyRequestForm Form6("idiot3");

	Form4.beSigned(Bureaucrat2);
	Form4.beSigned(Bureaucrat1);

	Form4.execute(Bureaucrat1);
	Form4.execute(Bureaucrat2);
	Form5.execute(Bureaucrat2);

	Bureaucrat1.executeForm(Form4);
	Bureaucrat2.executeForm(Form4);
	Bureaucrat2.executeForm(Form5);

	std::cout << Form4 << std::endl;
	std::cout << Form5 << std::endl;
	std::cout << Form6 << std::endl;

	PresidentialPardonForm Form7("person1");
	PresidentialPardonForm Form8("person2");
	PresidentialPardonForm Form9("person3");

	Form7.beSigned(Bureaucrat2);
	Form7.beSigned(Bureaucrat1);

	Form7.execute(Bureaucrat1);
	Form7.execute(Bureaucrat2);
	Form8.execute(Bureaucrat2);

	Bureaucrat1.executeForm(Form7);
	Bureaucrat2.executeForm(Form7);
	Bureaucrat2.executeForm(Form8);

	std::cout << Form7 << std::endl;
	std::cout << Form8 << std::endl;
	std::cout << Form9 << std::endl;
}
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

	try {
		Form1.beSigned(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form2.beSigned(Bureaucrat1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Form1.execute(Bureaucrat1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form1.execute(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form2.execute(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat1.executeForm(Form1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Bureaucrat2.executeForm(Form1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Bureaucrat2.executeForm(Form2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;

	RobotomyRequestForm Form4("idiot1");
	RobotomyRequestForm Form5("idiot2");
	RobotomyRequestForm Form6("idiot3");

	try {
		Form4.beSigned(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form4.beSigned(Bureaucrat1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Form4.execute(Bureaucrat1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form4.execute(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form5.execute(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat1.executeForm(Form4);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Bureaucrat2.executeForm(Form4);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Bureaucrat2.executeForm(Form5);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	std::cout << Form4 << std::endl;
	std::cout << Form5 << std::endl;
	std::cout << Form6 << std::endl;

	PresidentialPardonForm Form7("person1");
	PresidentialPardonForm Form8("person2");
	PresidentialPardonForm Form9("person3");

	try {
		Form7.beSigned(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form7.beSigned(Bureaucrat1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Form7.execute(Bureaucrat1);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form7.execute(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form8.execute(Bureaucrat2);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat1.executeForm(Form7);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Bureaucrat2.executeForm(Form7);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Bureaucrat2.executeForm(Form8);
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	std::cout << Form7 << std::endl;
	std::cout << Form8 << std::endl;
	std::cout << Form9 << std::endl;
}

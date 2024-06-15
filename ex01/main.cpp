#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat Bureaucrat1("Timmy", 150);
	Bureaucrat Bureaucrat2("Timmy", 20);

	std::cout << Bureaucrat1 << std::endl;
	std::cout << Bureaucrat2 << std::endl;

	Form Form1("FormA", 100, 90);
	Form Form2("FormB", 100, 90);
	Form Form3("FormC", 100, 90);

	try {
		Form1.beSigned(Bureaucrat1);
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		Form1.beSigned(Bureaucrat2);
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		Form3.beSigned(Bureaucrat1);
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;

	try {
		Bureaucrat2.signedForm(Form2);
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		Bureaucrat2.signedForm(Form2);
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		Bureaucrat1.signedForm(Form3);
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;
}

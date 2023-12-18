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

	Form1.beSigned(Bureaucrat1);
	Form1.beSigned(Bureaucrat2);
	Form3.beSigned(Bureaucrat1);

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;

	Bureaucrat2.signedFormat(Form2);
	Bureaucrat2.signedFormat(Form2);
	Bureaucrat1.signedFormat(Form3);

	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;
}
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

	Bureaucrat Bureaucrat4("Timmy", 500);
	Bureaucrat Bureaucrat5("Timmy", 0);
}
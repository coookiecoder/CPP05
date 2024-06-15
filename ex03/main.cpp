#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {
	Bureaucrat JeanMichelPasRandom("Jean michel", 1);
	Intern JeanMichelRandom;
	AForm *buffer;

	buffer = JeanMichelRandom.makeForm("shrubbery creation", "prout1");

	buffer->beSigned(JeanMichelPasRandom);
	buffer->execute(JeanMichelPasRandom);

	delete buffer;

	buffer = JeanMichelRandom.makeForm("robotomy request", "prout2");

	buffer->beSigned(JeanMichelPasRandom);
	buffer->execute(JeanMichelPasRandom);

	delete buffer;

	buffer = JeanMichelRandom.makeForm("presidential pardon", "prout3");

	buffer->beSigned(JeanMichelPasRandom);
	buffer->execute(JeanMichelPasRandom);

	delete buffer;
}

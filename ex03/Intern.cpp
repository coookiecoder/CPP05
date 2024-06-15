#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

Intern::Intern(void) {

}

Intern::Intern(Intern &src) {
	(void) src;
}

Intern& Intern::operator=(Intern &src) {
	(void) src;
	return *this;
}

Intern::~Intern(void) {

}

AForm *Intern::makeForm(std::string form, std::string target) {
	std::string form_avaible[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int cursor = 0; cursor < 3; cursor++) {
		if (form_avaible[cursor] == form) {
			std::cout << "Intern creates " << form_avaible[cursor] << " form" << std::endl;
			try {
			switch (cursor) {
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
				}
			} catch (std::exception &error) {
				std::cout << error.what() << std::endl;
				return (NULL);
			}
		}
	}

	std::cout << "form : " << form << " not found" << std::endl;
	return (NULL);
}

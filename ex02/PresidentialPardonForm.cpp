#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy) {

}

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(std::string target) {
	std::cout << target << std::endl;
}
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy) {
	this->target = copy.target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) {
	if (!this->getSigned())
		throw Bureaucrat::NotSigned();
	else if (this->getGradeExecute() >= executor.getGrade())
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw GradeTooLowException();
}

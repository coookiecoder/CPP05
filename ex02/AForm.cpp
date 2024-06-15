#include "AForm.hpp"

const char * AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	this->isSigned = false;
}

AForm::AForm(const AForm &src) : name(src.name), gradeRequiredToSign(src.gradeRequiredToSign), gradeRequiredToExecute(src.gradeRequiredToExecute) {
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	this->isSigned = src.isSigned;
}

AForm & AForm::operator=(const AForm &copy) {
	this->isSigned = copy.isSigned;
	return *this;
}

AForm::~AForm() {
	
}

void AForm::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > gradeRequiredToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

std::string AForm::getName(void) const{
	return this->name;
}

bool AForm::getSigned(void) const {
	return this->isSigned;
}

int AForm::getGradeSign(void) const {
	return this->gradeRequiredToSign;
}

int AForm::getGradeExecute(void) const {
	return this->gradeRequiredToExecute;
}

std::ostream &operator<<(std::ostream &output, AForm const &input) {
	if (input.getSigned())
		output << input.getName() << " Form, " << input.getGradeSign() << " needed to sign, " << input.getGradeExecute() << " needed to execute, is signed : true";
	else
		output << input.getName() << " Form, " << input.getGradeSign() << " needed to sign, " << input.getGradeExecute() << " needed to execute, is signed : false";
	return output;
}

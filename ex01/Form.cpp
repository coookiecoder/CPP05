#include "Form.hpp"

const char * Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
	try {
		if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const GradeTooHighException& e) {
		std::cerr << "GradeTooHighException: " << e.what() << '\n';
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
	this->isSigned = false;
}

Form::Form(const Form &src) : name(src.name), gradeRequiredToSign(src.gradeRequiredToSign), gradeRequiredToExecute(src.gradeRequiredToExecute) {
	try {
		if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const GradeTooHighException& e) {
		std::cerr << "GradeTooHighException: " << e.what() << '\n';
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
	this->isSigned = src.isSigned;
}

Form & Form::operator=(const Form &copy) {
	this->isSigned = copy.isSigned;
	return *this;
}

Form::~Form() {
	
}

void Form::beSigned(Bureaucrat bureaucrat) {
	try {
		if (bureaucrat.getGrade() > gradeRequiredToSign)
			throw Form::GradeTooLowException();
		else
			this->isSigned = true;
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
}

std::string Form::getName(void) const{
	return this->name;
}

bool Form::getSigned(void) const {
	return this->isSigned;
}

int Form::getGradeSign(void) const {
	return this->gradeRequiredToSign;
}

int Form::getGradeExecute(void) const {
	return this->gradeRequiredToExecute;
}

std::ostream &operator<<(std::ostream &output, Form const &input) {
	if (input.getSigned())
		output << input.getName() << " Form, " << input.getGradeSign() << " needed to sign, " << input.getGradeExecute() << " needed to execute, is signed : true";
	else
		output << input.getName() << " Form, " << input.getGradeSign() << " needed to sign, " << input.getGradeExecute() << " needed to execute, is signed : false";
	return output;
}
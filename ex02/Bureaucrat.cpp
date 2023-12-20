#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char * Bureaucrat::NotSigned::what() const throw() {
	return "Form is not signed!";
}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : name(name), grade(grade) {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const GradeTooHighException& e) {
		std::cerr << "GradeTooHighException: " << e.what() << '\n';
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade()) {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const GradeTooHighException& e) {
		std::cerr << "GradeTooHighException: " << e.what() << '\n';
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat &copy) {
	this->grade = copy.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	
}

const std::string & Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::signedForm(AForm &form) {
	if (form.getSigned())
		std::cout << this->name << " couldn't sign " << form.getName() << " because form already signed" << std::endl;
	else {
		form.beSigned(*this);
		if (form.getSigned())
			std::cout << this->name << " signed " << form.getName() << std::endl;
		else
			std::cout << this->name << " couldn't sign " << form.getName() << " because grade too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form) {
	try {
		if (!form.getSigned())
			throw Bureaucrat::NotSigned();
		else if (form.getGradeExecute() >= this->getGrade())
		{
			form.execute(*this);
			std::cout << this->name << " executed " << form.getName() << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
	catch (const NotSigned& e){
		std::cerr << "NotSigned: " << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input) {
	output << input.getName() << ", bureaucrat grade " << input.getGrade();
	return output;
}
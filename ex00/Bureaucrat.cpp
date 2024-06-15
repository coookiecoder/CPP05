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

Bureaucrat::Bureaucrat(const std::string & name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade()) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::incrementGrade() {
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input) {
	output << input.getName() << ", bureaucrat grade " << input.getGrade();
	return output;
}

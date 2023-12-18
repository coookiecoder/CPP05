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

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input) {
	output << input.getName() << ", bureaucrat greade " << input.getGrade();
	return output;
}
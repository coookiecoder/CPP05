#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy) {
	this->target = copy.target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 127) {
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
	try {
		if (!this->getSigned())
			throw Bureaucrat::NotSigned();
		else if (executor.getGrade() <= this->getGradeExecute())
		{
			std::string fileName = target + "_shrubbery";
			std::ofstream file(fileName.c_str(), std::fstream::trunc);
			if (file.is_open())
			{
			    file << "  ^  \n / \\ \n/   \\ \n-----\n";
			    file.close();
			}
		}
		else
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException& e) {
		std::cerr << "GradeTooLowException: " << e.what() << '\n';
	}
	catch (const Bureaucrat::NotSigned& e) {
		std::cerr << "NotSigned: " << e.what() << '\n';
	}
}
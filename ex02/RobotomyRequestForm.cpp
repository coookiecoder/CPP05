#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy) {
	this->target = copy.target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) {
	try {
		if (!this->getSigned())
			throw Bureaucrat::NotSigned();
		else if (executor.getGrade() <= this->getGradeExecute())
		{
			srand(time(0));
			int success = rand() % 2;

			if (success) {
			    std::cout << this->target << " has been robotomized successfully.\n";
			}
			else {
				std::cout << this->target << " robotomy failed.\n";
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
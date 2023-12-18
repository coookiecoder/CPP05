#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy) {

}

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(std::string target) {
	std::cout << target << std::endl;
}
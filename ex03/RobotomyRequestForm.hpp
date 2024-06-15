#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
    public: 
        RobotomyRequestForm(RobotomyRequestForm &copy); 
        RobotomyRequestForm(std::string target); 
        ~RobotomyRequestForm(void); 
        void execute(Bureaucrat const &executor);
};

#endif
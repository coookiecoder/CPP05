#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public: 
        RobotomyRequestForm(RobotomyRequestForm &copy); 
        RobotomyRequestForm(void); 
        ~RobotomyRequestForm(void); 
        void execute(std::string target); 
};

#endif
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
    public:
        PresidentialPardonForm(PresidentialPardonForm &copy);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);
        void execute(Bureaucrat const &executor);
};

#endif
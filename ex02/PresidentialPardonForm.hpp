#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(PresidentialPardonForm &copy);
        PresidentialPardonForm(void);
        ~PresidentialPardonForm(void);
        void execute(std::string target);
};

#endif
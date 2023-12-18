#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		void execute(std::string target);
};
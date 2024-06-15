#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	private:

	public:
		Intern(void);
		Intern(Intern &src);
		Intern& operator=(Intern &src);
		~Intern(void);
		AForm *makeForm(std::string form, std::string target);
};

#endif

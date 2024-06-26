#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <ostream>
# include <stdexcept>
# include <string>
# include <iostream>

class Form;

class Bureaucrat {
	private:
	    const std::string name;
	    int grade;
		Bureaucrat(void);
	public:
	    Bureaucrat(const std::string & name, int grade);
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat &operator=(Bureaucrat &copy);
		~Bureaucrat(void);
    	const std::string & getName(void) const;
	    int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signedForm(Form &form);

	public:
	    class GradeTooHighException : public std::exception {
	        public:
	            const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception {
	        public:
	            const char* what() const throw();
	    };
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input);

#endif

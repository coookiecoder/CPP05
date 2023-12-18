#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
# include <string>

class Form {
	private:
	    const std::string name;
	    bool isSigned;
	    const int gradeRequiredToSign;
	    const int gradeRequiredToExecute;
		Form(void);
	public:
	    Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		~Form(void);
		void beSigned(Bureaucrat bureaucrat);
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeSign(void) const;
		int getGradeExecute(void) const;

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

std::ostream &operator<<(std::ostream &output, Form const &input);

#endif
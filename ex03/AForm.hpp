#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm {
	private:
	    const std::string name;
	    bool isSigned;
	    const int gradeRequiredToSign;
	    const int gradeRequiredToExecute;
		AForm(void);
	public:
	    AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm(void);
		void beSigned(Bureaucrat bureaucrat);
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeSign(void) const;
		int getGradeExecute(void) const;
		virtual void execute(Bureaucrat const &executor) = 0;

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

std::ostream &operator<<(std::ostream &output, AForm const &input);

#endif

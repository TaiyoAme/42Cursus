/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:31 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/18 17:22:10 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
public:
	virtual ~AForm();

	const std::string getName() const;
	bool isSigned() const;
	const int getSignGrad() const;
	const int getExecGrad() const;
	void beSigned(Bureaucrat &b);
	void execute(Bureaucrat const & executor) const;
	virtual void executeForm() const = 0;
	class GradeTooHighException : public std::exception{
	public:
		explicit GradeTooHighException();
		const char* what() const noexcept override;

	private:
		const char *msg = "Grade to high !";
	};

	class GradeTooLowException : public std::exception{
	public:
		explicit GradeTooLowException();
		const char* what() const noexcept override;

	private:
		const char *msg = "Grade to low !";
	};

	class FormNotSignedException : public std::exception{
	public:
		explicit FormNotSignedException();
		const char* what() const noexcept override;

	private:
		const char *msg = "Form not signed !";
	};


private:
	const std::string name_;
	bool signed_ = false;
	const int sign_;
	const int exec_;
protected:
	AForm();
	AForm(const AForm &copy);
	AForm(std::string name, int sign, int exec);
	AForm &operator=(const AForm &copy);
};
std::ostream &operator<<(std::ostream &os, const AForm &ref);

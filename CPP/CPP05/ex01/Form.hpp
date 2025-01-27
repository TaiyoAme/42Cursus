/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:31 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 19:39:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
public:
	Form();
	Form(const Form &copy);
	Form(std::string name, int sign, int exec);
	Form &operator=(const Form &copy);
	~Form();

	const std::string getName() const;
	bool isSigned() const;
	const int getSignGrad() const;
	const int getExecGrad() const;
	void beSigned(Bureaucrat &b);

private:
	const std::string name_;
	bool signed_ = false;
	const int sign_;
	const int exec_;

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

};
std::ostream &operator<<(std::ostream &os, const Form &ref);

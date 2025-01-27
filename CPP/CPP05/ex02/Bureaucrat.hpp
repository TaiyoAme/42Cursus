/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:54:32 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/17 18:35:37 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
private:
	std::string name_;
	int	grade_;


public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	std::string	getName();
	int	getGrade() const;
	void promote();
	void demote();
	void signForm(AForm &f);
	void executeForm(AForm const & form);
	~Bureaucrat();
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
std::ostream& operator<<(std::ostream& os, Bureaucrat& ref);

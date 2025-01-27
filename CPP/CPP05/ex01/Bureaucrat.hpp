/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:54:32 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 19:20:15 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	std::string	getName();
	int	getGrade();
	void promote();
	void demote();
	void signForm(Form &f);
	~Bureaucrat();

private:
	std::string name_;
	int	grade_;

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

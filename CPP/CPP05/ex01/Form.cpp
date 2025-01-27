/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:18:46 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 19:39:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form() : name_("no name"), exec_(1), sign_(1)
{
	std::cout << "Form DEFAULT constructor called" << std::endl;
};

Form::Form(const Form &copy) : name_(copy.name_), exec_(copy.exec_), sign_(copy.sign_)
{
	std::cout << "Form COPY constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int exec) : name_(name), signed_(false), sign_(sign), exec_(exec)
{
	std::cout << "Form(args) constructor called" << std::endl;
	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Form COPY assignement called" << std::endl;

	if (this != &copy)
	{
		this->signed_ = copy.signed_;
	}
	return (*this);
}
Form::~Form()
{
	std::cout << "Form deconstructor called" << std::endl;
}

const std::string Form::getName() const
{
	return (this->name_);
}

bool Form::isSigned() const
{
	return (this->signed_);
}

const int Form::getSignGrad() const
{
	return (this->sign_);
}

const int Form::getExecGrad() const
{
	return (this->exec_);
}

void Form::beSigned(Bureaucrat &b)
{
	try {
		if (b.getGrade() > this->getSignGrad())
			throw Form::GradeTooLowException();
		this->signed_ = true;
	} catch (Form::GradeTooLowException& e) {
		std::cout << "Exception caught : " << e.what() <<std::endl;
	}
}

Form::GradeTooLowException::GradeTooLowException(){};
const char* Form::GradeTooLowException::what() const noexcept
{
	return (this->msg);
}

Form::GradeTooHighException::GradeTooHighException(){};
const char* Form::GradeTooHighException::what() const noexcept
{
	return (this->msg);
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
	os	<< "| Form | Name : " <<ref.getName() << " | Signed : " << ref.isSigned() 
		<< " | Sign grade(min) : " << ref.getSignGrad() << " | Exec grade(min) : " 
		<< ref.getExecGrad() << " |";
	return (os);
}

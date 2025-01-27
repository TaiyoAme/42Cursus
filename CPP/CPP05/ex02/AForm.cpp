/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:18:46 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/18 17:57:38 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <string>

AForm::AForm() : name_("no name"), exec_(1), sign_(1)
{
	std::cout << "AForm DEFAULT constructor called" << std::endl;
};

AForm::AForm(const AForm &copy) : name_(copy.name_), exec_(copy.exec_), sign_(copy.sign_)
{
	std::cout << "AForm COPY constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign, int exec) : name_(name), signed_(false), sign_(sign), exec_(exec)
{
	std::cout << "AForm(args) constructor called" << std::endl;
	if (sign > 150 || exec > 150)
		throw AForm::GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "AForm COPY assignement called" << std::endl;

	if (this != &copy)
	{
		this->signed_ = copy.signed_;
	}
	return (*this);
}
AForm::~AForm()
{
	std::cout << "AForm deconstructor called" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name_);
}

bool AForm::isSigned() const
{
	return (this->signed_);
}

const int AForm::getSignGrad() const
{
	return (this->sign_);
}

const int AForm::getExecGrad() const
{
	return (this->exec_);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrad())
		throw Bureaucrat::GradeTooLowException();
	else if(this->isSigned() == false)
	{
		this->signed_ = true;
		std::cout << this->getName() << " was signed by " << b.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " is already signed" << std::endl;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw FormNotSignedException();	
	if (this->getExecGrad() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	this->executeForm();
}

AForm::GradeTooLowException::GradeTooLowException(){};
const char* AForm::GradeTooLowException::what() const noexcept
{
	return (this->msg);
}

AForm::GradeTooHighException::GradeTooHighException(){};
const char* AForm::GradeTooHighException::what() const noexcept
{
	return (this->msg);
}

AForm::FormNotSignedException::FormNotSignedException(){};
const char* AForm::FormNotSignedException::what() const noexcept
{
	return (this->msg);
}

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
	os	<< "| AForm | Name : " <<ref.getName() << " | Signed : " << ref.isSigned() 
		<< " | Sign grade(min) : " << ref.getSignGrad() << " | Exec grade(min) : " 
		<< ref.getExecGrad() << " |";
	return (os);
}

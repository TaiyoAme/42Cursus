/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:54:19 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/18 17:55:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : name_("No name"), grade_(150)
{
	std::cout << "Bureaucrat DEFAULT constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	std::cout << "Bureaucrat(name, grade) constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.name_), grade_(copy.grade_)
{
	std::cout << "Bureaucrat COPY constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat COPY assignment called" << std::endl;
	if (this != &copy)
	{
		this->name_ = copy.name_;
		this->grade_ = copy.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

void	Bureaucrat::executeForm(const AForm &form)
{
	form.execute(*this);
	std::cout << this->getName() << " executed (ExecuteForm)" << form.getName() << std::endl;
}

std::string Bureaucrat::getName()
{
	return (this->name_);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::promote()
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void	Bureaucrat::demote()
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

void Bureaucrat::signForm(AForm &f)
{
	if (this->getGrade() > f.getSignGrad())
		throw Bureaucrat::GradeTooLowException();
	f.beSigned(*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(){};
const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (this->msg);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(){};
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (this->msg);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
	return os;
}

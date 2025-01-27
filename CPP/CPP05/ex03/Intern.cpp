/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:56:56 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/20 17:21:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <functional>
#include <string>

Intern::Intern()
{
	std::cout << "Intern DEFAULT constructor called" << std::endl;
}
Intern::Intern(const Intern &copy)
{
	std::cout << "Intern COPY constructor called" << std::endl;
}
Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	return *this;
};

static AForm *createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(std::string form_name, std::string form_target)
{
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *(*form_func[])(std::string target) = {&createPresidentialPardonForm, &createRobotomyRequestForm,&createShrubberyForm};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			std::cout << "Intern creates " << forms[i] << " now" << std::endl;
			return (form_func[i](form_target));
		}
	}
	std::cout << "\033[33mIntern can not create a form called " << form_name << "\033[0m" << std::endl;
	return (NULL);
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
};


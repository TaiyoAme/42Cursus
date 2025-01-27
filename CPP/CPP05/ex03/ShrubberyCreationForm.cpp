/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:04:46 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/18 18:39:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), target_("null")
{
	std::cout << "TS" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm::AForm(copy.getName(), copy.getSignGrad(), copy.getExecGrad()), target_(copy.target_){};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->target_ = copy.target_;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm desconstructor called" << std::endl;
};

void ShrubberyCreationForm::executeForm() const
{
	std::string test = this->target_;
	 std::string drawing = 
        "             /\\\n"
        "            <  >\n"
        "             \\/\n"
        "             /\\\n"
        "            /  \\\n"
        "           /++++\\\n"
        "          /  ()  \\\n"
        "          /      \\\n"
        "         /~`~`~`~`\\\n"
        "        /  ()  ()  \\\n"
        "        /          \\\n"
        "       /*&*&*&*&*&*&\\\n"
        "      /  ()  ()  ()  \\\n"
        "      /              \\\n"
        "     /++++++++++++++++\\\n"
        "    /  ()  ()  ()  ()  \\\n"
        "    /                  \\\n"
        "   /~`~`~`~`~`~`~`~`~`~`\\\n"
        "  /  ()  ()  ()  ()  ()  \\\n"
        "  /*&*&*&*&*&*&*&*&*&*&*&\\\n"
        " /                        \\\n"
        "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\\n"
        "           |   |\n"
        "          |`````|\n"
        "          \\_____/";
	std::ofstream file(test.append("_shrubbery").c_str());

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return ;
    }

    file << drawing << std::endl;
    file.close();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:28:36 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/18 18:44:10 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_("no target"){};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target)
{

}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getSignGrad(), copy.getExecGrad()), target_(copy.target_){};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->target_ = copy.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::executeForm() const
{
	static int seed = 12345;
	std::srand(seed++);
    int random_value = std::rand() % 2;

    if (random_value == 0) {
        std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy failed" << std::endl;
    }
}

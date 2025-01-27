/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:34:02 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/25 17:12:49 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base()
{
	std::cout << "Base DEFAULT constructor called" << std::endl;
}

Base*	generate(void)
{
	int	randomNb = rand() % 3;
	switch (randomNb) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Found A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "Found B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "Found C" << std::endl;
	}
	else 
	{
		std::cout << "Not matched" << std::endl;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Found A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Found B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Found C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Not A, B or C" <<std::endl;
			}
			
		}
	
	}
}

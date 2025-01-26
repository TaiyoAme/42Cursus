/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:20:51 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:16:17 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>
#include <ostream>

Fixed::Fixed()
{
	std::cout << "Default contructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy contructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int rawBits)
{
	std::cout << "Int contructor called" << std::endl;
	this->rawBits = (rawBits << this->fraction);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->rawBits = copy.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const float rawBits)
{
	std::cout << "Float contructor called" << std::endl;
	this->rawBits = roundf(rawBits * (1 << this->fraction));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Destructor called" << std::endl;
	this->rawBits = raw;
}

int	Fixed::toInt() const
{
	return (this->rawBits >> this->fraction);
}

float Fixed::toFloat() const
{
	return (float)this->rawBits / (1 << this->fraction);
}

std::ostream	&operator<<(std::ostream	&os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

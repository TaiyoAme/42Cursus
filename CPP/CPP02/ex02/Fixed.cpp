/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:20:51 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/24 17:00:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>
#include <ostream>

Fixed::Fixed()
{
	//std::cout << "Default contructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy contructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int rawBits)
{
	//std::cout << "Int contructor called" << std::endl;
	this->rawBits = (rawBits << this->fraction);
}

Fixed::Fixed(const float rawBits)
{
	//std::cout << "Float contructor called" << std::endl;
	this->rawBits = roundf(rawBits * (1 << this->fraction));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "Destructor called" << std::endl;
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

Fixed	&Fixed::operator=(const Fixed	&f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->rawBits = f.rawBits;
	return (*this);
}

bool	Fixed::operator<(const Fixed &f)
{
	return (this->rawBits < f.rawBits);
}
bool	Fixed::operator>(const Fixed &f)
{
	return (this->rawBits > f.rawBits);
}
bool	Fixed::operator<=(const Fixed &f)
{
	return (this->rawBits <= f.rawBits);
}
bool	Fixed::operator>=(const Fixed &f)
{
	return (this->rawBits >= f.rawBits);
}
bool	Fixed::operator!=(const Fixed &f)
{
	return (this->rawBits != f.rawBits);
}
bool	Fixed::operator==(const Fixed &f)
{
	return (this->rawBits == f.rawBits);
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + f.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - f.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() * f.getRawBits() >> f.fraction);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() / f.getRawBits() << f.fraction);
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	rawBits++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed res(*this);
	rawBits++;
	return (res);
}

Fixed	Fixed::operator--(int)
{
	Fixed res(*this);
	rawBits--;
	return (res);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

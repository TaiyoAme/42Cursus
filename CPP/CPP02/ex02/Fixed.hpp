/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:15:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:17:03 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <ostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int rawBit);
	Fixed(float f);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

	Fixed	&operator=(const Fixed &f);
	
	bool	operator>(const Fixed &f);
	bool	operator<(const Fixed &f);
	bool	operator>=(const Fixed &f);
	bool	operator<=(const Fixed &f);
	bool	operator!=(const Fixed &f);
	bool	operator==(const Fixed &f);

	Fixed	operator+(const Fixed &f) const;
	Fixed	operator-(const Fixed &f) const;
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;

	Fixed	&operator--(void);
	Fixed	&operator++(void);
	Fixed	operator--(int);
	Fixed	operator++(int);

	static Fixed		&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);

private:
	int rawBits;
	static const int	fraction = 8;
};

std::ostream	&operator<<(std::ostream	&os, const Fixed &f);

#endif // !FIXED_HPP

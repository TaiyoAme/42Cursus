/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:15:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:16:07 by hehuang          ###   ########.fr       */
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
	Fixed &operator=(const Fixed &copy);
	Fixed(float f);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

private:
	int rawBits;
	static const int	fraction = 8;
};

std::ostream	&operator<<(std::ostream	&os, const Fixed &f);

#endif // !FIXED_HPP

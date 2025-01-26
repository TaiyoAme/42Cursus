/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:15:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:11:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
public:
	Fixed();
	Fixed(Fixed &f);
	Fixed &operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits( int const raw );
	void	operator=(Fixed	&f);

private:
	int rawBits;
	static const int	fraction = 8;
};

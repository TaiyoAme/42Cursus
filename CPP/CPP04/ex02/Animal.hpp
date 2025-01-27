/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:30:23 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:04:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
public:
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;

protected:
	std::string type_;
	Animal();
	Animal(Animal const &copy);
	Animal	&operator=(Animal const &copy);
	Animal(std::string type);
};

#endif // !ANIMAL_HPP

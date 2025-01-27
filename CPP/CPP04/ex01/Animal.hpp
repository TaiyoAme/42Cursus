/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:30:23 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/19 17:16:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(Animal const &copy);
	Animal	&operator=(Animal const &copy);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;

protected:
	std::string type_;	
};

#endif // !ANIMAL_HPP

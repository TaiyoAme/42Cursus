/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:34:38 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:08:05 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
#include <string>

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &dog);
	Dog &operator=(Dog const &copy);
	~Dog();
	void makeSound() const override;

private:
	Brain	*brain;
};

#endif // !DOG_HPP

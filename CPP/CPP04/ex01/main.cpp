/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:17 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/19 18:04:29 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Animal *table[50];
	for (int i = 0; i < 50; i++)
	{
		if (i < 25)
			table[i] = new Cat();
		else
			table[i] = new Dog();
	}
	for (int i = 0; i < 50; i++)
		delete table[i];
	return 0;
}

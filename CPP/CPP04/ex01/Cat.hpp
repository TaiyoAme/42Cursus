/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:32:05 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/19 17:27:10 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
public:
	Cat();
	Cat(Cat const &copy);
	Cat &operator=(Cat const &copy);
	void makeSound() const override;
	~Cat();

private:
	Brain	*brain;	
};

#endif // !CAT_HPP


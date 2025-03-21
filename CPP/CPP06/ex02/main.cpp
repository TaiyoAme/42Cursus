/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:09:46 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/25 17:11:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	Base *p = new Base();

	srand(time(0));
	identify(p);
	identify(*p);
	p = generate();
	identify(p);
	identify(*p);
	delete p;
}

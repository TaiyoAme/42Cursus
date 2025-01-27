/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:22:52 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/19 17:29:16 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
class Brain {
public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(Brain const &copy);
	~Brain();

private:
	std::string ideas[100];	
};

#endif

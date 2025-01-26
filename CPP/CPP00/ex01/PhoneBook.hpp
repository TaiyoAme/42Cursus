/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:31:32 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/18 22:11:44 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();

private:
	Contact contacts[8];
	int	size;
	int	oldest_id;
};

#endif // !PHONEBOOK_HPP

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:32:52 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/18 22:12:07 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
public:
	Contact();
	~Contact();
	Contact(std::string &firstname, std::string &lastname, std::string &nickname,
			std::string &phone_number, std::string &dark_secret) : 
		firstname(firstname), lastname(lastname), nickname(nickname),
		phone_number(phone_number), dark_secret(dark_secret) {};
	void	display_info();
	std::string	get_firstname();
	std::string	get_lastname();
	std::string	get_nickname();
	void		set_firstname(const std::string &str);
	void		set_lastname(const std::string &str);
	void		set_nickname(const std::string &str);
	void		set_phone_number(const std::string &str);
	void		set_dark_secret(const std::string &str);

private:
	std::string	firstname;
	std::string lastname;
	std::string nickname;
	std::string	phone_number;
	std::string dark_secret;
};

#endif // !CONTACT_HPP

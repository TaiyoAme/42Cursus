/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:28:48 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/24 17:40:55 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

constexpr const char* SPECIAL[]  = {"+inf", "-inf", "nan"};
constexpr const char* SPECIALF[]  = {"+inff", "-inff", "nanf"};

#include <string>
class ScalarConverter {
public:
	static void convert(std::string input);
	static bool is_special_case(std::string val);
	static bool is_numeric(std::string val);
	static bool is_displayable(float val);

private:
	std::string values[4];
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();	
};

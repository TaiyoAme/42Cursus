/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:54:32 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 18:14:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	std::string	getName();
	int	getGrade();
	void promote();
	void demote();
	~Bureaucrat();

private:
	std::string name_;
	int	grade_;

	class GradeTooHighException : public std::exception{
	public:
		explicit GradeTooHighException();
		const char* what() const noexcept override;

	private:
		const char *msg = "Grade to high !";
	};

	class GradeTooLowException : public std::exception{
	public:
		explicit GradeTooLowException();
		const char* what() const noexcept override;

	private:
		const char *msg = "Grade to low !";
	};

};
std::ostream& operator<<(std::ostream& os, Bureaucrat& ref);

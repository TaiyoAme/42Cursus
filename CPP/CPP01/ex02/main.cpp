/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:58:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/13 18:04:20 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string	*ptr = &str;
    std::string	&ref = str;

    std::cout << "Memory Addresses:\n"
              << "-----------------\n"
              << "str  address: " << &str << '\n'
              << "ptr  address: " << ptr << '\n'
              << "ref  address: " << &ref << "\n\n";

    std::cout << "Values:\n"
              << "--------\n"
              << "str  value: " << str << '\n'
              << "ptr  value: " << *ptr << '\n'
              << "ref  value: " << ref << '\n';

    return 0;
}

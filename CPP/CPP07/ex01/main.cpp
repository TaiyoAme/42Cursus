/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:32:00 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/25 18:43:36 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
    std::string arr[] = {"Hello", "World", "!"};
    size_t arrLength = sizeof(arr) / sizeof(arr[0]);

    iter(arr, arrLength, displayElement);

    std::cout << "\n";

    int array[] = {1,3,2,4,8,9,6,7};
    size_t arrayLength = sizeof(array) / sizeof(array[0]);

    iter(array, arrayLength, displayElement);

    return 0;
}

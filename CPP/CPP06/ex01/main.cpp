/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:51:54 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/24 19:07:24 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

    Data data = {42, "Example"};

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized value: " << deserialized->value << ", " << deserialized->name << std::endl;

    if (deserialized == &data) {
        std::cout << "Deserialization successful: Pointers match!" << std::endl;
    } else {
        std::cout << "Deserialization failed: Pointers do not match!" << std::endl;
    }

    return 0;
}

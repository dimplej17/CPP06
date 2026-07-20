/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:43:03 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/20 15:23:18 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
 
int main()
{
	Data original;
	original.value = "answer";
	original.key = 42;
	Data* ptr = &original;
 
	uintptr_t raw = Serializer::serialize(ptr);
	Data* restored = Serializer::deserialize(raw);
 
	std::cout << "original address:  " << ptr << std::endl;
	std::cout << "serialized value:  " << raw << std::endl;
	std::cout << "deserialized address: " << restored << std::endl;
 
	if (restored == ptr)
		std::cout << "pointers match" << std::endl;
	else
		std::cout << "pointers differ" << std::endl;
 
	std::cout << "restored->key = " << restored->key << std::endl;
	std::cout << "restored->value = " << restored->value << std::endl;
 
	return (0);
}
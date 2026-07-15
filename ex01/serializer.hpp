/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:21:49 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/15 17:25:57 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

// Implement a class Serializer, which will not be initializable by the user in any way

// Write a program to test that your class works as expected.
// You must create a non-empty (meaning it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
// Do not forget to turn in the files of your Data structure.

class Serializer
{
	static uintptr_t serialize(Data* ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t.
	static Data* deserialize(uintptr_t raw); // It takes an unsigned integer parameter and converts it to a pointer to Data.



};

#endif
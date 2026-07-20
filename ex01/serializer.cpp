/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:21:57 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/20 15:21:32 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
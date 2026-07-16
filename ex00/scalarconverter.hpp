/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarconverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:04:56 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/16 02:13:37 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter& operator=(const ScalarConverter& other) = delete;
	~ScalarConverter() = delete;

	public:
	static void convert(std::string input); // 1. detect aka parsing? 2. convert to respective type 3. cast to the other types
};


#endif
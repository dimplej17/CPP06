/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarconverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:04:40 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/18 14:41:46 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input) // 1. detect aka parsing? 2. convert to respective type 3. cast to the other types
{
	
	// char
	if ((input == sizeof(char)) && ((input > 31 && input < 48) || (input > 57 && input < 128)))
	{
		std::cout << "char: " << input << std::endl;
		std::cout << "int: " << static_cast<int>(input) << std::endl;
		std::cout << "float: " << static_cast<float>(input) << std::endl;
		std::cout << "double: " << static_cast<double>(input) << std::endl;
		return ;
	}
	
	if (input == "-inff")
	{
		std::cout << "char: impossible" << input << std::endl;
		std::cout << "int: impossible" << i << std::endl;
		std::cout << "float: -inff" << f << std::endl;
		std::cout << "double: -inf" << d << std::endl;
		return ;
	}

	if (input == "inff")
	{
		std::cout << "char: impossible" << input << std::endl;
		std::cout << "int: impossible" << i << std::endl;
		std::cout << "float: inff" << f << std::endl;
		std::cout << "double: inf" << d << std::endl;
		return ;
	}

	if (input == "-inf")
	{
		std::cout << "char: impossible" << input << std::endl;
		std::cout << "int: impossible" << i << std::endl;
		std::cout << "float: -inff" << f << std::endl;
		std::cout << "double: -inf" << d << std::endl;
		return ;
	}
		
	if (input == "inf")
	{
		std::cout << "char: impossible" << input << std::endl;
		std::cout << "int: impossible" << i << std::endl;
		std::cout << "float: inff" << f << std::endl;
		std::cout << "double: inf" << d << std::endl;
		return ;
	}

	if (input == "nan")
	{
		std::cout << "char: impossible" << input << std::endl;
		std::cout << "int: impossible" << i << std::endl;
		std::cout << "float: nanf" << f << std::endl;
		std::cout << "double: nan" << d << std::endl;
		return ;
	}
	
	if (input == "nanf")
	{
		std::cout << "char: impossible" << input << std::endl;
		std::cout << "int: impossible" << i << std::endl;
		std::cout << "float: nanf" << f << std::endl;
		std::cout << "double: nan" << d << std::endl;
		return ;
	}
	
	// (i) check if the string has only numbers - 
	// (ii) if yes, check how many numbers it has - to decide if it's an int or double (or nah?) + handle numeric limits, overflows;
	// (iii) convert string to number using some conversion function
	// (iv) if string has other chars in addition to numbers, check for a decimal point --> if it's just '.' then double, if it has 'f' and decimal point, then it's float
	// handle numeric limits, overflows

	int str_len = strlen(input);
	int d_point_flag = 0;
	int f_flag = 0;
	for (int i = 0; i < str_len; i++)
	{
		if !((input[i] > 47 && input[i] < 58) || (input[i] == '.') || (input[i] == 'f'))
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		else if (input[i] == '.')
		{
			if (d_point_flag == 1)
			{
				std::cout << "Invalid input" << std::endl;
				return ;
			}
			d_point_flag = 1;
		}
		else if (input[i] == 'f')
		{
			if (f_flag == 1)
			{
				std::cout << "Invalid input" << std::endl;
				return ;
			}
			f_flag = 1;
		}
	}

	// int
	if (d_point_flag == 0 && f_flag == 0)
	{
		double temp_int = std::stod(input); // I'm using double to take care of overflows for int
		// numeric limits
		if (temp_int >= INT_MAX)
		{
			std::cout << "char: " << static_cast<char>(temp_int) << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(temp_int) << std::endl;
			std::cout << "double: " << temp_int << std::endl;
			return ;
		}
		if (temp_int <= INT_MIN)
		{
			std::cout << "char: " << static_cast<char>(temp_int) << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(temp_int) << std::endl;
			std::cout << "double: " << temp_int << std::endl;
			return ;
		}
		// non-displayable
		if (temp_int >= 0 && temp_int < 32)
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(temp_int) << std::endl;
			std::cout << "float: " << static_cast<float>(temp_int) << std::endl;
			std::cout << "double: " << temp_int << std::endl;
			return ;
		}
		std::cout << "char: " << static_cast<char>(temp_int) << std::endl;
		std::cout << "int: " << static_cast<int>(temp_int) << std::endl;
		std::cout << "float: " << static_cast<float>(temp_int) << std::endl;
		std::cout << "double: " << temp_int << std::endl;
		return ;
	}

	// float
	if (d_point_flag == 1 && f_flag == 1)
	{
		
	}
}

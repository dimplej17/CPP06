/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarconverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:04:40 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/18 15:24:18 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int int_limits(double num)
{
	if (num >= INT_MAX)
			return (1);
	else if (num <= INT_MIN)
			return (1);
	else
		return (0);
}

static int flt_limits(double num)
{
	if (num >= FLT_MAX)
			return (1);
	else if (num <= FLT_MIN)
			return (1);
	else
		return (0);
}

static int dbl_limits(double num) // here I don't know how to handle overflows
{
	if (num >= DBL_MAX)
			return (1);
	else if (num <= DBL_MIN)
			return (1);
	else
		return (0);
}

void ScalarConverter::convert(std::string input) // 1. detect aka parsing? 2. convert to respective type 3. cast to the other types
{
	int str_len = std::string::length(input);
	
	// char
	if ((str_len == 1) && ((input[0] > 31 && input[0] < 48) || (input[0] > 57 && input[0] < 128)))
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

	double num = std::stod(input); // I'm using double to take care of overflows for int
	// stod() throws exceptions!!!!


	
	// int
	if (d_point_flag == 0 && f_flag == 0)
	{
		// numeric limits
		if (int_limits(num) == 1)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (flt_limits(num) == 1)
				std::cout << "float: impossible" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(num) << std::endl;
			if (dbl_limits(num) == 1)
				std::cout << "double: impossible" << std::endl;
			else
				std::cout << "double: " << num << std::endl;
			return ;
		}
		
		// non-displayable
		if (num >= 0 && num < 32)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(num) << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << static_cast<float>(num) << std::endl;	
		std::cout << "double: " << num << std::endl;
		return ;
	}

	// float
	if (d_point_flag == 1 && f_flag == 1)
	{
		// numeric limits
		if (flt_limits(num) == 1)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			if (dbl_limits(num) == 1)
				std::cout << "double: impossible" << std::endl;
			else
				std::cout << "double: " << num << std::endl;
			return ;
		}

		// non-displayable
		if (num >= 0 && num < 32)
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		else if (int_limits(num) == 1)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << "char: " << static_cast<char>(num) << std::endl;
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		std::cout << "float: " << static_cast<float>(num) << std::endl;
		std::cout << "double: " << num << std::endl;
		return ;
	}

	// double
	if (d_point_flag == 1 && f_flag == 0)
	{
		// numeric limits
		if (dbl_limits(num) == 1)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << num << std::endl;
			return ;
		}

		// non-displayable
		if (num >= 0 && num < 32)
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		else if (int_limits(num) == 1)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << "char: " << static_cast<char>(num) << std::endl;
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		}
		if (flt_limits(num) == 1)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(num) << std::endl;
		
		std::cout << "double: " << num << std::endl;
		return ;
	}
	std::cout << "Invalid" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:04:40 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/20 16:41:56 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isIntOverflow(double num)
{
	return (num > static_cast<double>(std::numeric_limits<int>::max()) ||
			num < static_cast<double>(std::numeric_limits<int>::min()));
}

static bool isFloatOverflow(double num)
{
	return (num > static_cast<double>(std::numeric_limits<float>::max()) ||
			num < -static_cast<double>(std::numeric_limits<float>::max()));
}

static std::string formatDouble(double d)
{
	if (std::isnan(d))
		return "nan";
	if (std::isinf(d))
		return (d < 0 ? "-inf" : "inf");
	std::ostringstream oss;
	oss << d;
	std::string s = oss.str();
	if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) // ???
		s += ".0";
	return s;
}

static std::string formatFloat(float f)
{
	if (std::isnan(f))
		return "nanf";
	if (std::isinf(f))
		return (f < 0 ? "-inff" : "inff");
	std::ostringstream oss;
	oss << f;
	std::string s = oss.str();
	if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) // ???
		s += ".0";
	return s + "f";
}

static void printChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << formatFloat(static_cast<float>(c)) << std::endl;
	std::cout << "double: " << formatDouble(static_cast<double>(c)) << std::endl;
}

static void printPseudoLiteral(std::string const& input)
{
	bool negative = (input[0] == '-');

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input.find("nan") != std::string::npos)
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "float: " << (negative ? "-inff" : "inff") << std::endl;
		std::cout << "double: " << (negative ? "-inf" : "inf") << std::endl;
	}
}

static void printNum(double num)
{
	bool intOverflow = isIntOverflow(num);
	bool floatOverflow = isFloatOverflow(num);

	if (intOverflow)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(static_cast<int>(num));
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	if (intOverflow)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (floatOverflow)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << formatFloat(static_cast<float>(num)) << std::endl;

	std::cout << "double: " << formatDouble(num) << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	size_t len = input.length();

	if (len == 0)
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}

	// char
	if (len == 1 &&
		!std::isdigit(static_cast<unsigned char>(input[0])) &&
		std::isprint(static_cast<unsigned char>(input[0])))
	{
		printChar(input[0]);
		return;
	}

	if (input == "-inff" || input == "+inff" || input == "inff" ||
		input == "-inf"  || input == "+inf"  || input == "inf"  ||
		input == "nan"   || input == "nanf")
	{
		printPseudoLiteral(input);
		return;
	}

	// parsing
	bool hasDot = false;
	bool hasF = false;
	bool hasDigit = false;

	for (size_t i = 0; i < len; ++i)
	{
		char c = input[i];

		if (c == '-' || c == '+')
		{
			if (i != 0)
			{
				std::cout << "Invalid input" << std::endl;
				return;
			}
		}
		else if (c == '.')
		{
			if (hasDot)
			{
				std::cout << "Invalid input" << std::endl;
				return;
			}
			hasDot = true;
		}
		else if (c == 'f')
		{
			if (hasF || i != len - 1)
			{
				std::cout << "Invalid input" << std::endl;
				return;
			}
			hasF = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(c)))
		{
			hasDigit = true;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			return;
		}
	}

	if (!hasDigit)
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}

	double num;
	try
	{
		size_t pos;
		num = std::stod(input, &pos);
		if (pos != len - (hasF ? 1 : 0))
		{
			std::cout << "Invalid input" << std::endl;
			return;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		// std::cout << "Invalid input" << std::endl;
		return;
	}

	printNum(num);
}


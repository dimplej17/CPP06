/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 01:41:36 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/18 13:59:47 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "Please enter input" << std::cout;
		return ;
	}
	if (argc != 2)
	{
		std::cout << "Invalid input" << std::cout;
		return ;
	}
	ScalarConverter::convert(argv[1]);
}
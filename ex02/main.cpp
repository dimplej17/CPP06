/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:58:26 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/20 16:56:15 by djanardh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate (void)
{
	// Generate a random number between 0 and 2
	int random_num = rand() % 3;

	switch (random_num)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) == NULL)
	{
		if (dynamic_cast<B*>(p) == NULL)
		{	
			if (dynamic_cast<C*>(p) == NULL)
			{
				std::cout << "Invalid: object pointed to by 'p' is not A or B or C" << std::endl;
				return ;
			}
			std::cout << "The actual type of the object pointed to by 'p' is 'C'" << std::endl;
			return ;
		}
		std::cout << "The actual type of the object pointed to by 'p' is 'B'" << std::endl;
		return ;
	}
	std::cout << "The actual type of the object pointed to by 'p' is 'A'" << std::endl;
	return ;
}

void identify(Base& p)
{
	int flag = 0;
	try 
	{
		A& a = dynamic_cast<A&>(p);
	}
	catch (const std::exception& e)
	{
		flag = 1;
	}
	if (flag == 0)
	{
		std::cout << "The actual type of object referenced by 'p' is 'A'" << std::endl;
		return ;
	}

	if (flag == 1)
	{
		try 
		{
			B& b = dynamic_cast<B&>(p);
		}
		catch (const std::exception& e)
		{
			flag = 2;
		}
	}
	if (flag == 1)
	{
		std::cout << "The actual type of object referenced by 'p' is 'B'" << std::endl;
		return ;		
	}

	if (flag == 2)
	{
		try 
		{
			C& c = dynamic_cast<C&>(p);
		}
		catch (const std::exception& e)
		{
			std::cout << "Invalid: object is not A or B or C" << std::endl;
			return ;
		}
	}
	if (flag == 2)
	{
		std::cout << "The actual type of object referenced by 'p' is 'C'" << std::endl;
		return ;
	}

}

int main (void)
{
	srand(time(NULL));

	Base* random_class = generate();

	identify(random_class);
	identify(*random_class);
	
	delete (random_class);
	
	return (0);
}
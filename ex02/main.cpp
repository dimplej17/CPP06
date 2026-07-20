/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanardh <djanardh@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:58:26 by djanardh          #+#    #+#             */
/*   Updated: 2026/07/20 17:28:29 by djanardh         ###   ########.fr       */
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
		{
			std::cout << "A generated" << std::endl;
			return (new A());
		}
		case 1:
		{
			std::cout << "B generated" << std::endl;
			return (new B());
		}
		case 2:
		{
			std::cout << "C generated" << std::endl;
			return (new C());
		}
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
				std::cout << "Invalid (not A, B or C)" << std::endl;
				return ;
			}
			std::cout << "C" << std::endl;
			return ;
		}
		std::cout << "B" << std::endl;
		return ;
	}
	std::cout << "A" << std::endl;
	return ;
}

void identify(Base& p)
{
	try 
	{
		// If True (Success): Returns a valid reference to the actual object of type A (or its derived type).
		// If False (Failure): Throws a std::bad_cast exception.
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}

	try 
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;	
	}
	catch (const std::bad_cast&) {}

	try 
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}

	std::cout << "Invalid (not A, B or C)" << std::endl;
	return ;
}

int main (void)
{
	srand(time(NULL));

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Round " << i << std::endl;
		
		Base* random_class = generate();

		std::cout << "The actual type of the object pointed to by 'p' is: ";
		identify(random_class);
		
		std::cout << "The actual type of object referenced by 'p' is: ";
		identify(*random_class);

		delete (random_class);
		std::cout << std::endl;
	}
	std::cout << "Round 4" << std::endl;
	
	Base* p = NULL;
	identify(p);
	
	return (0);
}
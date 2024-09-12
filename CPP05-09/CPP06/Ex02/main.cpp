/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:46:46 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/12 14:16:06 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "main.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base	*generate()
{
	int	random;

	random = rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

static void	identifyPtr(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

static void	identifyPtr2(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

int	main()
{
	srand(time(NULL));
	Base	*base = generate();
	A	a;
	B	b;
	C	c;

	std::cout << "random type\n";
	identifyPtr(base);
	identifyPtr2(*base);
	std::cout << "type A\n";
	identifyPtr(&a);
	identifyPtr2(a);
	std::cout << "type B\n";
	identifyPtr(&b);
	identifyPtr2(b);
	std::cout << "type C\n";
	identifyPtr(&c);
	identifyPtr2(c);
	
	delete base;
	return 0;
}

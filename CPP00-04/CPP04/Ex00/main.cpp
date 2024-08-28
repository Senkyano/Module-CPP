/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:50:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/28 12:34:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	j->makeSound();
	std::cout << i->getType() << std::endl;
	i->makeSound();

	meta->makeSound();

	const	WrongAnimal* w = new WrongCat();

	std::cout << w->getType() << std::endl;
	w->makeSound();

	delete w;
	delete meta;
	delete j;
	delete i;
	return (0);
}

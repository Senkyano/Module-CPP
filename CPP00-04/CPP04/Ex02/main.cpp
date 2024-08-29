/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:50:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/29 15:28:23 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	// const Animal* meta = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();

	Cat *cat2 = new Cat(*static_cast<Cat*>(cat));
	std::cout << cat2->getType() << std::endl;
	cat2->addIdea(1, "new idea");
	std::cout << "cat idea : "<< cat2->getIdea(1) << std::endl;

	delete cat2;
	delete dog;
	delete cat;
	return (0);
}

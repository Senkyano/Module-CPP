/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:50:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/02 13:19:18 by rihoy            ###   ########.fr       */
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

	Cat *cat1 = new Cat();
	cat1->addIdea(1, "cat cat12");
	Cat cat2(*cat1);
	std::cout << cat2.getType() << std::endl;
	cat2.addIdea(1, "new idea");
	std::cout << "cat idea : "<< cat2.getIdea(1) << std::endl;

	delete cat1;
	delete dog;
	delete cat;
	return (0);
}

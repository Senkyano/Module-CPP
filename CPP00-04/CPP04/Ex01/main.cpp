/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:50:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/30 13:48:08 by rihoy            ###   ########.fr       */
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
	// meta->makeSound();

	Cat *cat1 = new Cat();
	cat1->addIdea(1, "new idea");
	Cat cat2(*cat1);
	Cat cat3(cat2);
	cat3 = cat2;
	std::cout << "cat idea : " << cat2.getIdea(1) << std::endl;
	// delete meta;
	delete cat1;
	delete dog;
	delete cat;
	return (0);
}

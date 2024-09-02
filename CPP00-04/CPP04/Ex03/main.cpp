/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:38 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/02 14:14:23 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "main.hpp"

int main()
{
	std::cout << "==========SUBJECT==========" << std::endl;
	// Test subject
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	// END test subject
	std::cout << "========END SUBJECT========" << std::endl;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	bob = new Character("bob");
	me = new Character("me");
	Character	*me1 = new Character("me");
	me1->equip(new Ice());
	Character	me2(*me1);
	std::cout << PUR << "me1 :" << &me1 << std::endl;
	std::cout << Y << "inventory : " << std::endl;
	std::cout << "1 :" << me1->getMateria(0) << RST << std::endl;
	std::cout << PUR <<"me2 :" << &me2 << std::endl;
	std::cout << Y << "inventory : " << std::endl;
	std::cout << "1 :" << me2.getMateria(0) << RST << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	for (int i = 0; i < 22; i++)
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(1);
	}
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->unequip(2);
	me->use(2, *bob);
	delete me1;
	delete src;
	delete me;
	delete bob;
	return (0);
}

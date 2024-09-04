/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:03:37 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/04 10:05:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{};

WrongCat::WrongCat(const WrongCat &value) : WrongAnimal(value)
{};

WrongCat	&WrongCat::operator=(const WrongCat &value)
{
	type = value.getType();
	return (*this);
};

WrongCat::~WrongCat() {};

void		WrongCat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
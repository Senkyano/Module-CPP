/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:32 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/18 12:39:08 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "main.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GR <<"Cure constructor called" << RST << std::endl;
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor called" << RST << std::endl;
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << PUR << "* heals " << target.getName() << "'s wounds *" << RST << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:36 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/18 12:38:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "main.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GR<< "Ice constructor called" << RST << std::endl;
}

Ice::~Ice()
{
	std::cout << RED << "Ice destructor called" << RST << std::endl;
}

AMateria	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << CY << "* shoots an ice bolt at " << target.getName() << " *" << RST << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/02 14:11:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(const AMateria &value)
{
	this->type = value.type;
}

AMateria &AMateria::operator=(const AMateria &value)
{
	if (this == &value)
		return (*this);
	type = value.type;
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

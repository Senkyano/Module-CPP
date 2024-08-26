/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:13 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:03:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &value);
		AMateria &operator=(const AMateria &value);
		virtual ~AMateria();
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif

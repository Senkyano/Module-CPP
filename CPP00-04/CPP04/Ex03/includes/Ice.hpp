/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:20 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:04:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice &value);
		Ice &operator=(const Ice &value);
		~Ice();

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
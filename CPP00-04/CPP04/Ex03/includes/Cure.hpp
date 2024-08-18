/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:17 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/18 12:10:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Cure : public AMateria
{
	public :
		Cure();
		~Cure();

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:49:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:04:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria*	inventory[4];
	
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &value);
		MateriaSource &operator=(const MateriaSource &value);
		~MateriaSource();

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:08:37 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/15 14:11:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap : public ClapTrap
{
	private :
		
	public :
		FragTrap(std::string name);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif
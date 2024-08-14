/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:56 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/14 14:38:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private :
		std::string		name;
		int				health;
		int				engergy;
		int				attack_damage;

	public :
		ClapTrap(const std::string name);
		~ClapTrap();
		
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	// Setters
		void		setHealth(int health);
		void		setEnergy(int energy);
		void		setAttackDamage(int attack_damage);
	// Getters
		int			getHealth();
		int			getEnergy();
		int			getAttackDamage();
		std::string	getName();
};

#endif

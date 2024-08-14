/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:50 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/14 14:50:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	ClapTrap	ClapTrap("Tove lo");

	ScavTrap	ScavTrap("Serena");
	ClapTrap.attack("Skag");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);
	ScavTrap.guardGate();
	ScavTrap.attack("Skag");
	ScavTrap.takeDamage(40);
	ScavTrap.guardGate();
	ScavTrap.beRepaired(30);
	return (0);
}

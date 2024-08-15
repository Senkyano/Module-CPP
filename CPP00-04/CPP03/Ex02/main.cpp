/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:50 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/15 14:42:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main()
{
	ClapTrap	ClapTrap("Tove lo");
	ScavTrap	ScavTrap("Serena");
	FragTrap	FragTrap("Luna");
	
	ClapTrap.attack("Skag");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);
	std::cout << std::endl;
	ScavTrap.guardGate();
	ScavTrap.attack("Skag");
	ScavTrap.takeDamage(40);
	ScavTrap.guardGate();
	ScavTrap.beRepaired(30);
	std::cout << std::endl;
	FragTrap.highFivesGuys();
	FragTrap.attack("Skag");
	FragTrap.takeDamage(20);
	FragTrap.beRepaired(10);
	return (0);
}

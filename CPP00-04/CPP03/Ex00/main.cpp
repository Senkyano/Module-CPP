/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:50 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/14 13:59:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main()
{
	ClapTrap	ClapTrap("Tove lo");

	ClapTrap.attack("Skag");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);
	return (0);
}

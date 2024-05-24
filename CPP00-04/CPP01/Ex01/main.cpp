/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:12:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/24 13:31:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		i;

	i = 5;
	Zombie	*zombie = zombieHorde(i, "Zombie1(MERL)");
	while (i--)
		zombie[i].announce();
	delete []	zombie;
}

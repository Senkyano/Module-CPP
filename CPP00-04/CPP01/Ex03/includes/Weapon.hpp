/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:52:09 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/26 14:34:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>
# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string	getType();
		void				setType(std::string type);

	private:
		std::string	type;
};

#endif

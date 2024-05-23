/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:15:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/23 13:27:50 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include <iostream>
#include <string>
#include "contact.hpp"

class	Phonebook
{
	public:
		Phonebook();
		~Phonebook();
	private:
		Contact contacts[8];
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:15:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/23 22:55:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include <iostream>
#include <string>
#include "contact.hpp"
#include "main.hpp"

class	Phonebook
{
	public:
		Phonebook();
		~Phonebook();
	
		void	getContact(int index);
		void	getInfo(std::string str);
		void	addContact();
		void	displayContacts();

	private:
		int		lastAdded;
		Contact contacts[8];
};

#endif

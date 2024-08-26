/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:03:19 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/26 23:03:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private :
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &value);
		Brain &operator=(const Brain &value);
		~Brain();

		std::string	getIdea(int i) const;
		void		setIdea(int i, std::string idea);
};

#endif

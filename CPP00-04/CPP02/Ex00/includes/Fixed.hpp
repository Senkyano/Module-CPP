/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonique.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:39:25 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/27 22:19:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CANONIQUE_HPP__
# define __CANONIQUE_HPP__

class Canonique
{
	private:
		int					value;
		static const int	constValue;

	public:
	// constructor
		Canonique();
		Canonique(const Canonique &value);
	// destructeur
		~Canonique();
	//surcharge operator
		Canonique &operator=(const Canonique &value);
	//getter
		int getRawBits(void) const;
	//setter
		void setRawBits(int const raw);
};

#endif
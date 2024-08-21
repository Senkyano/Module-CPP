/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:14:23 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/21 19:29:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include "main.hpp"
# include <stdint.h>

typedef struct	Data
{
	std::string		s1;
	int				n;
	std::string		s2;
}	Data;

class	Serialization
{
	public:
		Serialization();
		~Serialization();

		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif

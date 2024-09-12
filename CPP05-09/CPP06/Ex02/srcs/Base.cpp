/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:29:37 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/12 14:14:39 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
}

Base::Base(const Base &src)
{
	*this = src;
}

Base::~Base()
{
}

Base	&Base::operator=(const Base &src)
{
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

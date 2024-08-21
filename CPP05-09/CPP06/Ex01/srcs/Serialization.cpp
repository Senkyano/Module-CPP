/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:24:27 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/21 19:25:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
}

Serialization::~Serialization()
{
}

uintptr_t	Serialization::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

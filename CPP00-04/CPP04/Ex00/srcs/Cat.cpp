/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:53:26 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/17 13:57:28 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::~Cat()
{
}

void	Cat::makeSound() const
{
	std::cout << type << " : meow meow" << std::endl;
}
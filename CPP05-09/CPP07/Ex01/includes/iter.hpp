/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:45:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/22 23:23:37 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *fst, size_t length, void (*f)(T &))
{
	if (!fst || !f)
		return ;
	for (size_t i = 0; i < length; i++)
		f(fst[i]);
};

#endif

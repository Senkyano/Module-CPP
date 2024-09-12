/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:42:46 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/12 14:13:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include "main.hpp"

class	Base
{
	public :
		Base();
		Base(const Base &src);
		virtual	~Base();

		Base	&operator=(const Base &src);
};

#endif

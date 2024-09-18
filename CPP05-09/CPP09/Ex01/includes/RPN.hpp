/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:54:01 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/18 13:46:35 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "main.hpp"
# include <stack>
# include <list>

class	RPN
{
	private :
		std::stack<int, std::list<int> >		num;
		std::stack<char, std::list<char> >	ope;

	public :
		RPN();
		RPN(const RPN &src);
		~RPN();
		
		RPN		&operator=(const RPN &src);
		bool	parsing(const char* str, int i);
		void	calcul(std::string str);
};

#endif
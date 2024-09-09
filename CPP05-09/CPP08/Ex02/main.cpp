/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:52:57 by rihoy             #+#    #+#             */
/*   Updated: 2024/09/09 15:51:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "on retire 1 element de la stack\n";
	mstack.pop();
	std::cout << "size stack : " << mstack.size() << std::endl;
	std::cout << "on rajoute de 0 a 100 element de la stack\n";
	for (int i = 0; i < 100; ++i)
		mstack.push(i);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ;";
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
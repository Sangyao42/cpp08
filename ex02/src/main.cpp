/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:33:51 by sawang            #+#    #+#             */
/*   Updated: 2023/12/17 22:15:35 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	MutantStack<int, std::deque<int> > mstack;

	if (mstack.empty())
		std::cout << "stack is empty" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(42);
	mstack.push(987);

	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;

	MutantStack<int, std::deque<int> > mstack2(mstack);
	std::cout << "mstack2  after copy" << std::endl;
	std::cout << "size: " << mstack2.size() << std::endl;
	std::cout << "top: " << mstack2.top() << std::endl;
	MutantStack<int, std::deque<int> > mstack3;
	mstack3.push(1);
	mstack3.push(2);
	mstack3.push(3);
	// mstack.swap(mstack3);
	// std::cout << "mstack  after swap" << std::endl;
	// std::cout << "after swap" << std::endl;
	// std::cout << "size: " << mstack.size() << std::endl;
	// std::cout << "top: " << mstack.top() << std::endl;

	std::cout << "mstack interator:" << std::endl;
	MutantStack<int, std::deque<int> >::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "mstack reverse interator:" << std::endl;
	MutantStack<int, std::deque<int> >::reverse_iterator it2 = mstack.rbegin();
	while (it2 != mstack.rend())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
	std::cout << "mstack3 interator:" << std::endl;
	MutantStack<int, std::deque<int> >::const_iterator it3 = mstack3.cbegin();
	while (it3 != mstack3.cend())
	{
		std::cout << *it3 << std::endl;
		it3++;
	}
	std::cout << "mstack3 reverse interator:" << std::endl;
	MutantStack<int, std::deque<int> >::const_reverse_iterator it4 = mstack3.crbegin();
	while (it4 != mstack3.crend())
	{
		std::cout << *it4 << std::endl;
		it4++;
	}
}
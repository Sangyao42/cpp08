/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:56:21 by sawang            #+#    #+#             */
/*   Updated: 2023/12/16 20:38:02 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> array;
	// std::list<int> array;
	for (int i = 0; i < 10; i++)
		array.push_back(i);
	std::vector<int>::iterator it;
	// std::list<int>::iterator it;
	it = std::find(array.begin(), array.end(), 3);
	array.insert(it , 8);
	std::cout << "original array: " << std::endl;
	for (it = array.begin(); it != array.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	int num1 = 3;
	int num2 = 12;

	try
	{
		std::cout << "found number " << num1 << " at index: " << easyfind(array, num1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "found number " << num2 << " at index: " << easyfind(array, num2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
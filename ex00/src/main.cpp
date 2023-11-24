/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:56:21 by sawang            #+#    #+#             */
/*   Updated: 2023/11/24 17:08:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

int main(void)
{
	std::vector<int> array;
	for (int i = 0; i < 10; i++)
		array.push_back(i);
	std::vector<int>::iterator it;
	it = std::find(array.begin(), array.end(), 3);
	array.insert(it , 8);
	std::cout << "original array: " << std::endl;
	for (it = array.begin(); it != array.end(); it++)
		std::cout << *it << ' ';
	int num1 = 3;
	int num2 = 12;

	try
	{
		std::cout << "found number " << num1 << " at index " << ::easyfind(array, num1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "found number " << num1 << " at index " << ::easyfind(array, num2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
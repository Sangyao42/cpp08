/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:56 by sawang            #+#    #+#             */
/*   Updated: 2023/12/04 14:42:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	int size = 10;
	Span sp = Span(size);
	std::cout << sp << std::endl;
	// for (int i = 0; i < 10002; i++)
	// {
	// 	try
	// 	{
	// 		sp.addNumber(rand() % 10000);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	size_t arraySize = size + 5;
	srand(time(NULL));
	std::vector<int> intArray;
	for (size_t i = 0; i < arraySize; i++)
	{
		intArray.push_back(rand() % (arraySize * 10));
	}
	std::cout << "Array to fill: ";
	std::vector<int>::iterator it = intArray.begin();
	while (it != intArray.end())
	{
		std::cout << *it << " ";
		it++;
	}



	std::cout << std::endl;
	// try
	// {
	// 	sp.fillSpan(intArray, intArray + arraySize);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	sp.fillSpan(intArray.begin(), intArray.end());

	try
	{
		int nbr = rand() % arraySize;
		std::cout << "Try to add one random number: " << nbr << std::endl;
		sp.addNumber(nbr);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	try
	{
		std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "longest span is: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
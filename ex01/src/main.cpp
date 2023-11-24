/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:56 by sawang            #+#    #+#             */
/*   Updated: 2023/11/24 20:29:48 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span sp = Span(10000);
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
	size_t arraySize = 10010;
	int intArray[arraySize];
	for (size_t i = 0; i < arraySize; i++)
	{
		intArray[i] = rand() % 20000;
		// std::cout << intArray[i] << ' ';
	}
	std::cout << std::endl;
	sp.fillSpan(intArray, arraySize);
	try
	{
		sp.addNumber(rand() % 10000);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp << std::endl;

	std::cout << "shortest span is " << sp.shortestSpan() << std::endl;
	std::cout << "longest span is " << sp.longestSpan() << std::endl;
}
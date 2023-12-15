/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:01 by sawang            #+#    #+#             */
/*   Updated: 2023/12/15 15:10:10 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
unsigned int easyfind(const T array, int num)
{
	// std::vector<int>::const_iterator it;
	typename T::const_iterator it;
	it = std::find(array.begin(), array.end(), num);
	if (it == array.end())
		throw std::runtime_error("Given number not found in array");
	else
		return (std::distance(array.begin(), it));
}

// unsigned int easyfind(std::vector<int> array, int num)
// {
// 	std::vector<int>::iterator it;
// 	it = std::find(array.begin(), array.end(), num);
// 	if (it == array.end())
// 	{
// 		std::cout << "error" << std::endl;
// 		throw std::exception();
// 	}
// 	else
// 	{
// 		std::cout << "found at index: " << std::endl;
// 		return (std::distance(array.begin(), it));
// 	}
// }
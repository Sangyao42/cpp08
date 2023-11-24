/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:01 by sawang            #+#    #+#             */
/*   Updated: 2023/11/24 17:06:41 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
unsigned int easyfind(const T array, int num)
{
	std::vector<int>::const_iterator it;
	it = std::find(array.begin(), array.end(), num);
	if (it == array.end())
		throw std::exception();
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
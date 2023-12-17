/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:01 by sawang            #+#    #+#             */
/*   Updated: 2023/12/17 15:06:21 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
unsigned int easyfind(const T array, int num)
{
	typename T::const_iterator it;
	it = std::find(array.begin(), array.end(), num);
	if (it == array.end())
		throw std::runtime_error("Given number not found in array");
	else
		return (std::distance(array.begin(), it));
}
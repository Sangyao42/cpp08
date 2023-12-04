/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:13:07 by sawang            #+#    #+#             */
/*   Updated: 2023/12/04 13:20:15 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>
#include <algorithm>
#include <iostream>

class Span
{
	public:
		Span(unsigned int N);
		Span(Span const &cpy);
		Span &operator=(Span const &rhs);
		~Span();

		//getters
		size_t				getN(void) const;
		std::multiset<int>	getArray(void) const;

		//members functions
		void	addNumber(int num);
		// void			fillSpan(int *intArray, size_t arraySize);
		template <typename TIt>
		void	fillSpan(TIt begin, TIt end)
		{
			if (this->_array.size() + std::distance(begin, end) <= this->_N)
				this->_array.insert(begin, end);
			else
				// throw Span::SpanIsFullException();
				this->_array.insert(begin, begin + (this->_N - this->_array.size()));
		}
		int		shortestSpan(void);
		int		longestSpan(void);

		//exceptions
		class SpanIsFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class SpanNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		Span();

		size_t		_N;
		std::multiset<int>	_array;
};

std::ostream &operator<<(std::ostream &o, Span const &rhs);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:59 by sawang            #+#    #+#             */
/*   Updated: 2023/12/04 13:20:32 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>

Span::Span() : _N(0)
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(Span const &cpy)
{
	this->_array = cpy._array;
	this->_N = cpy._N;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_array = rhs._array;
		this->_N = rhs._N;
	}
	return (*this);
}

Span::~Span()
{}

//getters
size_t	Span::getN(void) const
{
	return (this->_N);
}

std::multiset<int>	Span::getArray(void) const
{
	return (this->_array);
}

// //member functions
void	Span::addNumber(int num)
{
	if (this->_array.size() < this->_N)
		this->_array.insert(num);
	else
		throw Span::SpanIsFullException();
}

// void	Span::fillSpan(int *intArray, size_t arraySize)
// {
// 	if (this->_array.size() + arraySize <= this->_N)
// 		this->_array.insert(intArray, intArray + arraySize);
// 	else
// 		this->_array.insert(intArray, intArray + (this->_N - this->_array.size()));
// }

// void	Span::fillSpan(int *begin, int *end)
// {
// 	if (this->_array.size() + std::distance(begin, end) <= this->_N)
// 		this->_array.insert(begin, end);
// 	else
// 		// throw Span::SpanIsFullException();
// 		this->_array.insert(begin, begin + (this->_N - this->_array.size()));
// }

int	Span::shortestSpan(void)
{
	if (this->_array.size() < 2)
		throw Span::SpanNotFoundException();
	int shortest = std::numeric_limits<int>::max();
	std::multiset<int>::iterator it = this->_array.begin();
	while (it != --this->_array.end())
	{
		shortest = std::min(shortest, std::abs(*it - *(++it)));
	}

	return (shortest);
}

int	Span::longestSpan(void)
{
	if (this->_array.size() < 2)
		throw Span::SpanNotFoundException();
	std::multiset<int>::iterator itFirstElem = this->_array.begin();
	std::multiset<int>::iterator itLastElem = --this->_array.end();
	return (std::abs(*itLastElem - *itFirstElem));
	// return (std::abs(*this->_array.begin() - *std::prev(this->_array.end())));
}

//exceptions
const char *Span::SpanIsFullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::SpanNotFoundException::what() const throw()
{
	return ("Span cannot be found because there are not enough elements");
}

std::ostream &operator<<(std::ostream &o, Span const &rhs)
{
	o << "Span with size " << rhs.getN() << " has the following elements: " << std::endl;
	const std::multiset<int> temp = rhs.getArray();
	std::multiset<int>::const_iterator it = temp.begin();
	while (it != temp.end())
	{
		o << *it << ' ';
		it++;
	}
	return (o);
}
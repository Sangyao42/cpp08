/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:59 by sawang            #+#    #+#             */
/*   Updated: 2023/11/24 20:27:15 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

void	Span::fillSpan(int *intArray, size_t arraySize)
{
	if (this->_array.size() + arraySize <= this->_N)
		this->_array.insert(intArray, intArray + arraySize);
	else
		this->_array.insert(intArray, intArray + (this->_N - this->_array.size()));
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_array.size() < 2)
		throw Span::SpanNotFoundException();
	double shortest = UINT_MAX;
	std::multiset<int>::iterator it = this->_array.begin();
	while (it != std::prev(this->_array.end()))
	{
		std::multiset<int>::iterator it2 = std::next(this->_array.begin());
		while (it2 != this->_array.end())
		{
			if (abs(*it2 - *it) < shortest && it != it2)
				shortest = abs(*it - *it2);
			it2++;
		}
		it++;
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void)
{
	if (this->_array.size() < 2)
		throw Span::SpanNotFoundException();
	return (abs(*this->_array.begin() - *std::prev(this->_array.end())));
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
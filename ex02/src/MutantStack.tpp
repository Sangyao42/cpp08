/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:30:46 by sawang            #+#    #+#             */
/*   Updated: 2023/11/25 18:19:10 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
// #include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &cpy) : std::stack<T, Container>(cpy)
{}

template <class T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	if (this != &rhs)
		std::stack<T, Container>::operator=(rhs);
	return (*this);
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack()
{}

//In the standard std::stack container adapter,
//c is the name of the protected member variable
//that holds the underlying container
//(which can be a std::deque, std::vector, or std::list).
// his->c will be an object of that type(underlying container type).

// The underlying container is the actual data structure
// that stores the elements of the stack.

//iterator
template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

//reverse_iterator
template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

//const_iterator
template <class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin() const
{
	return (this->c.cbegin());
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend() const
{
	return (this->c.cend());
}

//const_reverse_iterator
template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin() const
{
	return (this->c.crbegin());
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend() const
{
	return (this->c.crend());
}
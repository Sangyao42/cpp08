/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:54:20 by sawang            #+#    #+#             */
/*   Updated: 2023/11/25 18:19:01 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>

template <class T, class Container>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &cpy);
		MutantStack &operator=(MutantStack const &rhs);
		virtual ~MutantStack();

		//iterator
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		//reverse_iterator
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		//const_iterator
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const_iterator cbegin() const;
		const_iterator cend() const;

		//const_reverse_iterator
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

	private:
};

#include "../src/MutantStack.tpp"
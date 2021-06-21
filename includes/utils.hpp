/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:18:19 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 17:39:27 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {

	template < typename T >
	struct node
	{
		node	*prev;
		node	*next;
		T		data;
	};

	template <bool, class IsTrue = void>
	struct enable_if;

	template <class IsTrue>
	struct enable_if<true, IsTrue> {
		typedef IsTrue type;
	};

	template <typename T>
	void	mySwap(T & a, T & b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;
		
		first_type		first;
		second_type		second;
		
		pair( void ) : first(), second()	{};
	
		template<class U, class V>
		pair(const pair<U, V>& pr) : first( pr.first ), second( pr.second )		{};
	
		pair(const first_type &a, const second_type &b) : first(a), second(b)	{};
	
		pair&	operator=(const pair &pr)
		{
			if (this == &pr)
				return (*this);

			this->first = pr.first;
			this->second = pr.second;
		
			return ( *this );
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return ( lhs.first == rhs.first && lhs.second == rhs.second );
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return ( !(lhs == rhs) );
	}

	template <class T1, class T2>
	bool operator< (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return ( lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second) );
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return ( !(rhs < lhs) );
	}

	template <class T1, class T2>
	bool operator> (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return ( (rhs < lhs) );
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return ( !(lhs < rhs) );
	}

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u) {
		return ft::pair<T1, T2>(t, u);
	};

	template <class Key, class T>
	struct BTNode
	{
		BTNode *left;
		BTNode *right;
		BTNode *parent;
		ft::pair<Key, T> pair;
		bool end;
	};
};

#endif
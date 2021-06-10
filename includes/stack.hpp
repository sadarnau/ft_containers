/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:48:37 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/10 17:17:10 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

namespace ft
{
	template < class T, class Container = std::deque<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type	c;

		public:

	/*
		MEMBER FUNCTIONS
	*/

	//(constructor) :

		explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
		{ return ;}
	
		~stack(void) 						{ return ; }

		bool empty() const 					{ return ( c.empty() ); }
	
		size_type size() const 				{ return ( c.size() ); }
	
		value_type& top()					{ return ( c.back() ); }
		const value_type& top() const		{ return ( c.back() ); }

		void push (const value_type& val)	{ return ( c.push_back(val) ); }

		void pop() 							{ return ( c.pop_back() ); }


		friend bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

		friend bool operator< (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return (lhs.c < rhs.c);
		}
	};

/*
	NON-MEMBER FUNCTION OVERLOADS
*/


	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return ( !(lhs == rhs) ); }
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (!(rhs < lhs)); }
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (rhs < lhs); }
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{ return (!(lhs < rhs)); }
}

#endif
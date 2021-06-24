/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:09:59 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/16 16:28:38 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <deque>

namespace ft
{
	template < class T, class Container = std::deque<T> >
	class queue
	{
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef std::size_t		size_type;

		private:
			container_type		c;

		public:

	/*
		MEMBER FUNCTIONS
	*/

	//(constructor) :

		explicit queue (const container_type& ctnr = container_type()) : c(ctnr) { return ;}
	
		~queue(void)						{ return ; }

		bool empty() 				const	{ return ( c.empty() ); }
	
		size_type size()			const	{ return ( c.size() ); }
	
		value_type& front()					{ return ( c.front() ); }
		const value_type& front()	const	{ return ( c.front() ); }
		value_type& back()					{ return ( c.back() ); }
		const value_type& back()	const	{ return ( c.back() ); }
	
		void push (const value_type& val)	{ return ( c.push_back(val) ); }

		void pop()							{ return ( c.pop_front() ); }


		friend bool operator== (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

		friend bool operator< (const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (lhs.c < rhs.c);
		}
	};

/*
	NON-MEMBER FUNCTION OVERLOADS
*/


	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)	{ return ( !(lhs == rhs) ); }
	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)	{ return (!(rhs < lhs)); }
	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)	{ return (rhs < lhs); }
	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)	{ return (!(lhs < rhs)); }
}

#endif
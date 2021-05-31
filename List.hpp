/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:15:24 by sadarnau          #+#    #+#             */
/*   Updated: 2021/05/27 15:47:42 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <string>

namespace ft
{
	template < typename T >
	struct node
	{
		node	*prev;
		node	*next;
		T		data;
	};

	template < typename T >
	class List
	{
	public:
		typedef T										value_type;
		// typedef _Alloc								allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef size_t									size_type;
		// typedef ft::Iterator					iterator;
		// typedef ft::const_iterator			const_iterator;
		// typedef _VSTD::reverse_iterator<iterator>		reverse_iterator;
		// typedef _VSTD::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:

		node<T>			*_head;
		node<T>			*_tail;
		size_type		_lenght;

	public:

		List( void ) : _lenght(0)
		{
			this->_tail = new node<value_type>;
			this->_head = new node<value_type>;
			this->_tail->next = NULL;
			this->_tail->prev = this->_head;
			this->_head->next = this->_tail;
			this->_head->prev = NULL;
			return ;
		}

		List( List const & src)
		{
			*this= src;

			return ;
		}

		~List( void ) {return ;};
		
		List & operator=( List const & rhs )
		{
		// 	node<value_type>	tmp;
		// 	tmp = _head;
		// 	while (tmp != this->_tail)
		// 	{
		// 		this->
		// 	}

			return ( *this );
		}

		void		push_back( const_reference data )
		{
			node<value_type>	*tmp = new node<value_type>;
			tmp->data = data;

			if (this->_tail->prev)
			{
				tmp->prev = this->_tail->prev;
				this->_tail->prev->next = tmp;
			}

			tmp->next = this->_tail;
			this->_tail->prev = tmp;

			this->_lenght++;

			return ;
		}

		void		pop_back( void )
		{
			node<value_type>	*tmp = this->_tail->prev;

			this->_tail->prev = tmp->prev;
			tmp->next = this->_tail;

			delete (tmp);

			this->_lenght--;

			return ;
		}

		void		push_front( const_reference data )
		{
			node<value_type>	*tmp = new node<value_type>;
			tmp->data = data;

			if (this->_head->next)
			{
				tmp->next = this->_head->next;
				this->_head->next->prev = tmp;
			}

			tmp->prev = this->_head;
			this->_head->next = tmp;

			this->_lenght++;

			return ;
		}

		void		pop_front( void )
		{
			node<value_type>	*tmp = this->_head->next;

			delete (this->_head);
			this->_head = tmp;

			this->_lenght--;
			
			return ;
		}
		value_type	back( void ) { return ( this->_tail->prev->data ); }

		value_type	front( void ) { return ( this->_head->next->data ); }

		bool		empty( void ) { return (this->_lenght == 0); }

		size_type	size( void ) { return ( this->_lenght ); }

		void		clear( void )
		{
			node<value_type>	*tmp, *tmp2;
			tmp = this->_head;

			while (tmp)
			{
				tmp2 = tmp->next;
				delete(tmp);
				tmp = tmp2;
			}

			this->_lenght = 0;
			this->_head = NULL;
			this->_tail = NULL;
			return ;
		}
		
		void		resize( size_type count )
		{
			
			return ;
		}
	};
}
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:23:17 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/02 17:58:51 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <iostream>
# include <limits>
# include "listIterators.hpp"

namespace ft
{
	template < typename T >
	class list
	{
	public:
		typedef T						value_type;
		typedef value_type&				reference;
		typedef const value_type&		const_reference;
		typedef value_type*				pointer;
		typedef const value_type*		const_pointer;
		typedef size_t					size_type;
		typedef listIterator<T>			iterator;
		typedef constListIterator<T>	const_iterator;


	private:
		node<T>			*_head;
		node<T>			*_tail;
		size_type		_lenght;

	public:

	/*
		MEMBER FUNCTIONS
	*/

		void		initList( void )
		{
			this->_tail = new node<value_type>;
			this->_head = new node<value_type>;
		
			this->_head->prev = NULL;
			this->_head->next = this->_tail;
			// this->_head->data = 0;

			// this->_tail->data = 0;
			this->_tail->next = NULL;
			this->_tail->prev = this->_head;

			this->_lenght = 0;

			return ;
		}

	//(constructor) :
	
		explicit	list( void )
		{
			this->initList();

			return ;
		}

		explicit	list ( size_type n, const value_type& val = value_type() )
		{
			this->initList();
			//assign ??
			for (size_type i = 0; i != n; i++)
				push_back(val);
		
			return ;
		}

		template <class InputIterator>
		list ( InputIterator first, InputIterator last )
		{
			this->initList();
			assign(first, last);

			return ;
		}

		list( list const & src)
		{
			this->initList();
			*this = src;

			return ;
		}
		
	//(destructor) :

		~list( void ) { return ; }
		
	//operator= :

		list & operator=( list const & rhs )
		{
			this->clear();
			this->assign( rhs.begin(), rhs.end() );
			this->_lenght = rhs._lenght;

			return( *this );
		}

	/*
		ITERATORS
	*/

		iterator		begin(void)			{ return( iterator( this->_head->next )); }
		const_iterator	begin(void) const	{ return( const_iterator( this->_head->next )); }
		iterator		end(void) 			{ return( iterator( this->_tail )); }
		const_iterator	end(void) const		{ return( const_iterator( this->_tail )); }
		
		// reverse_iterator rbegin()	{};
		// const_reverse_iterator rbegin() const	{};
		// reverse_iterator rend()	{};
		// const_reverse_iterator rend() const	{};

	/*
		CAPACITY
	*/

		bool		empty( void )		{ return( this->_lenght == 0 ); }
		size_type	size( void )		{ return( this->_lenght ); }
		size_type	size( void ) const	{ return( this->_lenght ); }
		size_type	max_size() const	{ return( std::numeric_limits<size_type>::max() / (sizeof(node<T>)) ); }

	/*
		ELEMENT ACCESS
	*/

		reference		front( void )	{ return( this->_head->next->data ); }
		const_reference front() const	{ return( this->_head->next->data ); }
		reference		back( void )	{ return( this->_tail->prev->data ); }
		const_reference back() const	{ return( this->_tail->prev->data ); }


	/*
		MODIFIERS
	*/

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
				push_back(*first++);

			return ;
		}

		void	assign (size_type n, const value_type& val)
		{
			clear();
			while (n--)
				push_back(val);
		
			return ;
		}

		void	push_front( const value_type& data )
		{
			node<value_type>	*tmp = new node<value_type>;
			tmp->data = data;

			if (this->_lenght == 0)
			{
				tmp->next = this->_tail;
				this->_tail->prev = tmp;
			}
			else
			{
				tmp->next = this->_head->next;
				this->_head->next = tmp;
			}
			
			tmp->prev = this->_head;
			this->_head->next = tmp;

			this->_lenght++;

			return ;
		}

		void	pop_front( void )
		{
			node<value_type>	*tmp = this->_head->next;

			this->_head->next = tmp->next;
			tmp->next->prev = this->_head;

			delete (tmp);

			this->_lenght--;
			
			return ;
		}

		void	push_back( const value_type& data )
		{
			node<value_type>	*tmp = new node<value_type>;
			tmp->data = data;

			if (this->_lenght == 0)
			{
				tmp->prev = this->_head;
				this->_head->next = tmp;
			}
			else
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
			tmp->prev->next = this->_tail;

			delete (tmp);

			this->_lenght--;

			return ;
		}

		iterator insert (iterator position, const value_type& val)
		{
			node<value_type>	*tmp = new node<value_type>;

			position.node()->prev->next = tmp;
			tmp->next = position.node();
			tmp->prev = position.node()->prev;
			position.node()->prev = tmp;

			tmp->data = val;

			return ( tmp );
		}

		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (list& x);

		void resize (size_type n, value_type val = value_type());

		void	clear( void )
		{
			node<value_type>	*tmp, *tmp2;
			tmp = this->_head->next;

			while (tmp->next)
			{
				tmp2 = tmp->next;
				delete(tmp);
				tmp = tmp2;
			}

			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			this->_lenght = 0;

			return ;
		}
			
		/*
			MODIFIERS
		*/

		void splice (iterator position, list& x);
		void splice (iterator position, list& x, iterator i);
		void splice (iterator position, list& x, iterator first, iterator last);

		void remove (const value_type& val);

		template <class Predicate>
  		void remove_if (Predicate pred);
	
		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);

		void merge (list& x);
		template <class Compare>
		void merge (list& x, Compare comp);

		void sort();
		template <class Compare>
		void sort (Compare comp);

		void reverse();
	};

	template<typename T>
	bool operator==(list<T> const& lhs, list<T> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename list<T>::const_iterator it1 = lhs.begin();
		typename list<T>::const_iterator it2 = rhs.begin();
		while (it1 != lhs.end())
			if (*it1++ != *it2++)
				return (false);
		return (true);
	}

	template<typename T>
	bool operator!=(list<T> const &lhs, list<T> const &rhs) { return ( !(lhs == rhs) ); }
}
#endif

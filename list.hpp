/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:23:17 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/09 18:03:42 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <iostream>
# include <limits>
# include "listIterators.hpp"
# include "revListIterators.hpp"

namespace ft
{
	template < typename T >
	class list
	{
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef size_t						size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef ft::listIterator<T>			iterator;
		typedef ft::constListIterator<T>	const_iterator;
		typedef ft::revListIterator<T>		reverse_iterator;
		typedef ft::constRevListIterator<T>	const_reverse_iterator;


	private:
		node<T>			*_head;
		node<T>			*_tail;
		size_type		_length;

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

			this->_length = 0;

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

		~list( void )
		{				
			clear();
			delete this->_head;
			delete this->_tail;
			
			return ; 
		}
		
	//operator= :

		list & operator=( list const & rhs )
		{
			this->clear();
			this->assign( rhs.begin(), rhs.end() );
			this->_length = rhs._length;

			return( *this );
		}

	/*
		ITERATORS
	*/

		iterator		begin(void)			{ return( iterator( this->_head->next )); }
		const_iterator	begin(void) const	{ return( const_iterator( this->_head->next )); }
		iterator		end(void) 			{ return( iterator( this->_tail )); }
		const_iterator	end(void) const		{ return( const_iterator( this->_tail )); }
		reverse_iterator rbegin()				{ return( reverse_iterator( this->_tail->prev )); }
		const_reverse_iterator rbegin() const	{ return( const_reverse_iterator( this->_tail->prev )); }
		reverse_iterator rend()					{ return ( reverse_iterator( this->_head )); }
		const_reverse_iterator rend() const		{ return( const_reverse_iterator( this->head )); }

	/*
		CAPACITY
	*/

		bool		empty( void )		{ return( this->_length == 0 ); }
		size_type	size( void )		{ return( this->_length ); }
		size_type	size( void ) const	{ return( this->_length ); }
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

			if (this->_length == 0)
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

			this->_length++;

			return ;
		}

		void	pop_front( void )
		{
			node<value_type>	*tmp = this->_head->next;

			this->_head->next = tmp->next;
			tmp->next->prev = this->_head;

			delete (tmp);

			this->_length--;
			
			return ;
		}

		void	push_back( const value_type& data )
		{
			node<value_type>	*tmp = new node<value_type>;
			tmp->data = data;

			if (this->_length == 0)
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

			this->_length++;

			return ;
		}

		void		pop_back( void )
		{
			node<value_type>	*tmp = this->_tail->prev;

			this->_tail->prev = tmp->prev;
			tmp->prev->next = this->_tail;

			delete (tmp);

			this->_length--;

			return ;
		}

		iterator insert (iterator position, const value_type& val)
		{
			node<value_type>	*tmp = new node<value_type>;

			position->prev->next = tmp;
			tmp->next = position.node();
			tmp->prev = position->prev;
			position->prev = tmp;

			tmp->data = val;
			this->_length++;

			return ( tmp );
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			while (n--)
				insert(position, val);

			return ;
		}

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, first->data);
				first++;
			}

			return;
		}

		iterator erase (iterator position)
		{
			node<value_type>	*tmp;

			tmp = position->next;
			tmp->prev = position->prev;
			position->prev->next = tmp;

			this->_length--;

			return (tmp);
		}
		
		iterator erase (iterator first, iterator last)
		{
			while (first != last)
				erase(first++);

			return (last);
		}

		void swap (list& x)
		{
			size_t tmp = x._length;
			x._length = this->_length;
			this->_length = tmp;

			node<T> *it = x._head;
			x._head = this->_head;
			this->_head = it;

			it = x._tail;
			x._tail = this->_tail;
			this->_tail = it;

			return ;
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_length)
				while (n < this->_length)
					pop_back();
			else if (n > this->_length)
				while (n > this->_length)
					push_back(val);

			return;
		}

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
			this->_length = 0;

			return ;
		}
			
		/*
			MODIFIERS
		*/

		void splice (iterator position, list& x)
		{
			splice(position, x, x.begin(), x.end());

			return ;
		}

		void splice (iterator position, list& x, iterator i)
		{
			insert(position, *i);
			x.erase(i);

			return ;
		}

		void splice (iterator position, list& x, iterator first, iterator last)
		{
			insert(position, first, last);
			x.erase(first, last);

			return;
		}

		void remove (const value_type& val)
		{
			for(iterator it = this->begin(); it != this->end(); it++)
				if (*it == val)
					erase(it);

			return ;
		}

		template <class Predicate>
  		void remove_if (Predicate pred)
		{
			for(iterator it = this->begin(); it != this->end(); it++)
				if (pred(*it))
					erase(it);

			return ;
		}

		void unique()
		{
			for(iterator it = this->begin(); it != this->end(); it++)
				if (*it == it.node()->next->data)
				{
					erase(it.node()->next);
					it--;
				}

			return ;
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator curr = this->begin();
			iterator next = this->begin();
			next++;
			
			while (next != this->end())
			{
				if (binary_pred(*curr, *next))
				{
					this->erase(next);
					next = curr;
				}
				else
					curr = next;
				next++;
			}

			return ;
		}

		void merge (list& x)
		{
			if (&x == this)
				return;



			// insert(this->end(), x.begin(), x.end());
			// x.clear();
			// sort(less);
	
			return ;	
		}

		template <class Compare>
		void merge (list& x, Compare comp)
		{
			if (&x == this)
				return;
			insert(this->end(), x.begin(), x.end());
			x.clear();
			sort(comp);
		}

		void sort() { sort(less); }

		template <class Compare>
		void sort (Compare comp)
		{
			iterator it1 = this->begin(), it2;

			while (it1 != this->end())
			{
				it2 = it1->next;
				while (it2 != this->end())
				{
					if (comp(*it1, *it2))
					{
						value_type tmp = *it1;
						*it1 = *it2;
						*it2 = tmp;
					}
					it2++;
				}
				it1++;
			}

			return;
		}

		void reverse()
		{
			list<value_type> tmp;

			iterator it = this->begin();
			while (it != this->end())
				tmp.push_front(*it++);
			
			*this = tmp;
		
			return ;
		}

		static bool	less(T& lvalue, T& rvalue) { return (lvalue > rvalue); };

		// void	exchange(list &src) 
		// {
		// 	this->clear();
		// 	node<value_type> tmp = this->_head;

		// 	this->_head = src._head;
		// 	this->_length = src._length;
		// 	src._head = tmp; src._length = 0;
		// 	tmp = NULL;
		// }
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
	bool operator!=(list<T> const &lhs, list<T> const &rhs)		{ return ( !(lhs == rhs) ); }

	template <class T>
	bool operator<(const list<T>& lhs, const list<T>& rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);

		constListIterator<T> it1 = lhs.begin();
		constListIterator<T> it2 = rhs.begin();
		
		while (it1 != lhs.end())
		{
			if (*it1 != *it2)
				return (*it1 < *it2);
			it1++;
			it2++;
		}	

		return (false);	
	}

	template <class T>
	bool operator<=(const list<T>& lhs, const list<T>& rhs)	{ return (!(rhs < lhs)); }
	template <class T>
	bool operator>(const list<T>& lhs, const list<T>& rhs)	{ return (rhs < lhs); }
	template <class T>
	bool operator>=(const list<T>& lhs, const list<T>& rhs)	{ return (!(lhs < rhs)); }

	template <class T>
	void swap (list<T>& x, list<T>& y) { x.swap(y); }

}
#endif

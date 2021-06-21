/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:23:17 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 17:37:39 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <iostream>
# include <limits>
# include "listIterators.hpp"
# include "revListIterators.hpp"
# include "utils.hpp"

namespace ft
{
	template < typename T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T										value_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef size_t									size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef ft::listIterator<T>						iterator;
			typedef ft::constListIterator<T>				const_iterator;
			typedef ft::revListIterator<T, iterator>		reverse_iterator;
			typedef ft::revListIterator<T, const_iterator>	const_reverse_iterator;
			typedef ft::node<T>								node_type;
			typedef node_type*								node_ptr;

		private:
			node<T>			*_tail;
			size_type		_length;

		public:

	/*
		MEMBER FUNCTIONS
	*/

		void		initList( void )
		{
			this->_tail = new node<value_type>;
			this->_tail->next = this->_tail;
			this->_tail->prev = this->_tail;
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
			for (size_type i = 0; i != n; i++)
				push_back(val);
			return ;
		}

		template <class InputIterator>
		list ( typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last )
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

		iterator				begin(void)			{ return( iterator( this->_tail->next )); }
		const_iterator			begin(void)	const	{ return( const_iterator( this->_tail->next )); }
		iterator				end(void) 			{ return( iterator( this->_tail )); }
		const_iterator			end(void) 	const	{ return( const_iterator( this->_tail )); }
		reverse_iterator		rbegin()			{ return( reverse_iterator( this->_tail )); }
		const_reverse_iterator	rbegin()	const	{ return( const_reverse_iterator( this->_tail )); }
		reverse_iterator 		rend()				{ return( reverse_iterator( this->_tail->next )); }
		const_reverse_iterator	rend()		const	{ return( const_reverse_iterator( this->_tail->next )); }

	/*
		CAPACITY
	*/

		bool		empty( void )	const	{ return( this->_length == 0 ); }
		size_type	size( void )			{ return( this->_length ); }
		size_type	size( void )	const	{ return( this->_length ); }
		size_type	max_size()		const	{ return( std::numeric_limits<size_type>::max() / (sizeof(node<T>)) ); }

	/*
		ELEMENT ACCESS
	*/

		reference		front( void )			{ return( this->_tail->next->data ); }
		const_reference front()			const	{ return( this->_tail->next->data ); }
		reference		back( void )			{ return( this->_tail->prev->data ); }
		const_reference back()			const	{ return( this->_tail->prev->data ); }


	/*
		MODIFIERS
	*/

		template <class InputIterator>
		void	assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
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

		void	push_front( const value_type& data )	{ this->insert(begin(), data); }
		void	pop_front( void )						{ this->erase(this->begin()); }
		void	push_back( const value_type& data ) 	{ this->insert(this->end(), data); }
		void	pop_back( void )						{ this->erase(this->_tail->prev); }

		iterator insert (iterator position, const value_type& val)
		{
			node<value_type>	*tmp = new node<value_type>;

			tmp->next = position._ptr;
			tmp->prev = position._ptr->prev;
			tmp->data = val;

			position._ptr->prev->next = tmp;
			position._ptr->prev = tmp;
			this->_length++;
			
			return iterator(tmp);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			while (n--)
				insert(position, val);

			return ;
		}

		template <class InputIterator>
    	void insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				first++;
			}

			return;
		}

		iterator erase (iterator position)
		{			
			node<value_type>	*next = position._ptr->next;
			
			position._ptr->prev->next = next;
			next->prev = position._ptr->prev;

			delete (position._ptr);

			this->_length--;

			return (iterator(next));
		}
		
		iterator erase (iterator first, iterator last)
		{
			while (first != last)
				erase(first++);

			return (last);
		}

		void swap (list& x)
		{
			ft::mySwap(this->_length, x._length);
			ft::mySwap(this->_tail, x._tail);

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

		void	clear( void )	{ this->erase(this->begin(), this->end()); }
			
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
			this->splice(position, x, i, i + 1);

			return ;
		}

		void splice (iterator position, list& x, iterator first, iterator last)
		{
			node<T>		*previous = position.node()->prev, *positionNode = position.node();
			node<T>		*beginning = first.node(), *end = last.node()->prev;
			size_type	size = 0;

			while (first++ != last)
				size++;
	
			beginning->prev->next = end->next;
			end->next->prev = beginning->prev;

			previous->next = beginning;
			beginning->prev = previous;

			positionNode->prev = end;
			end->next = positionNode;

			this->_length += size;
			x._length -= size;

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
			this->merge(x, less);
	
			return ;	
		}

		template <class Compare>
		void merge (list& x, Compare comp)
		{
			if (&x == this)
				return;

			iterator it = this->begin(), itx = x.begin();

			while (itx != x.end() && it != this->end())
			{
				if (comp(*itx, *it))
					this->splice(it, x, itx++);
				else
					it++;
			}

			if (x._length != 0)
				this->splice(this->end(), x);
		
			return ;
		}


		void sort() { sort(less); }

		template <class Compare>
		void sort (Compare comp)
		{
			iterator 	it = this->begin(), it2;
			size_type	size = this->_length;

			while (size--)
			{
				it = this->begin();
				it2 = it + 1;
				while (it2 != this->end())
				{
					if (!comp(*it, *it2))
						this->splice(it, *this, it2);
					else
						it++;
					it2 = it + 1;
				}
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

		static bool	less(T& lvalue, T& rvalue) { return (lvalue < rvalue); };
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
		constListIterator<T> it1 = lhs.begin();
		constListIterator<T> it2 = rhs.begin();
		
		while (it1 != lhs.end() && it2 != rhs.end())
		{
			if (*it1 != *it2)
				return (*it1 < *it2);
			it1++;
			it2++;
		}	

		if (it2 != rhs.end())
			return(true);

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

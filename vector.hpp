/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:23:17 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/07 18:52:05 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <limits>
# include "vectorIterators.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T							value_type;
		typedef Alloc						allocator_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef size_t						size_type;
		typedef vectorIterator<T>			iterator;
		typedef constVectorIterator<T>		const_iterator;
		typedef revVectorIterator<T>		reverse_iterator;
		typedef constRevVectorIterator<T>	const_reverse_iterator;
		typedef ptrdiff_t					difference_type;

	private:
		pointer			_container;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

	public:

	/*
		MEMBER FUNCTIONS
	*/

	//(constructor) :
		
		explicit vector (const allocator_type& alloc = allocator_type()) : _container(0), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_container = this->_alloc.allocate(0);

			return ;
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _container(0), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_container = this->_alloc.allocate(0);
			this->reserve(n);
			while (n--)
				this->push_back(val);

			return ;
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _container(0), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_alloc.allocate(0);
			this->assign(first, last);

			return ;
		}

		vector (const vector& x) : _container(0), _size(0), _capacity(0), _alloc(x._alloc)
		{
			*this = x;

			return ;
		}
			
	//(destructor) :

		~vector( void )
		{ 
			_alloc.deallocate( this->_container, this->_capacity );
			// _alloc.destroy( this->_container, this->_capacity ); ???s

			return ;
		}
		
	//operator= :

		vector& operator=( const vector& x )
		{
			this->clear();
			this->reserve(x._size);
			for (const_iterator it = x.begin(); it != x.end(); it++)
				this->push_back(*it);

			return (*this);
		}

	/*
		ITERATORS
	*/

		iterator				begin(void)			{ return ( iterator(this->_container) ); }
		const_iterator			begin(void) const	{ return ( const_iterator(this->_container) ); }
		iterator				end(void) 			{ return ( iterator(this->_container + this->_size) ); }
		const_iterator			end(void) 	const	{ return ( const_iterator(this->_container + this->_size) ); }
		reverse_iterator 		rbegin()			{ return ( reverse_iterator(this->_container + this->_size) ); }
		const_reverse_iterator	rbegin() 	const	{ return ( const_reverse_iterator(this->_container + this->_size) ); }
		reverse_iterator 		rend()				{ return ( reverse_iterator(this->_container + this->_size) ); }
		const_reverse_iterator	rend() 		const	{ return ( const_reverse_iterator(this->_container) ); }

	/*
		CAPACITY
	*/

		size_type	size( void ) const		{ return ( this->_size ); }
		size_type	max_size() const	{ return ( std::numeric_limits<size_type>::max() / sizeof(value_type)); }
		
		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_size)
				while (this->_size > n)
					this->pop_back();

			if (n > this->_size)
				while (this->_size < n)
					this->push_back(val);

			return ;
		}

		size_type capacity() const		{ return ( this->_capacity ); }
		bool empty() const				{ return( this->_size == 0 ); }
		
		void reserve (size_type n)
		{
			if (n > this->_capacity)
			{
				pointer	tmp;
				tmp  = _alloc.allocate(n);
				for (size_type i = 0; i < this->_capacity; i++)
					this->_alloc.construct(tmp + i, *(this->_container + i));
				this->_capacity = n;
				this->_container = tmp;
			}

			return ;
		}

	/*
		ELEMENT ACCESS
	*/
    	
		reference		operator[] ( size_type n )		{ return ( this->_container[n] ); }
		const_reference	operator[] ( size_type n ) const{ return ( this->_container[n] ); }

		reference 		at ( size_type n )
		{
			if (n < 0 || n >= this->_size)
				throw (std::out_of_range("vector"));

			return (this->_container[n]);
		}

		const_reference at ( size_type n ) const
		{
			if (n < 0 || n >= this->_size)
				throw (std::out_of_range("vector"));
			return (this->_container[n]);
		}

		reference		front( void )			{ return ( *this->_container ); }
		const_reference front( void )	const	{ return ( *this->_container ); }
		reference		back( void )			{ return ( this->_container[this->_size - 1] ); }
		const_reference back( void )	const	{ return ( this->_container[this->_size - 1] ); }

	/*
		MODIFIERS
	*/

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			iterator	tmp = first;
			size_t		n = 0;

			while(tmp++ != last)
				n++;
			this->clear();
			this->reserve(n);
			for (iterator it = first; it != last; it++)
				this->push_back(*it);

			return ;
		}

		void assign (size_type n, const value_type& val)
		{
			this->clear();
			this->reserve(n);
			while (n--)
				this->push_back(val);

			return ;
		}

		void	push_back( const value_type& data )
		{
			if (this->_capacity == 0)
			{
				this->_container = _alloc.allocate(1);
				this->_capacity++;
			}
			if ( this->_size == this->_capacity)
				reserve(this->_capacity * 2);
			this->_container[this->_size] = data;
			this->_size++;

			return ;
		}

		void	pop_back( void )
		{
			this->_alloc.destroy(&_container[_size - 1]);
			this->_size--; 
		
			return ;
		}

		iterator insert (iterator position, const value_type& val)
		{
			insert(position, (size_t)1, val);

			return (position);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			vector tmp(position, this->end());

			this->erase(position, this->end());
			while (n--)
				this->push_back(val);

			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				this->push_back(*it);

			return ;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			vector tmp(position, this->end());

			this->erase(position, this->end());
			while (first != last)
				this->push_back(*first++);

			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				this->push_back(*it);

			return ;
		}

		iterator erase (iterator position)
		{
			iterator tmp = position;

			while (tmp + 1 != this->end())
			{
				*tmp = *(tmp + 1);
				tmp++;
			}
			
			this->_size--;

			return (position);
		}

		iterator erase (iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				last--;
			}
			return (first);
		}

		void swap (vector& x)
		{
			vector tmp(x);

			x = *this;
			*this = tmp;

			return ;
		}

		void clear() { erase(this->begin(), this->end()); }
			
	/*
		ALLOCATOR
	*/
		allocator_type get_allocator() const;
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs._size != rhs._size)
			return (false);

		for (size_t i = 0; i != rhs._size; i++)
			if (lhs[i] != rhs[i])
				return (false);
		
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }
	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t		n;

		if (lhs.size() > rhs.size())
			n = rhs.size();
		else
			n = lhs.size();

		for (size_t i = 0; i < n; i++)
			if (lhs[i] != rhs[i])
				return (lhs[i] < rhs[i]);

		return (lhs.size() < rhs.size());
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return ( !(rhs < lhs) ); }
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return ( rhs < lhs ); }
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return ( !(lhs < rhs) ); }
	
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)	{ x.swap(y); }

}
#endif

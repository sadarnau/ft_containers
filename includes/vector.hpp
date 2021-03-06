/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:23:17 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/28 14:25:10 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <limits>
# include "vectorIterators.hpp"
# include "revVectorIterators.hpp"
# include "utils.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef ft::vectorIterator<T>			iterator;
			typedef ft::constVectorIterator<T>		const_iterator;
			typedef ft::revVectorIterator<T, iterator>		reverse_iterator;
			typedef ft::revVectorIterator<T, const_iterator>	const_reverse_iterator;

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
			insert(this->begin(), n, val);

			return ;
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _container(0), _size(0), _capacity(0), _alloc(alloc)
		{
			this->_container = this->_alloc.allocate(0);
			this->assign(first, last);

			return ;
		}

		vector (const vector& x) : _container(0), _size(0), _capacity(0), _alloc(x._alloc)
		{
			this->_container = this->_alloc.allocate(0);
			this->assign(x.begin(), x.end());

			return ;
		}
			
	//(destructor) :

		~vector( void )
		{ 
			while (_size)
				pop_back();

			_alloc.deallocate( this->_container, this->_capacity );

			return ;
		}
		
	//operator= :

		vector& operator=( const vector& x )
		{
			if (this == &x)
				return (*this);
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
		reverse_iterator 		rend()				{ return ( reverse_iterator(this->_container) ); }
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
			{
				if(n > this->_size * 2)
					this->reserve(n);
				while (this->_size < n)
					this->push_back(val);
			}

			return ;
		}

		size_type capacity() const		{ return ( this->_capacity ); }
		bool empty() const				{ return( this->_size == 0 ); }
		
		void reserve (size_type n)
		{
			if (n > this->max_size())
				throw (std::out_of_range("vector::reserve"));

			if (n > this->_capacity)
			{
				pointer	tmp;
				tmp  = _alloc.allocate(n);
				if (_size != 0)
				{
					for (size_type i = 0; i < this->_size; i++)
					{
						this->_alloc.construct(&tmp[i], this->_container[i]);
						this->_alloc.destroy(&this->_container[i]);
					}
				}
				this->_alloc.deallocate( this->_container, this->_capacity );
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
		void assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			InputIterator	tmp = first;
			size_type		n = 0;

			while(tmp != last)
			{
				tmp++;
				n++;
			}
			this->clear();
			if (first == last)
			{
				this->push_back(*first);
				return;
			}
			this->reserve(n);

			for (InputIterator it = first; it != last; it++)
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
				this->_alloc.deallocate( this->_container, this->_capacity );
				this->_container = _alloc.allocate(1);
				this->_capacity++;
			}
			if ( this->_size == this->_capacity)
				reserve(this->_capacity * 2);
			
			_alloc.construct(&_container[_size], data);
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
			difference_type pos = position - begin();

			if( position != this->end())
			{
				vector tmp(position, this->end());
			
				this->erase(position, this->end());
				
				this->push_back(val);

				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					this->push_back(*it);
			}
			else
			{
				push_back(val);
				pos = this->_size - 1;
			}

			return (iterator(&_container[pos]));
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type	i = this->_size + n;
			difference_type cur = position - begin();

			this->reserve(i);

			for (i = n + this->_size - 1; i > cur + n - 1; i--)
			{
				this->_alloc.construct(&this->_container[i], this->_container[i - n]);
				this->_alloc.destroy(&this->_container[i - n]);
			}
			for (i = cur; i < cur + n; i++)
			{			
				this->_alloc.construct(&this->_container[i], val);
				this->_size++;
			}

			return ;
		}

		template <class InputIterator>
		void insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			InputIterator	tmp2 = first;
			size_type	n = 0;
			int			switchEnd = 0;

			while (tmp2++ != last)
				n++;

			if (this->_size)
			{
				size_t			i = this->_capacity;

				if (position == end())
					switchEnd = 1;

				if (this->_size + n > this->_capacity)
				{
					if (this->_size * 2 >= this->_size + n)
						i = this->_capacity * 2;
					else
						i = this->_size + n;
				}

				vector tmp(position, this->end());

				this->erase(position, this->end());
				this->reserve(i);

				while (first != last)
					this->push_back(*first++);
				if (!switchEnd)
					for (iterator it = tmp.begin(); it != tmp.end(); it++)
						this->push_back(*it);
			}
			else
			{
				this->reserve(n);
				while (first != last)
					this->push_back(*first++);
			}

			return ;
		}

		iterator erase (iterator position)
		{
			size_type pos = position - begin(), tmp = pos;

			_alloc.destroy(&_container[pos]);
			_size--;
			
			while(pos < _size)
			{
				_alloc.construct(&_container[pos], _container[pos + 1]);
				_alloc.destroy(&_container[pos + 1]);
				pos++;
			}

			return (iterator(&_container[tmp]));
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
			vector tmp;
			ft::mySwap(this->_capacity, x._capacity);
			ft::mySwap(this->_size, x._size);
			ft::mySwap(this->_container, x._container);

			return ;
		}

		void clear()
		{
			if (this->_size != 0)
				erase(this->begin(), this->end());
		}
			
	/*
		ALLOCATOR
	*/

		allocator_type get_allocator() const	{ return ( this->_alloc ); }

	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		for (size_t i = 0; i != rhs.size(); i++)
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

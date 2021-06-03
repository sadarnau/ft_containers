/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:23:17 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/03 16:32:14 by sadarnau         ###   ########.fr       */
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

	public:

	/*
		MEMBER FUNCTIONS
	*/

	//(constructor) :
	
	explicit vector (const allocator_type& alloc = allocator_type());
	explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	vector (const vector& x);
		
	//(destructor) :

		~vector( void ) { return ; }
		
	//operator= :

		vector& operator=( const vector& x );

	/*
		ITERATORS
	*/

		iterator				begin(void)			{}
		const_iterator			begin(void) const	{}
		iterator				end(void) 			{}
		const_iterator			end(void) 	const	{}		
		reverse_iterator 		rbegin()			{}
		const_reverse_iterator	rbegin() 	const	{}
		reverse_iterator 		rend()				{}
		const_reverse_iterator	rend() 		const	{}

	/*
		CAPACITY
	*/

		size_type	size( void )		{}
		size_type	max_size() const	{}
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

	/*
		ELEMENT ACCESS
	*/
    	
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference		front( void )	{}
		const_reference front() const	{}
		reference		back( void )	{}
		const_reference back() const	{}


	/*
		MODIFIERS
	*/

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void	push_back( const value_type& data ) {}
		void		pop_back( void ) {}

		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (vector& x) {}

		void clear() {}
			
	/*
		ALLOCATOR
	*/
		allocator_type get_allocator() const;
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

}
#endif

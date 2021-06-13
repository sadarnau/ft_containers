/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:40:33 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/13 16:42:51 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "mapIterators.hpp"
# include <memory>
# include <limits>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair< const Key, T > > >
	class map
	{
		public:
			typedef Key								key_type;
			typedef T							mapped_type;
			typedef std::pair<const key_type, mapped_type>						value_type;
			typedef Compare				key_compare;
			// typedef toComplete						value_compare;
			typedef Alloc							allocator_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef ft::mapIterator<Key, T>			iterator;
			// typedef ft::constMapIterator<Key, T>		const_iterator;
			// typedef ft::revMapIterator<Key, T>		reverse_iterator;
			// typedef ft::constRevMapIterator<Key, T>	const_reverse_iterator;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef BTNode<key_type, mapped_type>*	node;
			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{ return comp( x.first, y.first ); }
			};

		private:
			allocator_type	_alloc;
			key_compare 	_comp;
			node			_root;
			size_type		_length;

		public:
		
		node	newNode(key_type key, mapped_type value, node parent)
		{
			node node = new BTNode<key_type, mapped_type>;
			node->pair = std::make_pair(key, value);
			node->left = NULL;
			node->right = NULL;
			node->parrent = parent;

			return ( node );
		}

	/*
		MEMBER FUNCTIONS
	*/

	//(constructor) :

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc)
		{
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_length = 0;
			return ;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
		{


			return ;
		}

		map (const map& x);

	//(destructor) :

		~map();

	//operator= :

		map& operator= (const map& x);

	/*
		ITERATORS
	*/

		// iterator				begin(void)			{ return ( iterator() ); }
		// const_iterator			begin(void) const	{ return ( const_iterator() ); }
		// iterator				end(void) 			{ return ( iterator() ); }
		// const_iterator			end(void) 	const	{ return ( const_iterator() ); }
		// reverse_iterator 		rbegin()			{ return ( reverse_iterator() ); }
		// const_reverse_iterator	rbegin() 	const	{ return ( const_reverse_iterator() ); }
		// reverse_iterator 		rend()				{ return ( reverse_iterator() ); }
		// const_reverse_iterator	rend() 		const	{ return ( const_reverse_iterator() ); }

	/*
		CAPACITY
	*/

		bool		empty() 		const	{ return ( this->_size == 0 ); }
		size_type	size( void )	const	{ return ( this->_size ); }
		size_type	max_size()		const	{ return ( std::numeric_limits<size_type>::max() / sizeof(value_type)); }

	/*
		ELEMENT ACCESS
	*/

		mapped_type& operator[] (const key_type& k);

	/*
		MODIFIERS
	*/

		std::pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		void erase (iterator position);
		size_type erase (const key_type& k);
		void erase (iterator first, iterator last);

		void swap (map& x);

		void clear();

	/*
		OBSERVERS
	*/

		key_compare key_comp() const;
		value_compare value_comp() const;

	/*
		OPERATIONS
	*/

		iterator find (const key_type& k);
		// const_iterator find (const key_type& k) const;

		size_type count (const key_type& k) const;

		iterator lower_bound (const key_type& k);
		// const_iterator lower_bound (const key_type& k) const;

		iterator upper_bound (const key_type& k);
		// const_iterator upper_bound (const key_type& k) const;


		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		std::pair<iterator,iterator>	equal_range (const key_type& k);

	/*
		ALLOCATOR
	*/

		allocator_type get_allocator() const	{ return ( this->_alloc ); }

	};

}

#endif
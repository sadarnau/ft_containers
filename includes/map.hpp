/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:40:33 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/23 17:54:10 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "mapIterators.hpp"
# include "revMapIterators.hpp"
# include "utils.hpp"
# include <memory>
# include <iostream>
# include <limits>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair< const Key, T > > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			typedef ft::mapIterator<Key, T>						iterator;
			typedef ft::constMapIterator<Key, T>				const_iterator;
			typedef ft::revMapIterator<Key, T, iterator>		reverse_iterator;
			typedef ft::revMapIterator<Key, T, const_iterator>	const_reverse_iterator;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef BTNode<key_type, mapped_type>*				node;
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
			node			_end;
			size_type		_length;
			typename allocator_type::template rebind<BTNode<key_type, mapped_type> >::other _allocNode;

		public:
		
		node	newNode(key_type key, mapped_type value, node parent)
		{
			node node = new BTNode<key_type, mapped_type>;
			node->pair = ft::make_pair(key, value);
			node->left = NULL;
			node->right = NULL;
			node->parent = parent;

			return ( node );
		}

		void printTree( void ) { printTree(this->_root); }

		void printTree(node n)
		{
			if (!n)
				return;
			printTree(n->left);
			if (n != this->_end)
				std::cout << n->pair.first << " : " << n->pair.second << std::endl;
			printTree(n->right);
		}
 
		void	deleteNode(node n)
		{
			node parent = n->parent;
			
			if (n == this->_root)
			{
				if (!n->left && !n->right)
				{
					delete n;
					this->_root = newNode(key_type(), mapped_type(), NULL);
					this->_root->right = this->_end;
					return ;
				}
				if (n->left && !n->right)
				{
					this->_root = n->left;
					delete n;
					return ;
				}
				if (n->right && !n->left)
				{
					this->_root = n->right;
					delete n;
					return ;
				}
			}

			if (n == this->_end->parent)
				this->_end->parent = n->parent;
			// first case, no childs ! 
			if (!n->left && !n->right)
			{
				if (parent->right == n)
					parent->right = NULL;
				else
					parent->left = NULL;
				delete n;
				return ;
			}
			// second case, left but no right
			if (n->left && !n->right)
			{
				if (parent->right == n)
					parent->right = n->left;
				else
					parent->left = n->left;
				n->left->parent = parent;
				delete n;
				return ;
			}
			// third case, right but no left
			if (n->right && !n->left)
			{
				if (parent->right == n)
					parent->right = n->right;
				else
					parent->left = n->right;
				n->right->parent = parent;
				delete n;
				return ;
			}
		
			// last case, right and left
			// Find successor
			node succ = n->right, succParent = n;
			while (succ->left != NULL) {
				succParent = succ;
				succ = succ->left;
			}
			if (succParent != n)
				succParent->left = succ->right;
			else
				succParent->right = succ->right;
			
			ft::mySwap(n->pair, succ->pair);
			if (succ == this->_end->parent)
				this->_end->parent = n;
			delete succ;
		}

		void	deleteTree(node n)
		{
			if (n->right)
				deleteTree(n->right);
			if (n->left)
				deleteTree(n->left);
			delete n;

			return ;
		}

	/*
		MEMBER FUNCTIONS
	*/

	//(constructor) :

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _comp(comp), _length(0)
		{
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_end = newNode(key_type(), mapped_type(), this->_root);
			this->_root->right = this->_end;
		
			return ;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp)
		{
			this->_length = 0;
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_end = newNode(key_type(), mapped_type(), this->_root);
			this->_root->right = this->_end;
			this->insert(first, last);
			
			return ;
		}

		map (const map& x)
		{
			this->_length = 0;
			this->_comp = x._comp;
			this->_alloc = x._alloc;
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_end = newNode(key_type(), mapped_type(), this->_root);
			this->_root->right = this->_end;

			this->insert(x.begin(), x.end());

			return ;
		}

	//(destructor) :

		~map() { deleteTree(this->_root); }

	//operator= :

		map& operator= (const map& x)
		{
			this->clear();
			this->insert(x.begin(), x.end());
			return (*this);
		}

	/*
		ITERATORS
	*/

		iterator				begin(void)
		{
			if (_length == 0)
				return ( iterator(this->_end));

			node tmp = this->_root;
			
			while(tmp->left)
				tmp = tmp->left;
			
			return ( iterator(tmp) );
		}
		const_iterator			begin(void) const
		{
			if (_length == 0)
				return ( const_iterator(this->_end));
			node tmp = this->_root;
			
			while(tmp->left)
				tmp = tmp->left;
			
			return ( const_iterator(tmp) );
		}
		iterator				end(void) 			{ return ( iterator(this->_end) ); }
		const_iterator			end(void) 	const	{ return ( const_iterator(this->_end) ); }
		reverse_iterator 		rbegin()
		{
			node	tmp = this->_root;

			while (tmp->right)
				tmp = tmp->right;

			return (reverse_iterator(tmp));
		}
		const_reverse_iterator	rbegin() 	const
		{
			node	tmp = this->_root;

			while (tmp->right)
				tmp = tmp->right;

			return (const_reverse_iterator(tmp));
		}
		reverse_iterator 		rend()
		{
			if (_length == 0)
				return ( reverse_iterator(this->_end));
			node tmp = this->_root;

			while(tmp->left)
				tmp = tmp->left;
			return ( reverse_iterator(tmp) );
		}
		const_reverse_iterator	rend()	const
		{
						if (_length == 0)
				return ( reverse_iterator(this->_end));
			node tmp = this->_root;

			while(tmp->left)
				tmp = tmp->left;
			return ( const_reverse_iterator(tmp) );
		}
	/*
		CAPACITY
	*/

		bool		empty() 		const	{ return ( this->_length == 0 ); }
		size_type	size( void )	const	{ return ( this->_length ); }
		size_type	max_size()		const	{ return (std::numeric_limits<size_type>::max()/sizeof(ft::BTNode<key_type, mapped_type>)); }

	/*
		ELEMENT ACCESS
	*/

		mapped_type& operator[] (const key_type& k)
		{

			iterator	tmp = find(k);

			if (tmp != this->_end)
				return ( tmp->second );

			return ( this->insert(ft::make_pair(k, mapped_type())).first->second );
		}

	/*
		MODIFIERS
	*/

		ft::pair<iterator,bool> insert (const value_type& val)
		{
			node	newnode, previous;
			newnode = newNode(val.first, val.second, NULL);

			if (this->_length == 0)
			{
				this->_root->pair.first = val.first;
				this->_root->pair.second = val.second;
				++this->_length;
				delete (newnode);
				return ( ft::make_pair(iterator(this->_root), true) );
			}

			previous = this->_root;
			while(!newnode->parent)
			{
				if (previous->pair.first == val.first)
				{
					delete(newnode);
					return( ft::make_pair(iterator(previous), false) );
				}
				if (this->_comp(val.first, previous->pair.first))
				{
					if (previous->left)
						previous = previous->left;
					else
					{
						previous->left = newnode;
						newnode->parent = previous;
					}
				}
				else
				{
					if (previous->right && previous->right != this->_end)
						previous = previous->right;
					else
					{
						if (previous->right == this->_end)
							this->_end->parent = newnode;
						previous->right = newnode;
						newnode->parent = previous;
						if (this->_end->parent == newnode)
							newnode->right = this->_end;
					}
				}
			}

			++this->_length;

			return( ft::make_pair(iterator(newnode), true) );
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			node	newnode, previous;
			newnode = newNode(val.first, val.second, NULL);

			if (this->_length == 0)
			{
				this->_root->pair.first = val.first;
				this->_root->pair.second = val.second;
				++this->_length;
				delete (newnode);
				return ( iterator(this->_root) );
			}

			previous = this->_root;
			while(!newnode->parent)
			{
				if (previous->pair.first == val.first)
				{
					delete(newnode);
					return( iterator(previous) );
				}
				if (this->_comp(val.first, previous->pair.first))
				{
					if (previous->left)
						previous = previous->left;
					else
					{
						previous->left = newnode;
						newnode->parent = previous;
					}
				}
				else
				{
					if (previous->right && previous->right != this->_end)
						previous = previous->right;
					else
					{
						if (previous->right == this->_end)
							this->_end->parent = newnode;
						previous->right = newnode;
						newnode->parent = previous;
						if (this->_end->parent == newnode)
							newnode->right = this->_end;
					}
				}
			}

			++this->_length;

			return( iterator(newnode) );
		}
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while(first != last)
			{
				insert(*first);
				first++;
			}

			return ;
		}

		void erase (iterator position)
		{
			deleteNode(position.getPtr());
			--this->_length;

			return ;
		}

		size_type erase (const key_type& k)
		{
			iterator	tmp = find(k);

			if (tmp != this->_end)
			{
				this->erase(tmp);
				return (1);
			}

			return (0);
		}
		void erase (iterator first, iterator last)
		{
			iterator	tmp;
			
			while(first != last)
			{
				tmp = first + 1;
				this->erase(first);
				first = tmp;
			}

			return ;
		}

		void swap (map& x)
		{
			ft::mySwap(this->_root, x._root);
			ft::mySwap(this->_end, x._end);
			ft::mySwap(this->_length, x._length);

			return ;
		}

		void clear()
		{
			this->erase(begin(), end());
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_end->parent = this->_root;
			this->_root->right = this->_end;
			return ;
		}

	/*
		OBSERVERS
	*/

		key_compare key_comp()		const	{ return( this->_comp ); }
		value_compare value_comp()	const	{ return( value_compare(this->_comp) ); }

	/*
		OPERATIONS
	*/

		iterator find (const key_type& k)
		{
			node	tmp = this->_root;

			while(tmp)
			{
				if (tmp->pair.first == k)
					return ( iterator(tmp) );
				if (this->_comp(k, tmp->pair.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}

			return ( iterator(this->_end) );
		}

		const_iterator find (const key_type& k) const
		{
			node	tmp = this->_root;

			while(tmp)
			{
				if (tmp->pair.first == k)
					return ( const_iterator(tmp) );
				if (this->_comp(k, tmp->pair.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}

			return ( const_iterator(this->_end) );
		}

		size_type count (const key_type& k) const { return ((find(k) != this->end())); }

		iterator lower_bound (const key_type& k)
		{
			iterator it = this->begin();

			while (it != this->_end)
			{
				if (this->_comp(it->first, k) <= 0)
					return (it);
				++it;
			}

			return (this->end());
		}

		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = this->begin();

			while (it != this->end())
			{
				if (this->_comp(it->first, k) <= 0)
					return (it);
				++it;
			}

			return (this->end());
		}


		iterator upper_bound (const key_type& k)
		{
			iterator it = this->begin();

			while (it != this->_end)
			{
				if (it->first == k )
					return (++it);
				if (this->_comp(it->first, k) <= 0)
					return (it);
				++it;
			}

			return (this->end());
		}

		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = this->begin();

			while (it != this->end())
			{
				if (it->first == k )
					return (++it);
				if (this->_comp(it->first, k) <= 0)
					return (it);
				++it;
			}

			return (this->end());
		}

		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const { return ( ft::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k))); }
		ft::pair<iterator,iterator>				equal_range (const key_type& k) { return ( ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k))); }

	/*
		ALLOCATOR
	*/

		allocator_type get_allocator() const	{ return ( this->_alloc ); }
	};

	template < class Key, class T, class Compare, class Alloc>
	bool operator==(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename map<Key, T, Compare, Alloc>::const_iterator it1 = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();

		while (it1 != lhs.end())
			if (*it1++ != *it2++)
				return (false);

		return (true);
	}

	template < class Key, class T, class Compare, class Alloc>
	bool operator!=(map<Key, T, Compare, Alloc> const &lhs, map<Key, T, Compare, Alloc> const &rhs)		{ return ( !(lhs == rhs) ); }

	template < class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		constMapIterator<Key, T> it1 = lhs.begin();
		constMapIterator<Key, T> it2 = rhs.begin();
		
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

	template < class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)	{ return (!(rhs < lhs)); }
	template < class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)	{ return (rhs < lhs); }
	template < class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)	{ return (!(lhs < rhs)); }

}

#endif
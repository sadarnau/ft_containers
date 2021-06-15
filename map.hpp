/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:40:33 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/15 18:11:03 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "mapIterators.hpp"
# include <memory>
# include <iostream>
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
			typedef ft::mapIterator<Key, T>						iterator;
			typedef ft::constMapIterator<const Key, const T>		const_iterator;
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
			// node			_start;
			node			_end;
			size_type		_length;

		public:
		
		node	newNode(key_type key, mapped_type value, node parent)
		{
			node node = new BTNode<key_type, mapped_type>;
			node->pair = std::make_pair(key, value);
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
				// node succ = n->right, succParent = n;
				// while (succ->left != NULL) {
				// 	succParent = succ;
				// 	succ = succ->left;
				// }
				// if (succParent != n)
				// 	succParent->left = succ->right;
				// else
				// 	succParent->right = succ->right;
				
				// ft::swap(n->pair, succ->pair);
				// if (succ == this->_end->parent)
				// 	this->_end->parent = n;
				// delete succ;
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
			
			ft::swap(n->pair, succ->pair);
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
		: _comp(comp), _alloc(alloc), _length(0)
		{
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_end = newNode(key_type(), mapped_type(), this->_root);
			this->_root->right = this->_end;
			return ;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
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
			this->_root = newNode(key_type(), mapped_type(), NULL);
			this->_end = newNode(key_type(), mapped_type(), this->_root);
			this->_root->right = this->_end;
			*this = x;

			return ;
		}

	//(destructor) :

		~map() { deleteTree(this->_root); }

	//operator= :

		map& operator= (const map& x)
		{
			this->clear();
			this->_comp = x._comp;
			this->_alloc = x._alloc;
			this->insert(x.begin(), x.end());
			return (*this);
		}

	/*
		ITERATORS
	*/

		iterator				begin(void)
		{
			node tmp = this->_root;
			
			while(tmp->left)
				tmp = tmp->left;
			
			return ( iterator(tmp) );
		}
		const_iterator			begin(void) const
		{
			node tmp = this->_root;
			
			while(tmp->left)
				tmp = tmp->left;
			
			return ( const_iterator(tmp) );
		}
		iterator				end(void) 			{ return ( iterator(this->_end) ); }
		const_iterator			end(void) 	const	{ return ( const_iterator(this->_end) ); }
		// reverse_iterator 		rbegin()			{ return ( reverse_iterator() ); }
		// const_reverse_iterator	rbegin() 	const	{ return ( const_reverse_iterator() ); }
		// reverse_iterator 		rend()				{ return ( reverse_iterator() ); }
		// const_reverse_iterator	rend() 		const	{ return ( const_reverse_iterator() ); }

	/*
		CAPACITY
	*/

		bool		empty() 		const	{ return ( this->_length == 0 ); }
		size_type	size( void )	const	{ return ( this->_length ); }
		size_type	max_size()		const	{ return ( std::numeric_limits<size_type>::max() / sizeof(node)); }

	/*
		ELEMENT ACCESS
	*/

		mapped_type& operator[] (const key_type& k)
		{

			iterator	tmp = find(k);

			if (tmp != this->_end)
				return ( tmp->second );

			return ( this->insert(std::make_pair(k, mapped_type())).first->second );
		}

	/*
		MODIFIERS
	*/

		std::pair<iterator,bool> insert (const value_type& val)
		{
			node	newnode, previous;
			newnode = newNode(val.first, val.second, NULL);

			if (this->_length == 0)
			{
				this->_root->pair.first = val.first;
				this->_root->pair.second = val.second;
				++this->_length;
				delete (newnode);
				return ( std::make_pair(iterator(this->_root), true) );
			}

			previous = this->_root;
			while(!newnode->parent)
			{
				if (previous->pair.first == val.first)
				{
					delete(newnode);
					return( std::make_pair(iterator(previous), false) );
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

			return( std::make_pair(iterator(newnode), true) );
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
			while(first != last)
			{
				this->erase(first);
				first++;
			}

			return ;
		}

		void swap (map& x)
		{
			ft::swap(this->_root, x._root);
			ft::swap(this->_end, x._end);
			ft::swap(this->_lenght, x._lenght);

			return ;
		}

		void clear() { this->erase(begin(), end()); }

	/*
		OBSERVERS
	*/

		key_compare key_comp() const { return( this->_comp ); }
		value_compare value_comp() const  { return( value_compare(this->_comp) ); }

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
		const_iterator find (const key_type& k) const { return ( const_iterator(find(k)) ); }

		size_type count (const key_type& k) const { return ((find(k) == this->_end)); }

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

		const_iterator lower_bound (const key_type& k) const { return ( const_iterator(this->lower_bound(k)) ); }

		iterator upper_bound (const key_type& k)
		{
			iterator it = this->begin();

			while (it != this->end())
			{
				if (it->first == k )
					return (++it);
				if (this->_comp(it->first, k) <= 0)
					return (it);
				++it;
				std::cout << "caca";
			}

			return (this->end());
		}
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
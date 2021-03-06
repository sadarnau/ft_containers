/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:23:41 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 16:16:14 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_HPP
# define MAPITERATORS_HPP

# include "map.hpp"
# include "utils.hpp"
# include <utility>
# include <iostream>

namespace ft
{
	template <class Key, class T>
	class mapIterator
	{
		public:
			typedef ft::pair<Key, T>		value_type;
			typedef ft::pair<Key, T>&		reference;
			typedef BTNode<Key, T>*			pointer;
			typedef typename std::ptrdiff_t difference_type;
	
			pointer							_ptr;

			mapIterator( void ) : _ptr(NULL)		{}
			mapIterator( const mapIterator &rhs )	{ *this = rhs; }
			mapIterator( pointer ptr ) : _ptr(ptr)	{}
			~mapIterator( void ) 					{}
			
			mapIterator &operator=( const mapIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			mapIterator &operator++( void )	//++it
			{
				pointer next;

				if (!this->_ptr->right)
				{
					next = this->_ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = this->_ptr->right;
					while (next->left)
						next = next->left;
				}
				*this = next;
				return ( *this );
			}
			mapIterator operator++( int )		//it++
			{
				mapIterator tmp(*this);
				operator++();
				return (tmp);
			}
			mapIterator &operator--( void )
			{
				pointer next;

				if (!this->_ptr->left)
				{
					next = this->_ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = this->_ptr->left;
					while (next->right)
						next = next->right;
				}
				*this = next;
				return ( *this );
			}
			mapIterator operator--( int )
			{
				mapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			mapIterator operator+(int n) const
			{
				mapIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			mapIterator operator-(int n) const
			{
				mapIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			mapIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			mapIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(mapIterator b) { return ( this->_ptr - b._ptr ); }	// a - b
			difference_type operator +(mapIterator b) { return ( this->_ptr + b._ptr ); }	// a + b
		
			bool operator !=(mapIterator const &rhs)	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator ==(mapIterator const &rhs)	const	{ return ( this->_ptr == rhs._ptr); }
			bool operator < (mapIterator const &rhs)	const	{ return ( this->_ptr < rhs._ptr); }
			bool operator <=(mapIterator const &rhs)	const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator > (mapIterator const &rhs)	const	{ return ( this->_ptr > rhs._ptr); }
			bool operator >=(mapIterator const &rhs)	const	{ return ( this->_ptr >= rhs._ptr); }

			friend mapIterator operator+(int n, const mapIterator& it)	{ return ( it + n ); }
			friend mapIterator operator-(int n, const mapIterator& it)	{ return ( it - n ); }

			value_type &operator*(void)				{ return ( this->_ptr->pair); }
			value_type *operator->(void)	const	{ return ( &this->_ptr->pair); }
			pointer		getPtr() 			const 	{ return ( this->_ptr ); }
	};

	template <class Key, class T>
	class constMapIterator
	{
		public:
			typedef const ft::pair<Key, T>		value_type;
			typedef ft::pair<Key, T>&			reference;
			typedef BTNode<Key, T>*				pointer;
			typedef typename std::ptrdiff_t		difference_type;

		private:
			pointer							_ptr;

		public:
			constMapIterator( void ) : _ptr(NULL)				{}
			constMapIterator( const constMapIterator &rhs )		{ *this = rhs; }
			constMapIterator( const mapIterator<Key, T> &rhs )	{ *this = rhs; }
			constMapIterator( pointer ptr ) : _ptr( ptr )		{}
			~constMapIterator( void )							{}

			constMapIterator &operator=( const constMapIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			constMapIterator &operator=( const mapIterator<Key, T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constMapIterator &operator++( void )	//++it
			{
				pointer next;
				
				if (!this->_ptr->right)
				{
					next = this->_ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = this->_ptr->right;
					while (next->left)
						next = next->left;
				}
				this->_ptr = next;
				return ( *this );
			}
			constMapIterator operator++( int )		//it++
			{
				constMapIterator tmp(*this);
				operator++();
				return (tmp);
			}
			constMapIterator &operator--( void )
			{
				pointer next;

				if (!this->_ptr->left)
				{
					next = this->_ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = this->_ptr->left;
					while (next->right)
						next = next->right;
				}
				this->_ptr = next;
				return ( *this );
			}
			constMapIterator operator--( int )
			{
				constMapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			constMapIterator operator+(int n) const
			{
				constMapIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			constMapIterator operator-(int n) const
			{
				constMapIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			constMapIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			constMapIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(constMapIterator b)			{ return (_ptr - b._ptr); }			// a - b
			difference_type operator -(constMapIterator b)	const	{ return (_ptr - b._ptr); }
			difference_type operator +(constMapIterator b)			{ return (_ptr + b._ptr); } 		// a + b
			difference_type operator +(constMapIterator b)	const	{ return (_ptr + b._ptr); }

			friend constMapIterator operator+(int n, const constMapIterator& it)	{ return (it + n); }
			friend constMapIterator operator-(int n, const constMapIterator& it)	{ return (it - n); }

			bool operator !=( const constMapIterator &rhs )		const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const mapIterator<Key, T> &rhs )	const	{ return ( this->_ptr != rhs.getPtr() ); }
			bool operator ==(constMapIterator const& rhs)		const	{ return ( this->_ptr == rhs._ptr); }
			bool operator==( const mapIterator<Key, T> &rhs )	const	{ return ( this->_ptr == rhs.getPtr() ); }
			bool operator <(constMapIterator const& rhs)		const	{ return ( this->_ptr < rhs._ptr); }
			bool operator<( const mapIterator<Key, T> &rhs )	const	{ return ( this->_ptr < rhs.getPtr() ); }
			bool operator <=(constMapIterator const& rhs)		const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator<=(mapIterator<Key, T> const& rhs)		const	{ return ( this->_ptr <= rhs.getPtr()); }
			bool operator >(constMapIterator const& rhs)		const	{ return ( this->_ptr > rhs._ptr); }
			bool operator>(mapIterator<Key, T> const& rhs)		const	{ return ( this->_ptr > rhs.getPtr()); }
			bool operator >=(constMapIterator const& rhs)		const	{ return ( this->_ptr >= rhs._ptr); }
			bool operator>=(mapIterator<Key, T> const& rhs)		const	{ return ( this->_ptr >= rhs.getPtr()); }

			value_type &operator *( void )	const	{ return ( this->_ptr->pair ); }
			value_type *operator->( void ) 	const	{ return ( &this->_ptr->pair ); }
			pointer	getPtr()						const	{ return ( this->_ptr ); }
	};

	template <class Key, class T>
	bool operator==(const ft::mapIterator<Key, T> lhs, const ft::constMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template <class Key, class T>
	bool operator!=(const ft::mapIterator<Key, T> lhs, const ft::constMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template <class Key, class T>
	bool operator<(const ft::mapIterator<Key, T> lhs, const ft::constMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template <class Key, class T>
	bool operator>(const ft::mapIterator<Key, T> lhs, const ft::constMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template <class Key, class T>
	bool operator<=(const ft::mapIterator<Key, T> lhs, const ft::constMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

	template <class Key, class T>
	bool operator>=(const ft::mapIterator<Key, T> lhs, const ft::constMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}
}

#endif
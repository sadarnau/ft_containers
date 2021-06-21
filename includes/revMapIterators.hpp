/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revMapIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:23:37 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 16:19:28 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVMAPITERATORS_HPP
# define REVMAPITERATORS_HPP

# include "map.hpp"
# include <utility>
# include <iostream>

namespace ft
{
	template <class Key, class T, typename Iterator>
	class revMapIterator
	{
		public:
			typedef	Iterator							iteratorType;
			typedef typename Iterator::difference_type	difference_type;
			typedef typename Iterator::reference		reference;
			typedef typename Iterator::pointer			pointer;
			typedef typename Iterator::value_type		value_type;
	
		private:
			iteratorType	_it;

		public:
			revMapIterator( void ) : _it(NULL)					{}
			revMapIterator( const iteratorType rhs ) : _it(rhs) {};

			template <typename It>
			revMapIterator( const revMapIterator<Key, T, It> &rhs ) : _it(rhs.base()) {};

			// revMapIterator( const revMapIterator &rhs )			{ *this = rhs; }
			// revMapIterator( const mapIterator<Key, T> &rhs )	{ this->_ptr = rhs.getPtr(); }
			// revMapIterator( pointer ptr ) : _ptr(ptr)			{}

			~revMapIterator( void ) 							{}
			
			revMapIterator &operator=( const revMapIterator &rhs )
			{
				this->_it = rhs._it;
				return ( *this );
			}
			template <typename It>
			revMapIterator &operator=( const revMapIterator<Key, T, It> &rhs )
			{
				this->_it = rhs.base();
				return ( *this );
			}
			revMapIterator &operator--( void )	//--it
			{
				++_it;
				return ( *this );
			}
			revMapIterator operator--( int )		//it++
			{
				revMapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			revMapIterator &operator++( void )
			{
				--_it;
				return ( *this );
			}
			revMapIterator operator++( int )
			{
				revMapIterator tmp(*this);
				operator++();
				return (tmp);
			}
			revMapIterator operator+(int n) const
			{
				revMapIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			revMapIterator operator-(int n) const
			{
				revMapIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			revMapIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			revMapIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			template <class It>				
			difference_type operator -(revMapIterator<Key, T, It> b) { return (b.base().operator-(_it)); }	// a - b
			template <class It>
			difference_type operator +(revMapIterator<Key, T, It> b) { return (b.base().operator+(_it)); }	// a + b
		
			bool operator !=(revMapIterator const &rhs)	const	{ return ( this->_it != rhs.base()  ); }
			bool operator ==(revMapIterator const &rhs)	const	{ return ( this->_it == rhs.base() ); }
			bool operator < (revMapIterator const &rhs)	const	{ return ( this->_it < rhs.base() ); }
			bool operator <=(revMapIterator const &rhs)	const	{ return ( this->_it <= rhs.base() ); }
			bool operator > (revMapIterator const &rhs)	const	{ return ( this->_it > rhs.base() ); }
			bool operator >=(revMapIterator const &rhs)	const	{ return ( this->_it >= rhs.base() ); }

			friend revMapIterator operator+(int n, const revMapIterator& it)	{ return ( it + n ); }
			friend revMapIterator operator-(int n, const revMapIterator& it)	{ return ( it - n ); }

			value_type &operator *( void )
			{
				revMapIterator tmp(*this);
				--tmp._it;
			
				return ( tmp._it.getPtr()->pair );
			}
			value_type *operator-> ( void ) const
			{
				revMapIterator tmp(*this);
				--tmp._it;
			
				return ( &tmp._it.getPtr()->pair );
			}
			iteratorType base() const	{ return ( _it ); }
	};

	template <class Key, class T>
	bool operator==(const ft::revMapIterator<Key, T, ft::mapIterator<Key, T> > lhs, const ft::revMapIterator<Key, T, ft::constMapIterator<Key, T> > rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Key, class T>
	bool operator!=(const ft::revMapIterator<Key, T, ft::mapIterator<Key, T> > lhs, const ft::revMapIterator<Key, T, ft::constMapIterator<Key, T> > rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Key, class T>
	bool operator<(const ft::revMapIterator<Key, T, ft::mapIterator<Key, T> > lhs, const ft::revMapIterator<Key, T, ft::constMapIterator<Key, T> > rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Key, class T>
	bool operator>(const ft::revMapIterator<Key, T, ft::mapIterator<Key, T> > lhs, const ft::revMapIterator<Key, T, ft::constMapIterator<Key, T> > rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Key, class T>
	bool operator<=(const ft::revMapIterator<Key, T, ft::mapIterator<Key, T> > lhs, const ft::revMapIterator<Key, T, ft::constMapIterator<Key, T> > rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Key, class T>
	bool operator>=(const ft::revMapIterator<Key, T, ft::mapIterator<Key, T> > lhs, const ft::revMapIterator<Key, T, ft::constMapIterator<Key, T> > rhs)
	{
		return (lhs.base() <= rhs.base());
	}
}

#endif
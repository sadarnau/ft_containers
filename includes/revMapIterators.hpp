/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revMapIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:23:37 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/16 16:26:43 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVMAPITERATORS_HPP
# define REVMAPITERATORS_HPP

# include "map.hpp"
# include <utility>
# include <iostream>

namespace ft
{
	template <class Key, class T>
	class revMapIterator
	{
		public:
			typedef std::pair<Key, T> 		value_type;
			typedef std::pair<Key, T>& 		reference;
			typedef BTNode<Key, T>* 		pointer;
			typedef typename std::ptrdiff_t difference_type;
	
		private:
			pointer							_ptr;

		public:
			revMapIterator( void ) : _ptr(NULL)					{}
			revMapIterator( const revMapIterator &rhs )			{ *this = rhs; }
			revMapIterator( const mapIterator<Key, T> &rhs )	{ this->_ptr = rhs.getPtr(); }
			revMapIterator( pointer ptr ) : _ptr(ptr)			{}
			~revMapIterator( void ) 							{}
			
			revMapIterator &operator=( const revMapIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			revMapIterator &operator--( void )	//--it
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
			revMapIterator operator--( int )		//it++
			{
				revMapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			revMapIterator &operator++( void )
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

			difference_type operator -(revMapIterator b) { return ( this->_ptr - b._ptr ); }	// a - b
			difference_type operator +(revMapIterator b) { return ( this->_ptr + b._ptr ); }	// a + b
		
			bool operator !=(revMapIterator const &rhs)	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator ==(revMapIterator const &rhs)	const	{ return ( this->_ptr == rhs._ptr); }
			bool operator < (revMapIterator const &rhs)	const	{ return ( this->_ptr < rhs._ptr); }
			bool operator <=(revMapIterator const &rhs)	const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator > (revMapIterator const &rhs)	const	{ return ( this->_ptr > rhs._ptr); }
			bool operator >=(revMapIterator const &rhs)	const	{ return ( this->_ptr >= rhs._ptr); }

			friend revMapIterator operator+(int n, const revMapIterator& it)	{ return ( it + n ); }
			friend revMapIterator operator-(int n, const revMapIterator& it)	{ return ( it - n ); }

			value_type &operator*(void)				{ return ( this->_ptr->pair); }
			value_type *operator->(void)	const	{ return ( &this->_ptr->pair); }
			pointer		getPtr() 			const	{ return ( this->_ptr ); }
	};

	template <class Key, class T>
	class constRevMapIterator
	{
		public:
			typedef std::pair<Key, T> 		value_type;
			typedef std::pair<Key, T>& 		reference;
			typedef BTNode<Key, T>* 		pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			constRevMapIterator( void ) : _ptr(NULL)					{}
			constRevMapIterator( const constRevMapIterator &rhs )		{ *this = rhs; }
			constRevMapIterator( const constMapIterator<Key, T> &rhs )	{ *this = rhs; }
			constRevMapIterator( const revMapIterator<Key, T> &rhs )	{ *this = rhs; }
			constRevMapIterator( const mapIterator<Key, T> &rhs )		{ *this = rhs; }
			constRevMapIterator( pointer ptr ) : _ptr( ptr )			{}
			~constRevMapIterator( void )								{}

			constRevMapIterator &operator=( const constRevMapIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			constRevMapIterator &operator=( const mapIterator<Key, T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevMapIterator &operator=( const revMapIterator<Key, T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevMapIterator &operator=( const constMapIterator<Key, T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevMapIterator &operator--( void )	//++it
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
			constRevMapIterator operator--( int )		//it--
			{
				constRevMapIterator tmp(*this);
				operator--();
				return (tmp);
			}
			constRevMapIterator &operator++( void )
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
			constRevMapIterator operator++( int )
			{
				constRevMapIterator tmp(*this);
				operator++();
				return (tmp);
			}
			constRevMapIterator operator+(int n) const
			{
				constRevMapIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			constRevMapIterator operator-(int n) const
			{
				constRevMapIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			constRevMapIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			constRevMapIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(constRevMapIterator b)			{ return (_ptr - b._ptr); }			// a - b
			difference_type operator -(constRevMapIterator b)	const	{ return (_ptr - b._ptr); }
			difference_type operator -(revMapIterator<Key, T> b)		{ return (_ptr - b._ptr); }
			difference_type operator +(constRevMapIterator b)			{ return (_ptr + b._ptr); } 		// a + b
			difference_type operator +(constRevMapIterator b)	const	{ return (_ptr + b._ptr); }
			difference_type operator +(revMapIterator<Key, T> b)		{ return (_ptr + b._ptr); }

			friend constRevMapIterator operator+(int n, const constRevMapIterator& it)	{ return (it + n); }
			friend constRevMapIterator operator-(int n, const constRevMapIterator& it)	{ return (it - n); }

			bool operator !=( const constRevMapIterator &rhs )		const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const revMapIterator<Key, T> &rhs )	const	{ return ( this->_ptr != rhs.getPtr() ); }
			bool operator ==(constRevMapIterator const& rhs)		const	{ return ( this->_ptr == rhs._ptr); }
			bool operator==( const revMapIterator<Key, T> &rhs )	const	{ return ( this->_ptr == rhs.getPtr() ); }
			bool operator <(constRevMapIterator const& rhs)			const	{ return ( this->_ptr < rhs._ptr); }
			bool operator<( const revMapIterator<Key, T> &rhs )		const	{ return ( this->_ptr < rhs.getPtr() ); }
			bool operator <=(constRevMapIterator const& rhs)		const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator<=(revMapIterator<Key, T> const& rhs)		const	{ return ( this->_ptr <= rhs.getPtr()); }
			bool operator >(constRevMapIterator const& rhs)			const	{ return ( this->_ptr > rhs._ptr); }
			bool operator>(revMapIterator<Key, T> const& rhs)		const	{ return ( this->_ptr > rhs.getPtr()); }
			bool operator >=(constRevMapIterator const& rhs)		const	{ return ( this->_ptr >= rhs._ptr); }
			bool operator>=(revMapIterator<Key, T> const& rhs)		const	{ return ( this->_ptr >= rhs.getPtr()); }

			const value_type &operator *( void )	const	{ return ( this->_ptr->pair ); }
			const value_type *operator->( void ) 	const	{ return ( &this->_ptr->pair ); }
			pointer	getPtr()						const	{ return ( this->_ptr ); }
	};

	template <class Key, class T>
	bool operator==(const ft::revMapIterator<Key, T> lhs, const ft::constRevMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template <class Key, class T>
	bool operator!=(const ft::revMapIterator<Key, T> lhs, const ft::constRevMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template <class Key, class T>
	bool operator<(const ft::revMapIterator<Key, T> lhs, const ft::constRevMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template <class Key, class T>
	bool operator>(const ft::revMapIterator<Key, T> lhs, const ft::constRevMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template <class Key, class T>
	bool operator<=(const ft::revMapIterator<Key, T> lhs, const ft::constRevMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

	template <class Key, class T>
	bool operator>=(const ft::revMapIterator<Key, T> lhs, const ft::constRevMapIterator<Key, T> rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}
}

#endif
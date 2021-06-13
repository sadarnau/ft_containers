/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:23:41 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/13 16:30:09 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_HPP
# define MAPITERATORS_HPP

# include "map.hpp"
# include <utility>

namespace ft
{
	template <class Key, class T>
	struct BTNode
	{
		BTNode *left;
		BTNode *right;
		BTNode *parent;
		std::pair<Key, T> pair;
		// bool end;
	};

	template <class Key, class T>
	class mapIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef BTNode<Key, T>*				pointer;
			typedef BTNode<Key, T> const *		const_pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			mapIterator( void ) : _ptr(NULL)		{}
			mapIterator( const mapIterator &rhs )	{ *this = rhs; }
			mapIterator( pointer ptr ) : _ptr(ptr)	{}
			~mapIterator( void ) 					{}
			
			pointer node(void) const
			{
				return (_ptr);
			}
			
			mapIterator &operator=( const mapIterator &rhs )
			{
				// this->_ptr = rhs._ptr;
				return ( *this );
			}

			mapIterator &operator++( void )	//++it
			{
				// this->_ptr = this->_ptr->next;
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
				// this->_ptr = this->_ptr->prev;
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

			reference	operator*( void )	{ return ( this->_ptr->data ); }
			value_type	*operator->()		{ return ( &this->_ptr->data ); }
			pointer		getPtr() const	 	{ return ( this->_ptr ); }
	};

	// template <typename T>
	// class constListIterator
	// {
	// 	public:
	// 		typedef T						value_type;
	// 		typedef value_type&				reference;
	// 		typedef const value_type&		const_reference;
	// 		typedef node<T>*				pointer;
	// 		typedef node<T> const *			const_pointer;
	// 		typedef typename std::ptrdiff_t difference_type;

	// 	private:
	// 		pointer							_ptr;

	// 	public:
	// 		constListIterator( void ) : _ptr(NULL)				{}
	// 		constListIterator( const constListIterator &rhs )	{ *this = rhs; }
	// 		constListIterator( const listIterator<T> &rhs )		{ *this = rhs; }
	// 		constListIterator( pointer ptr ) : _ptr( ptr )		{}
	// 		~constListIterator( void )							{}

	// 		constListIterator &operator=( const constListIterator &rhs )
	// 		{
	// 			this->_ptr = rhs._ptr;
	// 			return ( *this );
	// 		}
	// 		constListIterator &operator=( const listIterator<T> &rhs )
	// 		{
	// 			this->_ptr = rhs.getPtr();
	// 			return ( *this );
	// 		}
	// 		constListIterator &operator++( void )	//++it
	// 		{
	// 			this->_ptr = this->_ptr->next;
	// 			return ( *this );
	// 		}
	// 		constListIterator operator++( int )		//it++
	// 		{
	// 			constListIterator tmp(*this);
	// 			operator++();
	// 			return (tmp);
	// 		}
	// 		constListIterator &operator--( void )
	// 		{
	// 			this->_ptr = this->_ptr->prev;
	// 			return ( *this );
	// 		}
	// 		constListIterator operator--( int )
	// 		{
	// 			constListIterator tmp(*this);
	// 			operator--();
	// 			return (tmp);
	// 		}
	// 		constListIterator operator+(int n) const
	// 		{
	// 			constListIterator tmp(*this);
	// 			while (n--)
	// 				tmp++;
	// 			return (tmp);
	// 		}
	// 		constListIterator operator-(int n) const
	// 		{
	// 			constListIterator tmp(*this);
	// 			while (n--)
	// 				tmp--;
	// 			return (tmp);
	// 		}
	// 		constListIterator &operator+=(int n)
	// 		{
	// 			while (n > 0)
	// 			{
	// 				operator++();
	// 				n--;
	// 			}
	// 			return (*this);
	// 		}
	// 		constListIterator &operator-=(int n)
	// 		{
	// 			while (n > 0)
	// 			{
	// 				operator--();
	// 				n--;
	// 			}
	// 			return (*this);
	// 		}

	// 		difference_type operator -(constListIterator b)			{ return (_ptr - b._ptr); }			// a - b
	// 		difference_type operator -(constListIterator b)	const	{ return (_ptr - b._ptr); }
	// 		difference_type operator +(constListIterator b)			{ return (_ptr + b._ptr); } 		// a + b
	// 		difference_type operator +(constListIterator b)	const	{ return (_ptr + b._ptr); }

	// 		friend constListIterator operator+(int n, const constListIterator& it)	{ return (it + n); }
	// 		friend constListIterator operator-(int n, const constListIterator& it)	{ return (it - n); }

	// 		bool operator !=( const constListIterator &rhs )	const	{ return ( this->_ptr != rhs._ptr ); }
	// 		bool operator!=( const listIterator<T> &rhs )		const	{ return ( this->_ptr != rhs.getPtr() ); }
	// 		bool operator ==(constListIterator const& rhs)		const	{ return ( this->_ptr == rhs._ptr); }
	// 		bool operator==( const listIterator<T> &rhs )		const	{ return ( this->_ptr == rhs.getPtr() ); }
	// 		bool operator <(constListIterator const& rhs)		const	{ return ( this->_ptr < rhs._ptr); }
	// 		bool operator<( const listIterator<T> &rhs )		const	{ return ( this->_ptr < rhs.getPtr() ); }
	// 		bool operator <=(constListIterator const& rhs)		const	{ return ( this->_ptr <= rhs._ptr); }
	// 		bool operator<=(listIterator<T> const& rhs)			const	{ return ( this->_ptr <= rhs.getPtr()); }
	// 		bool operator >(constListIterator const& rhs)		const	{ return ( this->_ptr > rhs._ptr); }
	// 		bool operator>(listIterator<T> const& rhs)			const	{ return ( this->_ptr > rhs.getPtr()); }
	// 		bool operator >=(constListIterator const& rhs)		const	{ return ( this->_ptr >= rhs._ptr); }
	// 		bool operator>=(listIterator<T> const& rhs)			const	{ return ( this->_ptr >= rhs.getPtr()); }

	// 		const_reference operator *( void )	const	{ return ( this->_ptr->data ); }
	// 		const value_type * operator->() 			{ return ( &this->_ptr->data ); }
	// 		pointer	getPtr()					const	{ return ( this->_ptr ); }
	// };

	// template<typename T>
	// bool operator==(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	// {
	// 	return (lhs.getPtr() == rhs.getPtr());
	// }

	// template<typename T>
	// bool operator!=(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	// {
	// 	return (lhs.getPtr() != rhs.getPtr());
	// }

	// template<typename T>
	// bool operator<(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	// {
	// 	return (lhs.getPtr() < rhs.getPtr());
	// }

	// template<typename T>
	// bool operator>(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	// {
	// 	return (lhs.getPtr() > rhs.getPtr());
	// }

	// template<typename T>
	// bool operator<=(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	// {
	// 	return (lhs.getPtr() <= rhs.getPtr());
	// }

	// template<typename T>
	// bool operator>=(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	// {
	// 	return (lhs.getPtr() >= rhs.getPtr());
	// }
}




#endif
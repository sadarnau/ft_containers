/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:10 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 17:37:57 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATORS_HPP
# define LISTITERATORS_HPP

# include "list.hpp"

namespace ft
{
	template <typename T>
	class listIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t difference_type;

			pointer							_ptr;

			listIterator( void ) : _ptr(NULL)		{}
			listIterator( const listIterator &rhs )	{ *this = rhs; }
			listIterator( pointer ptr ) : _ptr(ptr)	{}
			~listIterator( void ) 					{}
			
			pointer node(void) const
			{
				return (_ptr);
			}
			
			listIterator &operator=( const listIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}

			listIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			}
			listIterator operator++( int )		//it++
			{
				listIterator tmp(*this);
				operator++();
				return (tmp);
			}
			listIterator &operator--( void )
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			}
			listIterator operator--( int )
			{
				listIterator tmp(*this);
				operator--();
				return (tmp);
			}
			listIterator operator+(int n) const
			{
				listIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			listIterator operator-(int n) const
			{
				listIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			listIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			listIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(listIterator b) { return ( this->_ptr - b._ptr ); }	// a - b
			difference_type operator +(listIterator b) { return ( this->_ptr + b._ptr ); }	// a + b
		
			bool operator !=(listIterator const &rhs)	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator ==(listIterator const &rhs)	const	{ return ( this->_ptr == rhs._ptr); }
			bool operator < (listIterator const &rhs)	const	{ return ( this->_ptr < rhs._ptr); }
			bool operator <=(listIterator const &rhs)	const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator > (listIterator const &rhs)	const	{ return ( this->_ptr > rhs._ptr); }
			bool operator >=(listIterator const &rhs)	const	{ return ( this->_ptr >= rhs._ptr); }

			friend listIterator operator+(int n, const listIterator& it)	{ return ( it + n ); }
			friend listIterator operator-(int n, const listIterator& it)	{ return ( it - n ); }

			reference operator*( void )	{ return (  this->_ptr->data ); }
			value_type * operator->()	{ return ( &this->_ptr->data ); }
			pointer	getPtr() const	 	{ return ( this->_ptr ); }
	};

	template <typename T>
	class constListIterator
	{
		public:
			typedef const T						value_type;
			// typedef value_type&				reference;
			typedef const value_type&		reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			constListIterator( void ) : _ptr(NULL)				{}
			constListIterator( const constListIterator &rhs )	{ *this = rhs; }
			constListIterator( const listIterator<T> &rhs )		{ *this = rhs; }
			constListIterator( pointer ptr ) : _ptr( ptr )		{}
			~constListIterator( void )							{}

			constListIterator &operator=( const constListIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			constListIterator &operator=( const listIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constListIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			}
			constListIterator operator++( int )		//it++
			{
				constListIterator tmp(*this);
				operator++();
				return (tmp);
			}
			constListIterator &operator--( void )
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			}
			constListIterator operator--( int )
			{
				constListIterator tmp(*this);
				operator--();
				return (tmp);
			}
			constListIterator operator+(int n) const
			{
				constListIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			constListIterator operator-(int n) const
			{
				constListIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			constListIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			constListIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(constListIterator b)			{ return (_ptr - b._ptr); }			// a - b
			difference_type operator -(constListIterator b)	const	{ return (_ptr - b._ptr); }
			difference_type operator +(constListIterator b)			{ return (_ptr + b._ptr); } 		// a + b
			difference_type operator +(constListIterator b)	const	{ return (_ptr + b._ptr); }

			friend constListIterator operator+(int n, const constListIterator& it)	{ return (it + n); }
			friend constListIterator operator-(int n, const constListIterator& it)	{ return (it - n); }

			bool operator !=( const constListIterator &rhs )	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const listIterator<T> &rhs )		const	{ return ( this->_ptr != rhs.getPtr() ); }
			bool operator ==(constListIterator const& rhs)		const	{ return ( this->_ptr == rhs._ptr); }
			bool operator==( const listIterator<T> &rhs )		const	{ return ( this->_ptr == rhs.getPtr() ); }
			bool operator <(constListIterator const& rhs)		const	{ return ( this->_ptr < rhs._ptr); }
			bool operator<( const listIterator<T> &rhs )		const	{ return ( this->_ptr < rhs.getPtr() ); }
			bool operator <=(constListIterator const& rhs)		const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator<=(listIterator<T> const& rhs)			const	{ return ( this->_ptr <= rhs.getPtr()); }
			bool operator >(constListIterator const& rhs)		const	{ return ( this->_ptr > rhs._ptr); }
			bool operator>(listIterator<T> const& rhs)			const	{ return ( this->_ptr > rhs.getPtr()); }
			bool operator >=(constListIterator const& rhs)		const	{ return ( this->_ptr >= rhs._ptr); }
			bool operator>=(listIterator<T> const& rhs)			const	{ return ( this->_ptr >= rhs.getPtr()); }

			reference operator *( void )	const	{ return ( this->_ptr->data ); }
			value_type * operator->() 			{ return ( &this->_ptr->data ); }
			pointer	getPtr()					const	{ return ( this->_ptr ); }
	};

	template<typename T>
	bool operator==(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template<typename T>
	bool operator!=(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template<typename T>
	bool operator<(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template<typename T>
	bool operator>(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template<typename T>
	bool operator<=(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

	template<typename T>
	bool operator>=(const ft::listIterator<T> lhs, const ft::constListIterator<T> rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}
}

#endif

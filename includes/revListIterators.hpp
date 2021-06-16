/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revListIterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:43:57 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/16 16:33:24 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVLISTITERATORS_HPP
# define REVLISTITERATORS_HPP

# include "list.hpp"
# include "listIterators.hpp"

namespace ft
{
	template <typename T>
	class revListIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			revListIterator( void ) : _ptr(NULL) 			{}
			revListIterator( const revListIterator &rhs )	{ *this = rhs; }
			revListIterator( const listIterator<T> &rhs )	{ *this = rhs; }
			revListIterator( pointer ptr ) : _ptr( ptr )	{}
			~revListIterator( void ) 						{}

			revListIterator &operator=( const revListIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			revListIterator &operator=( const listIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			revListIterator &operator++( void )		//++it
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			}
			revListIterator operator++( int )		//it++
			{
				revListIterator tmp(*this);
				operator++();
				return (tmp);
			}
			revListIterator &operator--( void )
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			}
			revListIterator operator--( int )
			{
				revListIterator tmp(*this);
				operator--();
				return (tmp);
			}
			revListIterator operator+(int n) const
			{
				revListIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			revListIterator operator-(int n) const
			{
				revListIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			revListIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			revListIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(revListIterator b) { return (this->_ptr - b._ptr); }	// a - b
			difference_type operator +(revListIterator b) { return (this->_ptr + b._ptr); }	// a + b
		
			bool operator !=(revListIterator const &rhs)	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator ==(revListIterator const &rhs)	const	{ return ( this->_ptr == rhs._ptr); }
			bool operator < (revListIterator const &rhs)	const	{ return ( this->_ptr > rhs._ptr); }
			bool operator <=(revListIterator const &rhs)	const	{ return ( this->_ptr >= rhs._ptr); }
			bool operator > (revListIterator const &rhs)	const	{ return ( this->_ptr < rhs._ptr); }
			bool operator >=(revListIterator const &rhs)	const	{ return ( this->_ptr <= rhs._ptr); }

			friend revListIterator operator+(int n, const revListIterator& it)	{ return (it + n); }
			friend revListIterator operator-(int n, const revListIterator& it)	{ return (it - n); }

			reference operator*( void )	{ return (  this->_ptr->data ); }
			value_type * operator->()	{ return ( &this->_ptr->data ); }
			reference operator[](int n)	{ return ( *(*this + n) ); }
			pointer	getPtr() const 		{ return( this->_ptr ); }
	};

	template <typename T>
	class constRevListIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			constRevListIterator( void ) : _ptr(NULL) 				{}
			constRevListIterator( const constRevListIterator &rhs )	{ *this = rhs; }
			constRevListIterator( const constListIterator<T> &rhs )	{ *this = rhs; }
			constRevListIterator( const revListIterator<T> &rhs )	{ *this = rhs; }
			constRevListIterator( const listIterator<T> &rhs )		{ *this = rhs; }
			constRevListIterator( pointer ptr ) : _ptr( ptr ) 		{}
			~constRevListIterator( void ) 							{}

			constRevListIterator &operator=( const constRevListIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			constRevListIterator &operator=( const revListIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevListIterator &operator=( const constListIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevListIterator &operator=( const listIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevListIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			}
			constRevListIterator operator++( int )		//it++
			{
				constRevListIterator tmp(*this);
				operator++();
				return (tmp);
			}
			constRevListIterator &operator--( void )
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			}
			constRevListIterator operator--( int )
			{
				constRevListIterator tmp(*this);
				operator--();
				return (tmp);
			}
			constRevListIterator operator+(int n) const
			{
				constRevListIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			constRevListIterator operator-(int n) const
			{
				constRevListIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			constRevListIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			constRevListIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(constRevListIterator b)			{ return (_ptr - b._ptr); } 	// a - b
			difference_type operator -(constRevListIterator b) const	{ return (_ptr - b._ptr); }
			difference_type operator -(revListIterator<T> b) 			{ return (b.getPtr() - _ptr); }
			difference_type operator +(constRevListIterator b)			{ return (_ptr + b._ptr); } 	// a + b
			difference_type operator +(constRevListIterator b) const	{ return (_ptr + b._ptr); }

			friend constRevListIterator operator+(int n, const constRevListIterator& it)	{ return (it + n); }
			friend constRevListIterator operator-(int n, const constRevListIterator& it)	{ return (it - n); }

			bool operator !=( const constRevListIterator &rhs )	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const revListIterator<T> &rhs )	const	{ return ( this->_ptr != rhs.getPtr() ); }
			bool operator ==(constRevListIterator const& rhs)	const	{ return ( this->_ptr == rhs._ptr); }
			bool operator==( const revListIterator<T> &rhs )	const	{ return ( this->_ptr == rhs.getPtr() ); }
			bool operator <(constRevListIterator const& rhs)	const	{ return ( this->_ptr > rhs._ptr); }
			bool operator<( const revListIterator<T> &rhs )		const	{ return ( this->_ptr > rhs.getPtr() ); }
			bool operator <=(constRevListIterator const& rhs)	const	{ return ( this->_ptr >= rhs._ptr); }
			bool operator<=(revListIterator<T> const& rhs)		const	{ return ( this->_ptr >= rhs.getPtr()); }
			bool operator >(constRevListIterator const& rhs)	const	{ return ( this->_ptr < rhs._ptr); }
			bool operator>(revListIterator<T> const& rhs)		const	{ return ( this->_ptr < rhs.getPtr()); }
			bool operator >=(constRevListIterator const& rhs)	const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator>=(revListIterator<T> const& rhs)		const	{ return ( this->_ptr <= rhs.getPtr()); }

			const_reference operator *( void )	{ return ( this->_ptr->data ); }
			const value_type * operator->()		{ return ( &this->_ptr->data ); }
			pointer	getPtr()	const			{ return( this->_ptr ); }
	};

	template<typename T>
	bool operator==(const ft::revListIterator<T> lhs, const ft::constRevListIterator<T> rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template<typename T>
	bool operator!=(const ft::revListIterator<T> lhs, const ft::constRevListIterator<T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template<typename T>
	bool operator<(const ft::revListIterator<T> lhs, const ft::constRevListIterator<T> rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template<typename T>
	bool operator>(const ft::revListIterator<T> lhs, const ft::constRevListIterator<T> rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template<typename T>
	bool operator<=(const ft::revListIterator<T> lhs, const ft::constRevListIterator<T> rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}

	template<typename T>
	bool operator>=(const ft::revListIterator<T> lhs, const ft::constRevListIterator<T> rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}
}

#endif
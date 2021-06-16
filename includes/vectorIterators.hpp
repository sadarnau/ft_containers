/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:10 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/16 16:31:30 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORS_HPP
# define VECTORITERATORS_HPP

# include "vector.hpp"

namespace ft
{
	template <typename T>
	class vectorIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef T*						pointer;
			typedef T const *				const_pointer;
			typedef typename std::ptrdiff_t difference_type;
		
		private:
			pointer							_ptr;

		public:
			vectorIterator( void ) : _ptr(NULL) 		{}
			vectorIterator( const vectorIterator &rhs ) { *this = rhs; }
			vectorIterator( pointer ptr ) : _ptr( ptr ) {}
			~vectorIterator( void )						{}

			vectorIterator &operator=( const vectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			vectorIterator &operator++( void )	//++it
			{
				this->_ptr++;
				return ( *this );
			}
			vectorIterator operator++( int )	//it++
			{
				vectorIterator tmp(*this);
				this->operator++();
				return (tmp);
			}
			vectorIterator &operator--( void )
			{
				this->_ptr--;
				return ( *this );
			}
			vectorIterator operator--( int )
			{
				vectorIterator tmp(*this);
				operator--();
				return (tmp);
			}
			vectorIterator operator+(int n) const
			{
				vectorIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			vectorIterator operator-(int n) const
			{
				vectorIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			vectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			vectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}
	
			difference_type operator -(vectorIterator b) { return (this->_ptr - b._ptr); }	// a - b
			difference_type operator +(vectorIterator b) { return (this->_ptr + b._ptr); }	// a + b
			
			bool operator!=( const vectorIterator &rhs )	const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator ==(vectorIterator const& rhs)		const	{ return ( this->_ptr == rhs._ptr); }
			bool operator <(vectorIterator const& rhs)		const	{ return ( this->_ptr < rhs._ptr); }
			bool operator <=(vectorIterator const& rhs)		const	{ return ( this->_ptr <= rhs._ptr); }
			bool operator >(vectorIterator const& rhs)		const	{ return ( this->_ptr > rhs._ptr); }
			bool operator >=(vectorIterator const& rhs)		const	{ return ( this->_ptr >= rhs._ptr); }

			friend vectorIterator operator+(int n, const vectorIterator& it)	{ return (it + n); }
			friend vectorIterator operator-(int n, const vectorIterator& it)	{ return (it - n); }

			reference operator*( void )	{ return ( *this->_ptr ); }
			pointer operator->() 		{ return (this->_ptr); }
			reference operator[](int n)	{ return (*(*this + n)); }
			pointer	getPtr() 	const 	{ return( this->_ptr ); }
	};

	template <typename T>
	class constVectorIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef T*						pointer;
			typedef T const *				const_pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			constVectorIterator( void ) : _ptr(NULL) 				{}
			constVectorIterator( const constVectorIterator &rhs )	{ *this = rhs; }
			constVectorIterator( const vectorIterator<T> &rhs )		{ *this = rhs; }
			constVectorIterator( pointer ptr ) : _ptr( ptr )		{}
			~constVectorIterator( void ) {}

			constVectorIterator &operator=( const constVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			constVectorIterator &operator=( const vectorIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constVectorIterator &operator++( void )		//++it
			{
				this->_ptr++;
				return ( *this );
			}
			constVectorIterator operator++( int )		//it++
			{
				constVectorIterator tmp(*this);
				operator++();
				return (tmp);
			}
			constVectorIterator &operator--( void )
			{
				this->_ptr--;
				return ( *this );
			}
			constVectorIterator operator--( int )
			{
				constVectorIterator tmp(*this);
				operator--();
				return (tmp);
			}
			constVectorIterator operator+(int n) const
			{
				constVectorIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			constVectorIterator operator-(int n) const
			{
				constVectorIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			constVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			constVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(constVectorIterator b)		{ return (_ptr - b._ptr); }			// a - b
			difference_type operator -(constVectorIterator b) const { return (_ptr - b._ptr); }
			difference_type operator +(constVectorIterator b)		{ return (_ptr + b._ptr); } 			// a + b
			difference_type operator +(constVectorIterator b) const { return (_ptr + b._ptr); }

			friend constVectorIterator operator+(int n, const constVectorIterator& it)	{ return (it + n); }
			friend constVectorIterator operator-(int n, const constVectorIterator& it)	{ return (it - n); }

			bool operator !=( const constVectorIterator &rhs )	const { return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const vectorIterator<T> &rhs )		const { return ( this->_ptr != rhs.getPtr() ); }
			bool operator ==(constVectorIterator const& rhs)	const { return ( this->_ptr == rhs._ptr); }
			bool operator==( const vectorIterator<T> &rhs )		const { return ( this->_ptr == rhs.getPtr() ); }
			bool operator <(constVectorIterator const& rhs)		const { return ( this->_ptr < rhs._ptr); }
			bool operator<( const vectorIterator<T> &rhs )		const { return ( this->_ptr < rhs.getPtr() ); }
			bool operator <=(constVectorIterator const& rhs)	const { return ( this->_ptr <= rhs._ptr); }
			bool operator<=(vectorIterator<T> const& rhs)		const { return ( this->_ptr <= rhs.getPtr()); }
			bool operator >(constVectorIterator const& rhs)		const { return ( this->_ptr > rhs._ptr); }
			bool operator>(vectorIterator<T> const& rhs)		const { return ( this->_ptr > rhs.getPtr()); }
			bool operator >=(constVectorIterator const& rhs)	const { return ( this->_ptr >= rhs._ptr); }
			bool operator>=(vectorIterator<T> const& rhs)		const { return ( this->_ptr >= rhs.getPtr()); }

			const_reference operator *( void )	{ return ( *this->_ptr ); }
			const_pointer operator->()	const	{ return (this->_ptr); }
			pointer	getPtr()			const	{ return( this->_ptr ); }
	};

	template<typename T>
	bool operator==(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template<typename T>
	bool operator!=(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template<typename T>
	bool operator<(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template<typename T>
	bool operator>(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template<typename T>
	bool operator<=(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

	template<typename T>
	bool operator>=(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}
}

#endif

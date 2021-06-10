/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revVectorIterators.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:43:14 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/10 14:40:34 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVVECTORITERATORS_HPP
# define REVVECTORITERATORS_HPP

# include "vector.hpp"
# include "vectorIterators.hpp"

namespace ft
{
	template <typename T>
	class revVectorIterator
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
			revVectorIterator( void ) : _ptr(NULL) {}
			revVectorIterator( const revVectorIterator &rhs ) { *this = rhs; }
			revVectorIterator( const vectorIterator<T> &rhs ) { *this = rhs; }
			revVectorIterator( pointer ptr ) : _ptr( ptr ) {}
			~revVectorIterator( void ) {}

			revVectorIterator &operator=( const revVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			revVectorIterator &operator=( const vectorIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			revVectorIterator &operator++( void )	//++it
			{
				this->_ptr--;
				return ( *this );
			}
			revVectorIterator operator++( int )		//it++
			{
				revVectorIterator tmp(*this);
				this->operator++();
				return (tmp);
			}
			revVectorIterator &operator--( void )
			{
				this->_ptr++;
				return ( *this );
			}
			revVectorIterator operator--( int )
			{
				revVectorIterator tmp(*this);
				operator--();
				return (tmp);
			}
			revVectorIterator operator+(int n) const
			{
				revVectorIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			revVectorIterator operator-(int n) const
			{
				revVectorIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			revVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			revVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(revVectorIterator b) { return (this->_ptr - b._ptr); }	// a - b
			difference_type operator +(revVectorIterator b) { return (this->_ptr + b._ptr); }	// a + b
			
			bool operator !=(revVectorIterator const &rhs )		const	{ return ( this->_ptr != rhs._ptr ); }
			bool operator ==(revVectorIterator const &rhs) 		const	{ return ( this->_ptr == rhs._ptr); }
			bool operator <(revVectorIterator const &rhs) 		const	{ return ( this->_ptr > rhs._ptr); }
			bool operator <=(revVectorIterator const &rhs)		const	{ return ( this->_ptr >= rhs._ptr); }
			bool operator >(revVectorIterator const &rhs)		const	{ return ( this->_ptr < rhs._ptr); }
			bool operator >=(revVectorIterator const &rhs)		const	{ return ( this->_ptr <= rhs._ptr); }

			friend revVectorIterator operator+(int n, const revVectorIterator& it)	{ return (it + n); }
			friend revVectorIterator operator-(int n, const revVectorIterator& it)	{ return (it - n); }

			reference operator*( void )	{ return ( *this->_ptr ); }
			pointer operator->() 		{ return (this->_ptr); }
			reference operator[](int n)	{ return (*(*this + n)); }
			pointer	getPtr() const 		{ return( this->_ptr ); }
	};

	template <typename T>
	class constRevVectorIterator
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
			constRevVectorIterator( void ) : _ptr(NULL) {}
			constRevVectorIterator( const constRevVectorIterator &rhs )	{ *this = rhs; }
			constRevVectorIterator( const revVectorIterator<T> &rhs )	{ *this = rhs; }
			constRevVectorIterator( const vectorIterator<T> &rhs )		{ *this = rhs; }
			constRevVectorIterator( const constVectorIterator<T> &rhs )	{ *this = rhs; }
			constRevVectorIterator( pointer ptr ) : _ptr( ptr ) {}
			~constRevVectorIterator( void ) {}

			constRevVectorIterator &operator=( const constRevVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			}
			constRevVectorIterator &operator=( const revVectorIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevVectorIterator &operator=( const constVectorIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevVectorIterator &operator=( const vectorIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			}
			constRevVectorIterator &operator++( void )	//++it
			{
				this->_ptr--;
				return ( *this );
			}
			constRevVectorIterator operator++( int )	//it++
			{
				constRevVectorIterator tmp(*this);
				operator++();
				return (tmp);
			}
			constRevVectorIterator &operator--( void )
			{
				this->_ptr++;
				return ( *this );
			}
			constRevVectorIterator operator--( int )
			{
				constRevVectorIterator tmp(*this);
				operator--();
				return (tmp);
			}
			constRevVectorIterator operator+(int n) const
			{
				constRevVectorIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			}
			constRevVectorIterator operator-(int n) const
			{
				constRevVectorIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			}
			constRevVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			constRevVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			}

			difference_type operator -(constRevVectorIterator b)		{ return (_ptr - b._ptr); } 	// a - b
			difference_type operator -(constRevVectorIterator b) const	{ return (_ptr - b._ptr); }
			difference_type operator -(revVectorIterator<T> b) 			{ return (b.getPtr() - _ptr); }
			difference_type operator +(constRevVectorIterator b)		{ return (_ptr + b._ptr); } 	// a + b
			difference_type operator +(constRevVectorIterator b) const	{ return (_ptr + b._ptr); }

			friend constRevVectorIterator operator+(int n, const constRevVectorIterator& it)	{ return (it + n); }
			friend constRevVectorIterator operator-(int n, const constRevVectorIterator& it)	{ return (it - n); }

			bool operator !=( const constRevVectorIterator &rhs )	const { return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const revVectorIterator<T> &rhs )		const { return ( this->_ptr != rhs.getPtr() ); }
			bool operator ==(constRevVectorIterator const& rhs)		const { return ( this->_ptr == rhs._ptr); }
			bool operator==( const revVectorIterator<T> &rhs )		const { return ( this->_ptr == rhs.getPtr() ); }
			bool operator <(constRevVectorIterator const& rhs)		const { return ( this->_ptr > rhs._ptr); }
			bool operator<( const revVectorIterator<T> &rhs )		const { return ( this->_ptr > rhs.getPtr() ); }
			bool operator <=(constRevVectorIterator const& rhs)		const { return ( this->_ptr >= rhs._ptr); }
			bool operator<=(revVectorIterator<T> const& rhs)		const { return ( this->_ptr >= rhs.getPtr()); }
			bool operator >(constRevVectorIterator const& rhs)		const { return ( this->_ptr < rhs._ptr); }
			bool operator>(revVectorIterator<T> const& rhs)			const { return ( this->_ptr < rhs.getPtr()); }
			bool operator >=(constRevVectorIterator const& rhs)		const { return ( this->_ptr <= rhs._ptr); }
			bool operator>=(revVectorIterator<T> const& rhs)		const { return ( this->_ptr <= rhs.getPtr()); }
						
			const_reference operator *( void ) 	{ return ( *this->_ptr ); }
			const_pointer operator->()	const	{ return (this->_ptr); }
			pointer	getPtr() 			const 	{ return( this->_ptr ); }
	};

	template<typename T>
	bool operator==(const ft::revVectorIterator<T> lhs,
			const ft::constRevVectorIterator<T> rhs)
	{
		return (lhs.getPtr() == rhs.getPtr());
	}

	template<typename T>
	bool operator!=(const ft::revVectorIterator<T> lhs,
			const ft::constRevVectorIterator<T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	template<typename T>
	bool operator<(const ft::revVectorIterator<T> lhs,
			const ft::constRevVectorIterator<T> rhs)
	{
		return (lhs.getPtr() > rhs.getPtr());
	}

	template<typename T>
	bool operator>(const ft::revVectorIterator<T> lhs,
			const ft::constRevVectorIterator<T> rhs)
	{
		return (lhs.getPtr() < rhs.getPtr());
	}

	template<typename T>
	bool operator<=(const ft::revVectorIterator<T> lhs,
			const ft::constRevVectorIterator<T> rhs)
	{
		return (lhs.getPtr() >= rhs.getPtr());
	}

	template<typename T>
	bool operator>=(const ft::revVectorIterator<T> lhs,
			const ft::constRevVectorIterator<T> rhs)
	{
		return (lhs.getPtr() <= rhs.getPtr());
	}

}
#endif
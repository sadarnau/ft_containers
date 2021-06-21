/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revVectorIterators.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:43:14 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 17:09:45 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVVECTORITERATORS_HPP
# define REVVECTORITERATORS_HPP

# include "vector.hpp"
# include "vectorIterators.hpp"

namespace ft
{
	template <typename T, typename Iterator>
	class revVectorIterator
	{
		public:
			typedef	Iterator							iteratorType;
			typedef typename Iterator::difference_type	difference_type;
			typedef typename Iterator::reference		reference;
			typedef typename Iterator::pointer			pointer;
			typedef typename Iterator::value_type		value_type;
		
		private:
			iteratorType								_it;

		public:
			revVectorIterator( void ) : _it(NULL) 			{}
			revVectorIterator( const iteratorType rhs ) : _it(rhs) {};

			template <typename It>
			revVectorIterator( const revVectorIterator<T, It> &rhs ) : _it(rhs.base()) {};

			~revVectorIterator( void )	{}


			revVectorIterator &operator=( const revVectorIterator &rhs )
			{
				this->_it = rhs._it;
				return ( *this );
			}
			template <typename It>
			revVectorIterator &operator=( const revVectorIterator<T, It> &rhs )
			{
				this->_it = rhs.base();
				return ( *this );
			}
			revVectorIterator &operator++( void )	//++it
			{
				--_it;
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
				++_it;
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

			template <class It>
			difference_type operator +(revVectorIterator<T, It> b) 							{ return ( this->_it + b.base() ); }	// a + b
			difference_type operator -(revVectorIterator<T, ft::constVectorIterator<T> > b) { return ( b.base() - this->_it ); }	// a - b


			bool operator !=(revVectorIterator const &rhs )		const	{ return ( this->_it != rhs.base()  ); }
			bool operator ==(revVectorIterator const &rhs) 		const	{ return ( this->_it == rhs.base() ); }
			bool operator <(revVectorIterator const &rhs) 		const	{ return ( this->_it > rhs.base() ); }
			bool operator <=(revVectorIterator const &rhs)		const	{ return ( this->_it >= rhs.base() ); }
			bool operator >(revVectorIterator const &rhs)		const	{ return ( this->_it < rhs.base() ); }
			bool operator >=(revVectorIterator const &rhs)		const	{ return ( this->_it <= rhs.base() ); }

			friend revVectorIterator operator+(int n, const revVectorIterator& it)	{ return (it + n); }
			friend revVectorIterator operator-(int n, const revVectorIterator& it)	{ return (it - n); }

			reference operator*( void )
			{
				revVectorIterator tmp(*this);
				--tmp._it;
			
				return ( *tmp._it.getPtr() );
			}
			pointer operator->( void )
			{
				revVectorIterator tmp(*this);
				--tmp._it;
			
				return ( tmp._it.getPtr() );
			}
			reference operator[](int n)	{ return (*(*this + n)); }
			iteratorType base() const	{ return ( _it ); }
	};

	template<typename T>
	bool operator==(const ft::revVectorIterator<T, ft::vectorIterator<T> > lhs, const ft::revVectorIterator<T, ft::constVectorIterator<T> > rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T>
	bool operator!=(const ft::revVectorIterator<T, ft::vectorIterator<T> > lhs, const ft::revVectorIterator<T, ft::constVectorIterator<T> > rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T>
	bool operator<(const ft::revVectorIterator<T, ft::vectorIterator<T> > lhs, const ft::revVectorIterator<T, ft::constVectorIterator<T> > rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T>
	bool operator>(const ft::revVectorIterator<T, ft::vectorIterator<T> > lhs, const ft::revVectorIterator<T, ft::constVectorIterator<T> > rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T>
	bool operator<=(const ft::revVectorIterator<T, ft::vectorIterator<T> > lhs, const ft::revVectorIterator<T, ft::constVectorIterator<T> > rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T>
	bool operator>=(const ft::revVectorIterator<T, ft::vectorIterator<T> > lhs, const ft::revVectorIterator<T, ft::constVectorIterator<T> > rhs)
	{
		return (lhs.base() <= rhs.base());
	}
}
#endif
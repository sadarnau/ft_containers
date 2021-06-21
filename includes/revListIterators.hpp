/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revListIterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:43:57 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 16:09:50 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVLISTITERATORS_HPP
# define REVLISTITERATORS_HPP

# include "list.hpp"
# include "listIterators.hpp"

namespace ft
{
	template <typename T, typename Iterator>
	class revListIterator
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
			revListIterator( void ) : _it(NULL) 			{}
			revListIterator( const iteratorType rhs ) : _it(rhs) {};

			template <typename It>
			revListIterator( const revListIterator<T, It> &rhs ) : _it(rhs.base()) {};

			~revListIterator( void )	{}

			revListIterator &operator=( const revListIterator &rhs )
			{
				this->_it = rhs._it;
				return ( *this );
			}
			template <typename It>
			revListIterator &operator=( const revListIterator<T, It> &rhs )
			{
				this->_it = rhs.base();
				return ( *this );
			}
			revListIterator &operator++( void )		//++it
			{
				--_it;
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
				++_it;
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

			template <class It>				
			difference_type operator -(revListIterator<T, It> b) { return (b.base().operator-(_it)); }	// a - b
			template <class It>
			difference_type operator +(revListIterator<T, It> b) { return (b.base().operator+(_it)); }	// a + b
		
			bool operator !=(revListIterator const &rhs)	const	{ return ( this->_it != rhs.base() ); }
			bool operator ==(revListIterator const &rhs)	const	{ return ( this->_it == rhs.base()); }
			bool operator < (revListIterator const &rhs)	const	{ return ( this->_it > rhs.base()); }
			bool operator <=(revListIterator const &rhs)	const	{ return ( this->_it >= rhs.base()); }
			bool operator > (revListIterator const &rhs)	const	{ return ( this->_it < rhs.base()); }
			bool operator >=(revListIterator const &rhs)	const	{ return ( this->_it <= rhs.base()); }

			friend revListIterator operator+(int n, const revListIterator& it)	{ return (it + n); }
			friend revListIterator operator-(int n, const revListIterator& it)	{ return (it - n); }		

			reference operator*( void )
			{
				revListIterator tmp(*this);
				--tmp._it;
			
				return ( tmp._it.getPtr()->data );
			}
			value_type * operator->( void )
			{
				revListIterator tmp(*this);
				--tmp._it;
			
				return ( &tmp._it.getPtr()->data );
			}
			reference operator[](int n)	{ return ( *(*this + n) ); }
	
			iteratorType base() const	{ return ( _it ); }
	};

	template<typename T>
	bool operator==(const ft::revListIterator<T, ft::listIterator<T> > lhs, const ft::revListIterator<T, ft::constListIterator<T> > rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T>
	bool operator!=(const ft::revListIterator<T, ft::listIterator<T> > lhs, const ft::revListIterator<T, ft::constListIterator<T> > rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T>
	bool operator<(const ft::revListIterator<T, ft::listIterator<T> > lhs, const ft::revListIterator<T, ft::constListIterator<T> > rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T>
	bool operator>(const ft::revListIterator<T, ft::listIterator<T> > lhs, const ft::revListIterator<T, ft::constListIterator<T> > rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T>
	bool operator<=(const ft::revListIterator<T, ft::listIterator<T> > lhs, const ft::revListIterator<T, ft::constListIterator<T> > rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T>
	bool operator>=(const ft::revListIterator<T, ft::listIterator<T> > lhs, const ft::revListIterator<T, ft::constListIterator<T> > rhs)
	{
		return (lhs.base() <= rhs.base());
	}
}

#endif
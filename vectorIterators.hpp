/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:10 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/08 17:34:14 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORS_HPP
# define VECTORITERATORS_HPP

# include "vector.hpp"

namespace ft
{
	// template< class Category,
	// 		class T,
	// 		class Distance = std::ptrdiff_t,
	// 		class Pointer = T*,
	// 		class Reference = T& >
	// struct iterator {
	// 	typedef Distance difference_type;
	// 	typedef T value_type;
	// 	typedef Pointer pointer;
	// 	typedef Reference reference;
	// 	typedef Category iterator_category;
	// };
// https://github.com/lsoulier42/ft_containers/blob/main/includes/iterator.hpp

	template <typename T>
	class vectorIterator : public iterator
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
			vectorIterator( void ) : _ptr(NULL) {};
			vectorIterator( const vectorIterator &rhs ) { *this = rhs; };
			vectorIterator( pointer ptr ) : _ptr( ptr ) {};
			~vectorIterator( void ) {};
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
			bool operator!=( const vectorIterator &rhs ) const { return ( this->_ptr != rhs._ptr ); }
			bool operator!=( const constVectorIterator &rhs ) const { return ( this->_ptr != rhs.getPtr() ); };
			bool operator ==(vectorIterator const& rhs) const { return ( this->_ptr == rhs._ptr); }
			bool operator <(vectorIterator const& rhs) const { return ( this->_ptr < rhs._ptr); }
			bool operator <=(vectorIterator const& rhs) const { return ( this->_ptr <= rhs._ptr); }
			bool operator >(vectorIterator const& rhs) const { return ( this->_ptr > rhs._ptr); }
			bool operator >=(vectorIterator const& rhs) const { return ( this->_ptr >= rhs._ptr); }

			friend vectorIterator operator+(int n, const vectorIterator& it)
			{ return (it + n); }

			reference operator*( void )					{ return ( *this->_ptr ); }
			const_reference operator *( void ) const	{ return ( *this->_ptr ); }
			pointer operator->() { return (this->_ptr); }
			pointer operator->() const { return (this->_ptr); }
			reference operator[](int n)	{ return (*(*this + n)); }
			const_reference operator[](int n) const	{ return (*(*this + n)); }
			pointer	getPtr() const { return( this->_ptr ); }
	};

	template <typename T>
	class constVectorIterator : public iterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef 	T*					pointer;
			typedef 	T const *			const_pointer;
			typedef typename std::ptrdiff_t difference_type;

		private:
			pointer							_ptr;

		public:
			constVectorIterator( void ) : _ptr(NULL) {};
			constVectorIterator( const constVectorIterator &rhs ) { *this = rhs; };
			constVectorIterator( const vectorIterator<T> &rhs ) { *this = rhs; };
			constVectorIterator( pointer ptr ) : _ptr( ptr ) {};
			~constVectorIterator( void ) {};

			constVectorIterator &operator=( const constVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};
			constVectorIterator &operator=( const vectorIterator<T> &rhs )
			{
				this->_ptr = rhs.getPtr();
				return ( *this );
			};
			constVectorIterator &operator++( void )	//++it
			{
				this->_ptr++;
				return ( *this );
			};
			constVectorIterator operator++( int )		//it++
			{
				constVectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			constVectorIterator &operator--( void )
			{
				this->_ptr--;
				return ( *this );
			};
			constVectorIterator operator--( int )
			{
				constVectorIterator tmp(*this);
				operator--();
				return (tmp);
			};
			constVectorIterator operator+(int n) const
			{
				constVectorIterator tmp(*this);
				while (n--)
					tmp++;
				return (tmp);
			};
			constVectorIterator operator-(int n) const
			{
				constVectorIterator tmp(*this);
				while (n--)
					tmp--;
				return (tmp);
			};
			constVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			};
			constVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			};
			difference_type operator -(constVectorIterator b) { return (_ptr - b._ptr); }; // a - b
			difference_type operator -(constVectorIterator b) const { return (_ptr - b._ptr); }; // a - b
			difference_type operator +(constVectorIterator b) { return (_ptr + b._ptr); }; // a + b
			difference_type operator +(constVectorIterator b) const { return (_ptr + b._ptr); }; // a + b

			friend constVectorIterator operator+(int n, const constVectorIterator& it)
			{ return (it + n); }

			bool operator!=( const constVectorIterator &rhs ) const { return ( this->_ptr != rhs._ptr ); };
			// bool operator!=( const vectorIterator<T> &rhs ) const { return ( this->_ptr != rhs._ptr ); };
			bool operator==( const vectorIterator<T> &rhs ) const { return ( this->_ptr == rhs.getPtr() ); };
			bool operator ==(constVectorIterator const& rhs) const { return ( this->_ptr == rhs._ptr); }
			bool operator <(constVectorIterator const& rhs) const { return ( this->_ptr < rhs._ptr); }
			bool operator <=(constVectorIterator const& rhs) const { return ( this->_ptr <= rhs._ptr); }
			// bool operator <=(vectorIterator<T> const& rhs) const { std::cout << "\n1\n";return ( this->_ptr <= rhs.getPtr()); }
			bool operator >(constVectorIterator const& rhs) const { return ( this->_ptr > rhs._ptr); }
			bool operator >=(constVectorIterator const& rhs) const { return ( this->_ptr >= rhs._ptr); }

			reference operator*( void )					{ return ( *this->_ptr ); };
			const_reference operator *( void ) const	{ return ( *this->_ptr ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
			pointer	getPtr() const { return( this->_ptr ); }
	};

	template <typename T>
	class revVectorIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef 	T*				pointer;
			typedef 	T const *			const_pointer;

		private:
			pointer							_ptr;

		public:
			revVectorIterator( void ) : _ptr(NULL) {};
			revVectorIterator( const revVectorIterator &rhs ) { *this = rhs; };
			revVectorIterator( pointer ptr ) : _ptr( ptr ) { };
			~revVectorIterator( void ) {};

			revVectorIterator &operator=( const revVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			revVectorIterator &operator++( void )		//++it
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			revVectorIterator operator++( int )		//it++
			{
				revVectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			revVectorIterator &operator--( void )
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			revVectorIterator operator--( int )
			{
				revVectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const revVectorIterator &rhs ) const	{ return ( this->_ptr != rhs._ptr ); };
			bool operator ==(revVectorIterator const& rhs) const	{ return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
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

		private:
			pointer							_ptr;

		public:
			constRevVectorIterator( void ) : _ptr(NULL) {};
			constRevVectorIterator( const constRevVectorIterator &rhs ) { *this = rhs; };
			constRevVectorIterator( pointer ptr ) : _ptr( ptr ) { };
			~constRevVectorIterator( void ) {};

			constRevVectorIterator &operator=( const constRevVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			constRevVectorIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			constRevVectorIterator operator++( int )		//it++
			{
				constRevVectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			constRevVectorIterator &operator--( void )
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			constRevVectorIterator operator--( int )
			{
				constRevVectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const constRevVectorIterator &rhs ) const	{ return ( this->_ptr != rhs._ptr ); };
			bool operator ==(constRevVectorIterator const& rhs) const	{ return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
	};
	template <typename T>
	typename ft::vectorIterator<T>::difference_type
	operator==(const ft::vectorIterator<T> lhs,
			const ft::constVectorIterator<T> rhs)
	{
		return (lhs.getPtr() != rhs.getPtr());
	}

	// /* For iterator == const_iterator */
	// template<typename T_L, typename T_R>
	// typename ft::vectorIterator<T_L>::difference_type
	// operator==(const ft::vectorIterator<T_L> lhs,
	// 		const ft::constVectorIterator<T_R> rhs)
	// {
	// 	std::cout << "\n2\n";
	// 	return (lhs.getPtr() == rhs.getPtr());
    // }
	
	// template <typename T>
	// typename ft::vectorIterator<T>::difference_type
	// operator==(const ft::constVectorIterator<T> lhs,
	// 		const ft::vectorIterator<T> rhs)
	// {
	// 	std::cout << "\n3\n";
	// 	return (lhs.getPtr() == rhs.getPtr());
	// }

	// /* For iterator == const_iterator */
	// template<typename T_L, typename T_R>
	// typename ft::vectorIterator<T_L>::difference_type
	// operator==(const ft::constVectorIterator<T_L> lhs,
	// 		const ft::vectorIterator<T_R> rhs)
	// {
	// 	std::cout << "\n4\n";
	// 	return (lhs.getPtr() == rhs.getPtr());
	// }
}

#endif

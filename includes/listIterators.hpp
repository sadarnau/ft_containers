/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:10 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/03 15:50:47 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATORS_HPP
# define LISTITERATORS_HPP

# include "list.hpp"

namespace ft
{
	template < typename T >
	struct node
	{
		node	*prev;
		node	*next;
		T		data;
	};

	template <typename T>
	class listIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;

		private:
			pointer							_ptr;

		public:
			listIterator( void ) : _ptr(NULL) {};
			listIterator( const listIterator &rhs ) { *this = rhs; };
			listIterator( pointer ptr ) : _ptr( ptr ) { };
			~listIterator( void ) {};
			
			pointer node(void) const
			{
				return (_ptr);
			};
			
			listIterator &operator=( const listIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			listIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			listIterator operator++( int )		//it++
			{
				listIterator tmp(*this);
				operator++();
				return (tmp);
			};
			listIterator &operator--( void )
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			listIterator operator--( int )
			{
				listIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const listIterator &rhs ) const { return ( this->_ptr != rhs._ptr ); };
			bool operator ==(listIterator const& rhs) const { return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
	};

	template <typename T>
	class constListIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;

		private:
			pointer							_ptr;

		public:
			constListIterator( void ) : _ptr(NULL) {};
			constListIterator( const constListIterator &rhs ) { *this = rhs; };
			constListIterator( pointer ptr ) : _ptr( ptr ) { };
			~constListIterator( void ) {};

			constListIterator &operator=( const constListIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			constListIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			constListIterator operator++( int )		//it++
			{
				constListIterator tmp(*this);
				operator++();
				return (tmp);
			};
			constListIterator &operator--( void )
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			constListIterator operator--( int )
			{
				constListIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const constListIterator &rhs ) const { return ( this->_ptr != rhs._ptr ); };
			bool operator ==(constListIterator const& rhs) const { return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
	};

	template <typename T>
	class revListIterator
	{
		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;

		private:
			pointer							_ptr;

		public:
			revListIterator( void ) : _ptr(NULL) {};
			revListIterator( const revListIterator &rhs ) { *this = rhs; };
			revListIterator( pointer ptr ) : _ptr( ptr ) { };
			~revListIterator( void ) {};

			revListIterator &operator=( const revListIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			revListIterator &operator++( void )		//++it
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			revListIterator operator++( int )		//it++
			{
				revListIterator tmp(*this);
				operator++();
				return (tmp);
			};
			revListIterator &operator--( void )
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			revListIterator operator--( int )
			{
				revListIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const revListIterator &rhs ) const	{ return ( this->_ptr != rhs._ptr ); };
			bool operator ==(revListIterator const& rhs) const	{ return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
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

		private:
			pointer							_ptr;

		public:
			constRevListIterator( void ) : _ptr(NULL) {};
			constRevListIterator( const constRevListIterator &rhs ) { *this = rhs; };
			constRevListIterator( pointer ptr ) : _ptr( ptr ) { };
			~constRevListIterator( void ) {};

			constRevListIterator &operator=( const constRevListIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			constRevListIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			constRevListIterator operator++( int )		//it++
			{
				constRevListIterator tmp(*this);
				operator++();
				return (tmp);
			};
			constRevListIterator &operator--( void )
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			constRevListIterator operator--( int )
			{
				constRevListIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const constRevListIterator &rhs ) const	{ return ( this->_ptr != rhs._ptr ); };
			bool operator ==(constRevListIterator const& rhs) const	{ return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
	};
}

#endif

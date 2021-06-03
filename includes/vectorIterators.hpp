/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:49:10 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/03 16:29:53 by sadarnau         ###   ########.fr       */
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
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;

		private:
			pointer							_ptr;

		public:
			vectorIterator( void ) : _ptr(NULL) {};
			vectorIterator( const vectorIterator &rhs ) { *this = rhs; };
			vectorIterator( pointer ptr ) : _ptr( ptr ) { };
			~vectorIterator( void ) {};
			
			pointer node(void) const
			{
				return (_ptr);
			};
			
			vectorIterator &operator=( const vectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			vectorIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->next;
				return ( *this );
			};
			vectorIterator operator++( int )		//it++
			{
				vectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			vectorIterator &operator--( void )
			{
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			vectorIterator operator--( int )
			{
				vectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const vectorIterator &rhs ) const { return ( this->_ptr != rhs._ptr ); };
			bool operator ==(vectorIterator const& rhs) const { return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
	};

	template <typename T>
	class constVectorIterator
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
			constVectorIterator( void ) : _ptr(NULL) {};
			constVectorIterator( const constVectorIterator &rhs ) { *this = rhs; };
			constVectorIterator( pointer ptr ) : _ptr( ptr ) { };
			~constVectorIterator( void ) {};

			constVectorIterator &operator=( const constVectorIterator &rhs )
			{
				this->_ptr = rhs._ptr;
				return ( *this );
			};

			constVectorIterator &operator++( void )	//++it
			{
				this->_ptr = this->_ptr->next;
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
				this->_ptr = this->_ptr->prev;
				return ( *this );
			};
			constVectorIterator operator--( int )
			{
				constVectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

			bool operator!=( const constVectorIterator &rhs ) const { return ( this->_ptr != rhs._ptr ); };
			bool operator ==(constVectorIterator const& rhs) const { return ( this->_ptr == rhs._ptr); }

			reference operator*( void )					{ return (  this->_ptr->data ); };
			const_reference operator *( void ) const	{ return ( this->_ptr->data ); };
			pointer operator->() { return (this->_ptr); };
			pointer operator->() const { return (this->_ptr); };
	};

	template <typename T>
	class revVectorIterator
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
			typedef node<T>*				pointer;
			typedef node<T> const *			const_pointer;

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
}

#endif

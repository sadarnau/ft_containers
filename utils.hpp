#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

/*
** @brief Type of the null pointer constant.
** Permetted implicit conversions to null pointer ,
** similary conversions for all type of contant null pointer.
**
** From : (Take a look)
** https://www.amazon.com/dp/0201924889
*/
static class nullptr_t
{
    public:
        /*
        ** @brief For conversion to any type
        ** of null non-member pointer.
        */
        template<class T>
        operator T*() const { return (0); }

        /*
        ** @brief For conversion to any type of null
        ** member pointer.
        */
        template<class C, class T>
        operator T C::*() const { return (0); }

    private:
        
        /*
        ** @brief It's imposible to get an address of
        ** a nullptr.
        */
        void operator&() const;

} u_nullptr = {};

namespace ft
{

    /*
    ** @brief Empty class to identify the category of an
    ** "random access iterator". This type of iterator is the
    ** most complete iterators. Is particularity is that, it
    ** allow to access elements at an arbitrary offset.
    ** Take a look :
    ** http://www.cplusplus.com/reference/iterator/RandomAccessIterator/
    */
    class random_access_iterator_tag { };


    /*
    ** @brief Iterator traits class defining properties of
    ** iterators. In this, iterator_traits obtains information
    ** from Iterator class in template argument.
    */
    template <class Iterator> struct iterator_traits
    {
        /* Result of subtracting one iterator from another, from Iterator. */
        typedef typename Iterator::difference_type       difference_type;

        /* Type of the element where iterator point, from Iterator. */
        typedef typename Iterator::value_type            value_type;

        /* Type of a pointer to an element where the iterator point, from Iterator. */
        typedef typename Iterator::pointer               pointer;

        /* Type of a reference where iterator point, from Iterator. */
        typedef typename Iterator::reference             reference;

        /* The iterator category from Iterator. */
        typedef typename Iterator::iterator_category     iterator_category;
    };
    

    
    /*
    ** @brief Iterator traits class defining properties of
    ** iterators. This create a default operation with a
    ** const object (first argument in tempate argument).
    */
    template <class T> class iterator_traits<const T*>
    {
        /* Result of subtracting one iterator from another. */
        typedef ptrdiff_t                       difference_type;

        /* Type of the element where iterator point. */
        typedef T                               value_type;

        /* Type of a pointer to an element where the iterator point. */
        typedef const T*                        pointer;

        /* Type of a reference where iterator point. */
        typedef const T&                        reference;

        /* The iterator category from Iterator. */
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    /*
    ** @brief Base class for iterator, not really usefull, but type
    ** defined can be use for iterator_traits. An iterator permeted to
    ** take any element range in an object and using a set of operators.
    */
    template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                /* Type of elements pointed. */
                typedef T           value_type;

                /* Type to represent the difference between two iterators. */
                typedef Distance    difference_type;

                /* Type to represent a pointer to an element pointed */
                typedef Pointer     pointer;

                /* Type to represent a reference to an element pointed */
                typedef Reference   reference;

                /* Category of the iterator. */
                typedef Category    iterator_category;
        };

    template <class Iterator>
    class reverse_iterator
    {
        public:

            /* Iterator's type. */
            typedef Iterator    iterator_type;

            /* Preserves Iterator's category. */
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            
            /* Preserves Iterator's value type. */
            typedef typename ft::iterator_traits<Iterator>::value_type      value_type;
            
            /* Preserves Iterator's difference type. */
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            
            /* Preserves Iterator's pointer. */
            typedef typename ft::iterator_traits<Iterator>::pointer     pointer;
            
            /* Preserves Iterator's reference. */
            typedef typename ft::iterator_traits<Iterator>::reference   reference;
            
            /*
            ** @brief Default.
            ** Construct a reverse iterator object.
            ** This will points to no object.
            */
            reverse_iterator()
            :
                _elem()
            {}

            /*
            ** @brief Initialization.
            ** Construct a reverse iterator object from
            ** an original iteretor "it".
            ** The behavior of the constructed object
            ** replicate the orignal, but he iterates
            ** in the reverse order.
            **
            ** @param it The iterator to replicate.
            */
            explicit reverse_iterator (iterator_type it)
            :
                _elem(it)
            {}

            /*
            ** @brief Copy.
            ** Contruct a reverse iterator from other reverse iterator.
            ** Save the sense of iterateration as "rev_it".
            **
            ** @param rev_it original reverse iterator.
            */
            template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                :
                    _elem(rev_it.base())
                {}

            /* Added to follow subject obligation */
            virtual ~reverse_iterator() {}

            /*
            ** @brief Return a copy of the base iterator.
            ** Same type as the usert to construct the reverse_iterator.
            ** But pointing to the element next of this.
            ** (A reverse iterator always pointing to an element at
            ** an offset of -1).
            **
            ** @return A copy of the base iterator.
            */
            iterator_type base() const
            { return (_elem); }

            /*
            ** @brief Return a reference to the element pointed
            ** by the iterator.
            **
            ** @return The reference.
            */
            reference operator*() const
            {
                iterator_type tmp = _elem;
                return (*(--tmp));
            }

            /*
            ** @brief Return a reverse iterator pointing to
            ** the element at n position away from the pointed
            ** element of the iterator.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param "n" Number of elements to offset.
            ** @return An iterator pointing to the element at "n"
            ** position away.
            */
            reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_elem - n)); }

            /*
            ** @brief Advances the reverse_iterator by one position.
            ** Pre-increment.
            **
            ** @return return "(*this)" incremented.
            */
            reverse_iterator& operator++()
            {
                --_elem;
                return (*this);
            }

            /*
            ** @brief Advances the reverse_iterator by one position.
            ** Post-increment.
            **
            ** @return the value "(*this)" value had before the
            ** call.
            */
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            /*
            ** @brief Advances the "reverse_iterator" by n element positions.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param n the number of element.
            ** @return the reverse iterator itself (*this).
            */
            reverse_iterator& operator+= (difference_type n)
            {
                _elem -= n;
                return (*this);
            }

            /*
            ** @brief Return a reverse iterator pointing to the element
            ** located n positions before the element the iterator
            ** currently points to.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param n the number of element.
            ** @return An iterator pointing to the element
            ** n position before the currently pointed one.
            */
            reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_elem + n)); }

            /*
            ** @brief Decreases the reverse iterator by one position.
            **
            ** @return "(*this)".
            */
            reverse_iterator& operator--()
            {
                ++_elem;
                return (*this);
            }

            /*
            ** @brief Decreases the reverse iterator by one position.
            **
            ** @retun "(*this)" value before the call.
            */
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

            /*
            ** @brief Decreases the reverse iterator by "n" element
            ** postion.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param n Number of elements to offset.
            ** @return "(*this)".
            */
            reverse_iterator& operator-= (difference_type n)
            {
                _elem += n;
                return (*this);
            }

            /*
            ** @brief Give a pointer to the element
            ** pointed.
            **
            ** @return A pointer to the element pointed.
            */
            pointer operator->() const { return &(operator*()); }

            /*
            ** @brief Accesse the element at "n" positions
            ** away from the element currently pointed.
            ** Cause undefined behavior if the element
            ** does not exist.
            **
            ** @param n The number of positions.
            ** @return A reference at "n".
            */
            reference operator[] (difference_type n) const { return (this->base()[-n - 1]); }

        private:
            iterator_type     _elem;
    };

}

# endif
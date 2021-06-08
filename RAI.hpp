#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "utils.hpp"

namespace ft
{

    template <typename T>
        class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
        {
            public:
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
                typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
                typedef T*               pointer;
                typedef T&             reference;

                random_access_iterator(void)
                :
                    _elem(u_nullptr)
                {}
                random_access_iterator(pointer elem)
                :
                    _elem(elem)
                {}
                random_access_iterator(const random_access_iterator& op)
                :
                    _elem(op._elem)
                {}

                random_access_iterator &operator=(const random_access_iterator& op)
                {
                    if (this == &op)
		                return (*this);
                    this->_elem = op._elem;
                    return (*this);
                }

                virtual ~random_access_iterator() {}
                pointer base() const
                { return (this->_elem); }

                reference operator*(void) const { return (*_elem); }

                pointer operator->(void) { return &(this->operator*()); }

                random_access_iterator& operator++(void)
                {
                    _elem++;
                    return (*this);
                }

                random_access_iterator operator++(int)
                {
                    random_access_iterator rtn(*this);
                    operator++();
                    return (rtn);
                }

                random_access_iterator& operator--(void)
                {
                    _elem--;
                    return (*this);
                }

                random_access_iterator operator--(int)
                {
                    random_access_iterator rtn(*this);
                    operator--();
                    return (rtn);
                }

                random_access_iterator operator+(difference_type n) const { return (_elem + n); }

                random_access_iterator operator-(difference_type n) const { return (_elem - n); }

                random_access_iterator& operator+=(difference_type n)
                {
                    _elem += n;
                    return (*this);
                }

                random_access_iterator& operator-=(difference_type n)
                {
                    _elem -= n;
                    return (*this);
                }

                reference operator[](difference_type n) { return (*(operator+(n))); }

                operator random_access_iterator<const T> () const
                { return (random_access_iterator<const T>(this->_elem)); }

                private:
                    pointer _elem;
        };

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator==(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    /* For iterator == const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator==(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    /*
    ** @brief Check if the pointer of "lhs"
    ** is different than "rhs" in the memory.
    **
    ** @param lhs the random access iterator to compare.
    ** @param rhs the random access iterator with who check.
    ** @return true if the pointer of lhs
    ** if different than "rhs", otherwise false.
    */
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    /* For iterator != const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator!=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    /*
    ** @brief Check if the pointer of "lhs"
    ** is lower than "rhs" in the memory.
    **
    ** @param lhs the random access iterator to compare.
    ** @param rhs the random access iterator with who check.
    ** @return true if the pointer of lhs
    ** if lower than "rhs", otherwise false.
    */
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    /* For iterator < const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    /*
    ** @brief Check if the pointer of "lhs"
    ** is upper than "rhs" in the memory.
    **
    ** @param lhs the random access iterator to compare.
    ** @param rhs the random access iterator with who check.
    ** @return true if the pointer of lhs
    ** if upper than "rhs", otherwise false.
    */
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    /* For iterator > const_iterator */
    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    /*
    ** @brief Check if the pointer of "lhs"
    ** is lower or equal than "rhs" in the memory.
    **
    ** @param lhs the random access iterator to compare.
    ** @param rhs the random access iterator with who check.
    ** @return true if the pointer of lhs
    ** if lower or equal than "rhs", otherwise false.
    */
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    /* For iterator <= const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    /* For iterator >= const_iterator */
    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() >= rhs.base());
    }


    template<typename T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        typename ft::random_access_iterator<T>& rai)
        {
            return (&(*rai) + n);
        }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }

    /* For iterator - const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator-(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() - rhs.base());
    }

}

#endif
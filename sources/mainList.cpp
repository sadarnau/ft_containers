/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:57:00 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/03 14:56:07 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>

# define RESET "\e[0m"
# define GREEN "\e[92m"
# define BLUE "\e[94m"
# define BOLD "\e[1m"

# define GOOD "✓"
# define FAIL "❌"

void	print_list(std::list<int> list)
{	
	std::cout << "\nSTDlist contains:";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
}

template <typename T>
void	print_Mylist(ft::list<T> list)
{
	typename ft::list<T>::iterator it = list.begin();

	std::cout << "\nMylist contains:";
	for (it=list.begin(); it != list.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n";
}

template <typename T>
bool operator==(ft::list<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::list<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
}

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(38 - name.length(), ' ');
	if (a == b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(38 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

static void constructors(void)
{
	std::cout << "\nDefault constructor\n\n";
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	check("(default) l1 == l2", l1 == l2);
	ft::list<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	check("(fill with default value) l3 == l4", l3 == l4);
	ft::list<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	check("(fill) l5 == l6", l5 == l6);
	ft::list<int> l7(test, test + 4);
	std::list<int> l8(test, test + 4);
	check("(iterator) l7 == l8", l7 == l8);
	ft::list<int> l9(l7);
	std::list<int> l10(l8);
	check("(copy) l9 == l10", l9 == l10);
}

static void copy_operator(void)
{
	std::cout << "Operator =\n\n";
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1(test, test + 4);
	std::list<int> l2(test, test + 4);
	ft::list<int> l3;
	std::list<int> l4;
	l3 = l1;
	l4 = l2;
	check("l1 == l3", l1 == l3);
	check("l2 == l4", l2 == l4);
	l1.push_back(1);
	l2.push_back(1);
	check("l1 != l3", l1 != l3);
	check("l2 != l4", l2 != l4);
}

static void max_size(void)
{
	std::cout << "Max size\n\n";
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<std::string> l3;
	std::list<std::string> l4;
	check("l1.max_size() == l2.max_size()", l1.max_size(), l2.max_size());
	check("l3.max_size() == l4.max_size()", l3.max_size(), l4.max_size());
}

static void front_back(void)
{
	std::cout << "Front / Back\n\n";
	ft::list<int> l1;
	std::list<int> l2;
	check("front == back", l1.front() == l1.back());
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	check("l1.front() == l2.front()", l1.front(), l2.front());
	check("l1.back() == l2.back()", l1.back(), l2.back());
}

static void assign(void)
{
	std::cout << "\nAssign\n\n";
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	l1.assign(test, test + 4);
	l2.assign(test, test + 4);
	check("l1 == l2", l1 == l2);
	l1.assign((size_t)10, 42);
	l2.assign((size_t)10, 42);
	check("l1 == l2", l1 == l2);
}

static void push(void)
{
	std::cout << "\nPush front/back\n\n";
	ft::list<int> l1;
	std::list<int> l2;
	for (int _ = 0; _ < 100; _++)
	{
		if (rand() % 2)
		{
			int n = rand() % 100;
			l1.push_front(n);
			l2.push_front(n);
		}
		else
		{
			int n = rand() % 100;
			l1.push_back(n);
			l2.push_back(n);
		}
	}
	check("l1 == l2", l1 == l2);
}

static void swap(void)
{
	std::cout << "Swap\n";
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<int> l3;
	std::list<int> l4;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l2.push_front(1);
	l2.push_front(2);
	l2.push_front(3);
	l3.push_front(42);
	l4.push_front(42);
	l1.swap(l3);
	l2.swap(l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static void resize(void)
{
	std::cout << "Resize / Clear\n";
	ft::list<int> l1;
	std::list<int> l2;
	l1.resize(10, 42);
	l2.resize(10, 42);
	check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l2.resize(2, 42);
	check("l1 == l2", l1 == l2);
	l1.resize(0, 0);
	l2.resize(0, 0);
	check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l1.clear();
	l2.resize(2, 42);
	l2.clear();
	check("l1 == l2", l1 == l2);
}

static void splice(void)
{
	std::cout << "Splice\n";
	ft::list<int> l1((size_t)10, 5);
	std::list<int> l2((size_t)10, 5);
	ft::list<int> l3((size_t)3, 0);
	std::list<int> l4((size_t)3, 0);
	l1.splice(++l1.begin(), l3);
	l2.splice(++l2.begin(), l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin());
	l2.splice(l2.begin(), l4, ++l4.begin());
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin(), --l3.end());
	l2.splice(l2.begin(), l4, ++l4.begin(), --l4.end());
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static bool even(const int& value) { return (value % 2) == 0; } 

static void remove(void)
{
	std::cout << "Remove / Remove if\n";
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.remove(0);
	l1.remove(5);
	l2.remove(0);
	l2.remove(5);
	check("l1 == l2", l1 == l2);
	l1.remove_if(even);
	l2.remove_if(even);
	check("l1 == l2", l1 == l2);
}

static void erase(void)
{
	std::cout << "Erase\n";
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.erase(l1.begin());
	l1.erase(--l1.end());
	l1.erase(--l1.end());
	l2.erase(l2.begin());
	l2.erase(--l2.end());
	l2.erase(--l2.end());
	check("l1 == l2", l1 == l2);
	l1.erase(++l1.begin(), --l1.end());
	l2.erase(++l2.begin(), --l2.end());
	check("l1 == l2", l1 == l2);
}

static bool compare(int a, int b) 
{ 
    return (a >= b); 
} 

static void unique()
{
	std::cout << "Unique\n";
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.unique();
	l2.unique();
	check("l1 == l2", l1 == l2);
	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	l1.unique(compare);
	l2.unique(compare);
	check("l1 == l2", l1 == l2);
}

static bool compare2(int a, int b) 
{ 
    return (a == b); 
} 

static void merge(void)
{
	std::cout << "Merge\n";
	int test[] = {1, 2, 3};
	int test2[] = {42, 43, 44};
	ft::list<int> l1(test, test + 3);
	std::list<int> l2(test, test + 3);
	ft::list<int> l3(test2, test2 + 3);
	std::list<int> l4(test2, test2 + 3);
	l1.merge(l3);
	l2.merge(l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign(test, test + 3);
	l2.assign(test, test + 3);
	l3.assign(test2, test2 + 3);
	l4.assign(test2, test2 + 3);
	l1.merge(l3, compare2);
	l2.merge(l4, compare2);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static void reverse(void)
{
	std::cout << "Reverse\n";
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	check("l1 == l2", l1 == l2);
}

static void operators(void)
{
	std::cout << "Operators\n";
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	ft::list<int> l3(l1);
	std::list<int> l4(l2);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l1.push_back(42);
	l2.push_back(42);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l3.push_back(43);
	l4.push_back(43);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
}

bool sup_nine (const int& value) { return (value>9); }
bool same_integral_part (int first, int second) { return ( int(first)==int(second) ); }

int	main ()
{
	std::list<int>	list1;
	ft::list<int>	list2;

	std::cout << "empty ? std = " << list1.empty() << " and mine = " << list2.empty() << "\n";

 	list1.push_front(1);
 	list2.push_front(1);
	
	std::cout << "\npush front 1\nback : std = " << list1.back() << " and mine = " << list2.back() << "\n";
	std::cout << "size : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";
	std::cout << "empty ? std = " << list1.empty() << " and mine = " << list2.empty() << "\n";

	list1.push_back(5);
	list2.push_back(5);
	std::cout << "\npush back 5 :\nback : std = " << list1.back() << " and mine = " << list2.back() << "\n";
	std::cout << "size : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";


	list1.pop_back();
	list2.pop_back();
	std::cout << "\npop back :\nback : std = " << list1.back() << " and mine = " << list2.back() << "\n";
	std::cout << "size : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";

	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);
	list2.push_back(5);
	std::cout << "\n1 to 5 :\nback : std = " << list1.back() << " and mine = " << list2.back() << "\n";
	std::cout << "size : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";

	print_list(list1);
	print_Mylist(list2);

	list2.pop_front();
	list2.pop_front();
	list1.pop_front();
	list1.pop_front();
	std::cout << "\npop_front * 2\nback : std = " << list1.back() << " and mine = " << list2.back() << "\n";
	std::cout << "size : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";
	std::cout << "max_size : std = " << list1.max_size() << " and mine = " << list2.max_size() << "\n";

	list1.clear();
	list2.clear();
	std::cout << "\nclear :\nsize : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);
	list2.push_back(5);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);

	std::cout << "\n\ninsert 5 in begin() :";
	ft::list<int> l3((size_t)10, 42);
	std::list<int> l4((size_t)10, 42);
	ft::list<int>::iterator it = l3.begin();
	std::list<int>::iterator it2 = l4.begin();
	l3.insert(it, 5);
	l4.insert(it2, 5);
	print_list(l4);
	print_Mylist(l3);
	it++;
	it++;
	it2++;
	it2++;
	std::cout << "\ninsert 5 in 4th position";
	l3.insert(it, 5);
	l4.insert(it2, 5);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\ninsert three 6 in 4th position";
	l3.insert(it, (size_t)3, 6);
	l4.insert(it2, 3, 6);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\ninsert '2 3 4 5' with iterators";
	l3.insert(it, list2.begin(), list2.end());
	l4.insert(it2, list1.begin(), list1.end());
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nerase the 12th element";
	l3.erase(it);
	l4.erase(it2);
	print_list(l4);
	print_Mylist(l3);
	it = l3.begin();
	it2 = l4.begin();
	it++;
	it++;
	it2++;
	it2++;	
	std::cout << "\nerase all elements after the 2cd";
	l3.erase(it, l3.end());
	l4.erase(it2, l4.end());
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nresize(6, 64) :";
	l3.resize(6, 64);
	l4.resize(6, 64);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nresize(3, 10) :";
	l3.resize(3, 10);
	l4.resize(3, 10);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nremove(42) :";
	l3.remove(42);
	l4.remove(42);
	print_list(l4);
	print_Mylist(l3);
	l3.resize(5, 10);
	l4.resize(5, 10);
	std::cout << "\nremove_if >9 from :";
	print_list(l4);
	print_Mylist(l3);
	l3.remove_if(sup_nine);
	l4.remove_if(sup_nine);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nunique from :";
	l3.resize(5, 10);
	l4.resize(5, 10);
	print_list(l4);
	print_Mylist(l3);
	l3.unique();
	l4.unique();
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nunique = from :";
	l3.resize(5, 8);
	l4.resize(5, 8);
	l3.push_back(5);
	l4.push_back(5);
	print_list(l4);
	print_Mylist(l3);
	l3.unique(same_integral_part);
	l4.unique(same_integral_part);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nswap with list1 : ";
	l3.swap(list2);
	l4.swap(list1);
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nreverse : ";
	l3.reverse();
	l4.reverse();
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nsort : ";
	l3.sort();
	l4.sort();
	print_list(l4);
	print_Mylist(l3);
	std::cout << "\nmerge : ";
	l3.merge(list2);
	l4.merge(list1);
	print_list(l4);
	print_Mylist(l3);

	constructors();
	copy_operator();
	max_size();
	front_back();
	assign();
	push();
	swap();
	resize();
	splice();
	remove();
	erase();
	unique();
	merge();
	reverse();
	operators();

	return 0;
}

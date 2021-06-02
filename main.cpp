/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:57:00 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/02 17:08:01 by sadarnau         ###   ########.fr       */
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
	
	constructors();
	copy_operator();
	max_size();
	front_back();
	assign();
	push();

	return 0;
}

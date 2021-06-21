/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:57:00 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/21 13:55:03 by sadarnau         ###   ########.fr       */
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
	std::cout << "begin : std = " << *list1.begin() << " and mine = " << *list2.begin() << "\n";

	// list2.push_back(2);
	// list2.push_back(3);
	// list2.push_back(4);
	// list2.push_back(5);
	// list1.push_back(2);
	// list1.push_back(3);
	// list1.push_back(4);
	// list1.push_back(5);

	// std::cout << "\n\ninsert 5 in begin() :";
	// ft::list<int> l3(10, 42);
	// std::list<int> l4(10, 42);
	// ft::list<int>::iterator it = l3.begin();
	// std::list<int>::iterator it2 = l4.begin();
	// l3.insert(it, 5);
	// l4.insert(it2, 5);
	// print_list(l4);
	// print_Mylist(l3);
	// it++;
	// it++;
	// it2++;
	// it2++;
	// std::cout << "\ninsert 5 in 4th position";
	// l3.insert(it, 5);
	// l4.insert(it2, 5);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\ninsert three 6 in 4th position";
	// l3.insert(it, (size_t)3, 6);
	// l4.insert(it2, 3, 6);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\ninsert '2 3 4 5' with iterators";
	// l3.insert(it, list2.begin(), list2.end());
	// l4.insert(it2, list1.begin(), list1.end());
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nerase the 12th element";
	// l3.erase(it);
	// l4.erase(it2);
	// print_list(l4);
	// print_Mylist(l3);
	// it = l3.begin();
	// it2 = l4.begin();
	// it++;
	// it++;
	// it2++;
	// it2++;	
	// std::cout << "\nerase all elements after the 2cd";
	// l3.erase(it, l3.end());
	// l4.erase(it2, l4.end());
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nresize(6, 64) :";
	// l3.resize(6, 64);
	// l4.resize(6, 64);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nresize(3, 10) :";
	// l3.resize(3, 10);
	// l4.resize(3, 10);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nremove(42) :";
	// l3.remove(42);
	// l4.remove(42);
	// print_list(l4);
	// print_Mylist(l3);
	// l3.resize(5, 10);
	// l4.resize(5, 10);
	// std::cout << "\nremove_if >9 from :";
	// print_list(l4);
	// print_Mylist(l3);
	// l3.remove_if(sup_nine);
	// l4.remove_if(sup_nine);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nunique from :";
	// l3.resize(5, 10);
	// l4.resize(5, 10);
	// print_list(l4);
	// print_Mylist(l3);
	// l3.unique();
	// l4.unique();
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nunique = from :";
	// l3.resize(5, 8);
	// l4.resize(5, 8);
	// l3.push_back(5);
	// l4.push_back(5);
	// print_list(l4);
	// print_Mylist(l3);
	// l3.unique(same_integral_part);
	// l4.unique(same_integral_part);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nswap with list1 : ";
	// l3.swap(list2);
	// l4.swap(list1);
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nreverse : ";
	// l3.reverse();
	// l4.reverse();
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nsort : ";
	// l3.sort();
	// l4.sort();
	// print_list(l4);
	// print_Mylist(l3);
	// std::cout << "\nmerge : ";
	// l3.merge(list2);
	// l4.merge(list1);
	// print_list(l4);
	// print_Mylist(l3);

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:57:00 by sadarnau          #+#    #+#             */
/*   Updated: 2021/05/27 15:46:32 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>
#include <iostream>

int	main ()
{
	std::list<int>	list1;
	ft::List<int>	list2;

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

	// list1.clear();
	// list2.clear();
	// std::cout << "\nclear :\nsize : std = " << list1.size() << " and mine = " << list2.size() << "\n";
	// std::cout << "front : std = " << list1.front() << " and mine = " << list2.front() << "\n";

	return 0;
}
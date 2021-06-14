/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:47:50 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/14 17:22:21 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>

// void print_Mymap( ft::map<int> &map )
// {
// 	std::cout << "\nMy map :\n";
// 	for (ft::map<int>::iterator it = map.begin(); it != map.end(); it++)
// 	    std::cout << *it << ' ';
// }

// template<typename T>
// void print_map( std::map<T> map )
// {
// 	std::cout << "\nSTD map :\n";
// 	for (typename std::map<T>::iterator it = map.begin(); it != map.end(); it++)
// 	    std::cout << *it << ' ';
// }

int	main ()
{
	ft::map<int, int> m;

	std::cout << "insert(1,10) : bool = ";
	std::cout << m.insert(std::make_pair(1, 10)).second << "\n";
	std::cout << "insert(1,15) : bool = ";
	std::cout << m.insert(std::make_pair(1, 15)).second << "\n";
	std::cout << "insert(15, 150) : bool = ";
	std::cout << m.insert(std::make_pair(15, 150)).second << "\n";
	std::cout << "insert(20, 200) : bool = ";
	std::cout << m.insert(std::make_pair(20, 200)).second << "\n";
	std::cout << "find(1) : second = ";
	std::cout << m.find(1).node()->pair.second << "\n";
	std::cout << "find(14) : second = ";
	std::cout << m.find(14).node()->pair.second << "\n";
	std::cout << "find(15) : second = ";
	std::cout << m.find(15).node()->pair.second << "\n";

	std::cout << "\nIn the tree we have : \n";
	m.printTree();
	std::cout << "\n";

	std::cout << "begin() = " << m.begin().node()->pair.first << " : " << m.begin().node()->pair.second << "\n";
	std::cout << "end() - 1 = " << m.end().node()->parent->pair.first << " : " << m.end().node()->parent->pair.second << "\n\n";

	std::cout << "insert(begin(), (2, 20))\n";
	m.insert(m.begin() ,std::make_pair(2, 20));
	std::cout << "insert(end(), (13, 130))\n";
	m.insert(m.end(), std::make_pair(13, 130));

	std::cout << "\nIn the tree we have : \n";
	m.printTree();
	std::cout << "\n";
	
	std::cout << "insert(0, 1))\n";
	m.insert(std::make_pair(0, 1));
	std::cout << "\nIn the tree we have : \n";
	m.printTree();
	std::cout << "\n";
	std::cout << "erase(1)\n";
	m.erase(m.find(1));
	std::cout << "\nIn the tree we have : \n";
	m.printTree();
	std::cout << "\n";
	std::cout << "end() - 1 = " << m.end().node()->parent->pair.first << " : " << m.end().node()->parent->pair.second << "\n\n";
	std::cout << "begin() = " << m.begin().node()->pair.first << " : " << m.begin().node()->pair.second << "\n";
	return 0;
}
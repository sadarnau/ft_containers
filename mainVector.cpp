/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:57:00 by sadarnau          #+#    #+#             */
/*   Updated: 2021/06/07 17:55:53 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

// template<typename T>
// void print_Myvector( ft::vector<T> vector )
// {
// 	std::cout << "My vector :\n";
// 	for (typename ft::vector<T>::iterator it = vector.begin(); it != vector.end(); ++it)
// 	    std::cout << *it << ' ';
// }

void print_Myvector( ft::vector<int> &vector )
{
	std::cout << "\nMy vector :\n";
	for (ft::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	    std::cout << *it << ' ';
}

template<typename T>
void print_vector( std::vector<T> vector )
{
	std::cout << "\nSTD vector :\n";
	for (typename std::vector<T>::iterator it = vector.begin(); it != vector.end(); it++)
	    std::cout << *it << ' ';
}

int	main ()
{
	std::vector<int>	vector1;
	ft::vector<int>		vector2;

	std::cout << "\nempty : std = " << vector1.empty() << " and mine = " << vector2.empty() << "\n";
	vector1.push_back(1);
	vector2.push_back(1);
	std::cout << "\npush back(1) :\nempty : std = " << vector1.empty() << " and mine = " << vector2.empty() << "\n";
	std::cout << "size : std = " << vector1.size() << " and mine = " << vector2.size() << "\n";
	std::cout << "capacity : std = " << vector1.capacity() << " and mine = " << vector2.capacity() << "\n";
	std::cout << "max_size : std = " << vector1.max_size() << " and mine = " << vector2.max_size();
	print_vector(vector1);
	print_Myvector(vector2);
	vector1.push_back(2);
	vector2.push_back(2);
	vector1.push_back(3);
	vector2.push_back(3);
	vector1.push_back(4);
	vector2.push_back(4);
	vector1.push_back(5);
	vector2.push_back(5);
	std::cout << "\n\npush_back 1 to 5 :\nsize : std = " << vector1.size() << " and mine = " << vector2.size() << "\n";
	std::cout << "capacity : std = " << vector1.capacity() << " and mine = " << vector2.capacity() << "\n";
	std::cout << "max_size : std = " << vector1.max_size() << " and mine = " << vector2.max_size() << "\n";

	std::cout << "\n\nvectorbis(begin+1, end) :";
	std::vector<int>	vector1bis(vector1.begin() + 1, vector1.end());
	ft::vector<int>		vector2bis(vector2.begin() + 1, vector2.end());
	print_vector(vector1bis);
	print_Myvector(vector2bis);

	std::cout << "\n\nassign (begin, begin + 3) :";
	vector1bis.assign(vector1.begin(), vector1.begin() + 3);
	vector2bis.assign(vector2.begin(), vector2.begin() + 3);
	print_vector(vector1bis);
	print_Myvector(vector2bis);

	std::cout << "\n\nassign (5, 21) in vectorbis:";
	vector1bis.assign(5, 21);
	vector2bis.assign((size_t)5, 21);
	print_vector(vector1bis);
	print_Myvector(vector2bis);

	std::cout << "\n\nerase begin in vectorbis :";
	vector1bis.erase(vector1bis.begin());
	vector2bis.erase(vector2bis.begin());
	print_vector(vector1bis);
	print_Myvector(vector2bis);

	std::cout << "\n\nerase (begin + 1, end - 2) in vector :";
	vector1.erase(vector1.begin() + 1, vector1.end() - 2);
	vector2.erase(vector2.begin() + 1, vector2.end() - 2);
	print_vector(vector1);
	print_Myvector(vector2);

	std::cout << "\n\nat(2) in vector : std = " << vector1.at(2) << " and mine = " << vector2.at(2);

	std::cout << "\n\nvectorbis = vector :";
	vector1bis = vector1;
	vector2bis = vector2;
	print_vector(vector1bis);
	print_Myvector(vector2bis);

	std::cout << "\n\nnewVector(10, 42) :";
	std::vector<int>	vector3(10, 42);
	ft::vector<int>		vector4((size_t)10, 42);
	print_vector(vector3);
	print_Myvector(vector4);

	std::cout << "\n\nresize(2) in NewVector :";
	vector3.resize(2, 10);
	vector4.resize(2, 10);
	print_vector(vector3);
	print_Myvector(vector4);

	std::cout << "\n\nresize(5, 14) in NewVector :";
	vector3.resize(5, 14);
	vector4.resize(5, 14);
	print_vector(vector3);
	print_Myvector(vector4);

	std::cout << "\n\ninsert(begin + 1, 21) in NewVector :";
	vector3.insert(vector3.begin() + 1, 3, 21);
	vector4.insert(vector4.begin() + 1, (size_t)3, 21);
	print_vector(vector3);
	print_Myvector(vector4);

	std::cout << "\n\ninsert(end - 3, 5) in NewVector :";
	vector3.insert(vector3.end() - 3, 5);
	vector4.insert(vector4.end() - 3, 5);
	print_vector(vector3);
	print_Myvector(vector4);

	std::cout << "\n\ninsert(begin, vector.begin, vector. begin + 2) in NewVector :";
	vector3.insert(vector3.begin(), vector1.begin(), vector1.begin() + 2);
	vector4.insert(vector4.begin(), vector2.begin(), vector2.begin() + 2);
	print_vector(vector3);
	print_Myvector(vector4);

	std::cout << "\n\nswap NewVector and vector:";
	vector3.swap(vector1);
	vector4.swap(vector2);
	print_vector(vector3);
	print_Myvector(vector4);

	return 0;
}

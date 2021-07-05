/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainQueue.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:50:02 by sadarnau          #+#    #+#             */
/*   Updated: 2021/07/05 11:17:58 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"
#include <queue>
#include <iostream>

int main(void)
{
	ft::queue<int> myqueue;
	std::queue<int> queue;

	std::cout << "\nempty ? : std = " << queue.empty() << " and mine = " << myqueue.empty() << "\n";
	std::cout << "size : std = " << queue.size() << " and mine = " << myqueue.size() << "\n";

	myqueue.push(21);
	queue.push(21);
	std::cout << "\npush(21)\nempty : std = " << queue.empty() << " and mine = " << myqueue.empty() << "\n";
	std::cout << "size : std = " << queue.size() << " and mine = " << myqueue.size() << "\n";
	std::cout << "back : std = " << queue.back() << " and mine = " << myqueue.back() << "\n";
	std::cout << "front : std = " << queue.front() << " and mine = " << myqueue.front() << "\n";
	
	myqueue.push(42);
	queue.push(42);
	std::cout << "\npush(42)\nempty : std = " << queue.empty() << " and mine = " << myqueue.empty() << "\n";
	std::cout << "size : std = " << queue.size() << " and mine = " << myqueue.size() << "\n";
	std::cout << "back : std = " << queue.back() << " and mine = " << myqueue.back() << "\n";
	std::cout << "front : std = " << queue.front() << " and mine = " << myqueue.front() << "\n";

	myqueue.pop();
	queue.pop();
	std::cout << "\npop\nempty : std = " << queue.empty() << " and mine = " << myqueue.empty() << "\n";
	std::cout << "size : std = " << queue.size() << " and mine = " << myqueue.size() << "\n";
	std::cout << "back : std = " << queue.back() << " and mine = " << myqueue.back() << "\n";
	std::cout << "front : std = " << queue.front() << " and mine = " << myqueue.front() << "\n";

	myqueue.push(1);
	queue.push(1);
	myqueue.push(2);
	queue.push(2);
	myqueue.push(3);
	queue.push(3);

	std::cout << "\npush 1 2 3" << std::endl;
	std::cout << "mine 2 = mine";
	ft::queue<int>	myqueue2 = myqueue;
	std::queue<int>	queue2 = queue;
	std::cout << "\nempty : std = " << queue2.empty() << " and mine = " << myqueue2.empty() << "\n";
	std::cout << "size : std = " << queue2.size() << " and mine = " << myqueue2.size() << "\n";
	std::cout << "back : std = " << queue2.back() << " and mine = " << myqueue2.back() << "\n";
	std::cout << "front : std = " << queue2.front() << " and mine = " << myqueue2.front() << "\n";


	std::cout << "\nmyqueue2 == myqueue ? : " << (myqueue2 == myqueue) << std::endl;
	myqueue2.push(121);
	std::cout << "push(121) in myqueue2" << std::endl;
	std::cout << "myqueue2 == myqueue ? : " << (myqueue2 == myqueue) << std::endl;
}
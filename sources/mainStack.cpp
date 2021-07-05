/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainStack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:17:51 by sadarnau          #+#    #+#             */
/*   Updated: 2021/07/05 11:19:01 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include <iostream>

int main(void)
{
	ft::stack<int> mystack;
	std::stack<int> stack;

	std::cout << "\nempty ? : std = " << stack.empty() << " and mine = " << mystack.empty() << "\n";
	std::cout << "size : std = " << stack.size() << " and mine = " << mystack.size() << "\n";

	mystack.push(21);
	stack.push(21);
	std::cout << "\npush(21)\nempty : std = " << stack.empty() << " and mine = " << mystack.empty() << "\n";
	std::cout << "size : std = " << stack.size() << " and mine = " << mystack.size() << "\n";
	std::cout << "top : std = " << stack.top() << " and mine = " << mystack.top() << "\n";
	
	mystack.push(42);
	stack.push(42);
	std::cout << "\npush(42)\nempty : std = " << stack.empty() << " and mine = " << mystack.empty() << "\n";
	std::cout << "size : std = " << stack.size() << " and mine = " << mystack.size() << "\n";
	std::cout << "top : std = " << stack.top() << " and mine = " << mystack.top() << "\n";

	mystack.pop();
	stack.pop();
	std::cout << "\npop\nempty : std = " << stack.empty() << " and mine = " << mystack.empty() << "\n";
	std::cout << "size : std = " << stack.size() << " and mine = " << mystack.size() << "\n";
	std::cout << "top : std = " << stack.top() << " and mine = " << mystack.top() << "\n";

	mystack.push(1);
	stack.push(1);
	mystack.push(2);
	stack.push(2);
	mystack.push(3);
	stack.push(3);

	std::cout << "\npush 1 2 3" << std::endl;
	std::cout << "mine 2 = mine";
	ft::stack<int>	mystack2 = mystack;
	std::stack<int>	stack2 = stack;
	std::cout << "\nempty : std = " << stack2.empty() << " and mine = " << mystack2.empty() << "\n";
	std::cout << "size : std = " << stack2.size() << " and mine = " << mystack2.size() << "\n";
	std::cout << "top : std = " << stack2.top() << " and mine = " << mystack2.top() << "\n";

	std::cout << "\nmystack2 == mystack ? : " << (mystack2 == mystack) << std::endl;
	mystack2.push(121);
	std::cout << "push(121) in mystack2" << std::endl;
	std::cout << "mystack2 == mystack ? : " << (mystack2 == mystack) << std::endl;
}
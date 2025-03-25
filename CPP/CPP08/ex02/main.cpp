/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:52:45 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/25 18:59:45 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "---------------------------- MUTANTSTACK ---------------------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top :"<< mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size :" << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "value :" << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "------------------------------- LIST ------------------------------" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top :"<< mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "size :" << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "value :" << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
        std::cout << "===== Testing MutantStack =====" << std::endl;
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        // Test des itérateurs
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        std::cout << "Elements: ";
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
        
        // Test avec const_iterator
        const MutantStack<int> cmstack(mstack);
        MutantStack<int>::const_iterator cit = cmstack.begin();
        MutantStack<int>::const_iterator cite = cmstack.end();
        
        std::cout << "Const elements: ";
        while (cit != cite) {
            std::cout << *cit << " ";
            ++cit;
        }
        std::cout << std::endl;
        
        // Test avec reverse_iterator
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        
        std::cout << "Reverse elements: ";
        while (rit != rite) {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }
    
    // Test équivalent avec std::list
    {
        std::cout << "\n===== Testing std::list (comparison) =====" << std::endl;
        std::list<int> llist;
        
        llist.push_back(5);
        llist.push_back(17);
        
        std::cout << "Top: " << llist.back() << std::endl;
        llist.pop_back();
        std::cout << "Size: " << llist.size() << std::endl;
        
        llist.push_back(3);
        llist.push_back(5);
        llist.push_back(737);
        llist.push_back(0);
        
        // Test des itérateurs
        std::list<int>::iterator it = llist.begin();
        std::list<int>::iterator ite = llist.end();
        
        ++it;
        --it;
        
        std::cout << "Elements: ";
        while (it != ite) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
        
        // Test avec const_iterator
        const std::list<int> cllist(llist);
        std::list<int>::const_iterator cit = cllist.begin();
        std::list<int>::const_iterator cite = cllist.end();
        
        std::cout << "Const elements: ";
        while (cit != cite) {
            std::cout << *cit << " ";
            ++cit;
        }
        std::cout << std::endl;
        
        // Test avec reverse_iterator
        std::list<int>::reverse_iterator rit = llist.rbegin();
        std::list<int>::reverse_iterator rite = llist.rend();
        
        std::cout << "Reverse elements: ";
        while (rit != rite) {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
	}
	return 0;
}

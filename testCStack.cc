/**
 * @author Tyler Justinen-Teite tyler.justinenteite@uleth.ca
 * @date 02/04/2020
 * 
 * Assignment 6 CPSC 2620
*/

// User Defined
#include "CStack.h"
// I/O
#include <iostream>

bool isBallanced(const std::string& toCheck);

int main()
{
    /**
        Checking CStack for int
    */
    CStack<int> myStack;
    int i = 0;
    std::cout << "Pushing 0 - 99 into Stack 1\n\n";
    while (myStack.size() < 100)
    {
        myStack.push(i++);
        std::cout << myStack.top() << std::endl;
    }
    /**
        Checking CStack for assignment operator (calls copy constructor)
    */
    CStack<int> ourStack;
    
    ourStack = myStack;
    std::cout << "\n\nStack 2 = Stack 1\nReverse Iteration Stack 2\n\n";

    while (!ourStack.isEmpty())
    {
        std::cout << ourStack.top() << std::endl;
        ourStack.pop();
    }

    /**
        Checking character via bracked checker
    */
    // Add 50 Opening Brackets, then 50 Closing Brackets
    std::string testBracket;
    for (int i = 0; i < 50; i++)
        testBracket.append("(");
    for (int i = 0; i < 50; i++)
        testBracket.append(")");

    std::cout << isBallanced(testBracket) << std::endl;

	return 0;
}

bool isBallanced(const std::string& toCheck)
{
    CStack<char> tempStack;
    for (auto c : toCheck)
    {
        switch (c)
        {
        case '(':
            tempStack.push(c);
            break;
        case ')': 
            tempStack.pop();
            break;
        }
    }
    return tempStack.isEmpty();
}
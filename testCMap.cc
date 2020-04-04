/**
* @author Tyler Justinen-Teite tyler.justinenteite@uleth.ca
* @date 02/04/2020
* 
* Assignment 6 CPSC 2620
*/

// User Defined
#include "CMap.h"
// I/O
#include <iostream>


int main()
{
	CMap<int, int>* myMap = new CMap<int, int>;


	for (int i = 0; i < 100; i++)
		(*myMap)[i] = i + 1;
	
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			(*myMap)[i] = 9999;
//		std::cout << "Map[" << i << "]: " << (*myMap)[i] << std::endl;
	}

//	delete myMap;

	std::cout << "\n\n" << (*myMap)[0] << std::endl;

	return 0;
}
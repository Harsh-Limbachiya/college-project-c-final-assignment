/* ------------------------------------------------------
Final project Milestone 2
Filename: main.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-20
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include <iostream>
#include "AidMan.h"
#include "Utils.h"
int main()
{
	std::cout << "Enter the following:\nabc\n1\n2\n3\n4\n5\n6\n7\n8\n0\n--------\n";
	sdds::ut.testMode();
	sdds::AidMan().run();
	return 0;
}
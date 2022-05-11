/* ------------------------------------------------------
Final project Milestone 2
Filename: Menu.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-20
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef _MENU_H_
#define _MENU_H_
#pragma once
#include"Utils.h"

namespace sdds
{
	const int MaxMenuOption = 15;
	class Menu
	{
		char* m_options{};
		unsigned int m_number{};
		void safeEmpty();
	public:
		bool validateMenu(const char*, int);
		Menu(const char*, int);
		Menu(const Menu&);
		Menu& operator=(const Menu&);
		unsigned run();
		~Menu();
	};
	
}

#endif // !_MENU_H_



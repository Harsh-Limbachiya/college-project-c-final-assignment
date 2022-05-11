/* ------------------------------------------------------
Final project Milestone 2
Filename: AidMan.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-20
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef _AIDMAN_H_
#define _AIDMAN_H_
#pragma once
#include "Menu.h"
#include "Date.h"
namespace sdds
{
	class AidMan
	{
		char* m_fileName{};
		Menu m_menu{"1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7};
		unsigned menu();
	public :
		AidMan();
		//AidMan(const AidMan&);
		//AidMan& operator= (const AidMan&);
		void run();
		~AidMan();
	};
}

#endif // !_AIDMAN_H_

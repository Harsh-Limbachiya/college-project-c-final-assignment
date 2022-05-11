/* ------------------------------------------------------
Final project Milestone 4
Filename: Perishable.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-05
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef _PERSIHABLE_H_
#define _PERISHABLE_H_
#pragma once
#include "Date.h"
#include "Item.h"
#include "iProduct.h"
namespace sdds
{
	class Perishable : public Item
	{
		Date m_date{};
		char* m_handling{};
	public :
		//constructor
		Perishable();
		//copy constructor
		Perishable(const Perishable&);
		//Assignment Operator
		Perishable& operator=(const Perishable&);
		//deallocator
		~Perishable();
		//expiry method
		const Date& expiry();
		//save method override
		std::ofstream& save(std::ofstream& ofstr)const;
		// loads method override
		std::ifstream& load(std::ifstream& ifstr);
		//display method override
		std::ostream& display(std::ostream& ostr)const;
		//read sku method override
		int readSku(std::istream& istr);
		//read method override
		std::istream& read(std::istream& istr);
	};
	
}

#endif // !_PERSIHABLE_H_


/* ------------------------------------------------------
Final project Milestone 3
Filename: Item.h
Name : Harsh Vishnu Limbachiya
Email id : Hvlimbachiya@myseneca.ca
Date : 2022-04-03
---------------------------------------------------------- - */

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Utils.h"
#include "Status.h"
#include"iProduct.h"
#ifndef _Item_h_
#define _Item_ h_
#pragma once

namespace sdds
{
	class Item : public iProduct
	{
		char* m_description{};
		bool m_linear{};
		double m_price{};
		int m_qty{};
		int m_qtyNeeded{};
	protected:
		Status m_state;
		int m_sku{};
		//returns the linear flag of the Item
		bool linear();
	public:

		//constructor
		Item();
		//copy constructor
		Item(const Item&);
		//copy assignment operator 
		Item& operator=(const Item&);
		//deallocator 
		~Item();
		//returns the needed-quantity
		int qtyNeeded()const;
		//return the on hand quantity
		int qty()const;
		//return the price
		operator double()const;
		//return the state of object
		operator bool()const;
		// to reduce the quantity on hand
		virtual int operator-=(int qty);
		// to increase the quantity on hand
		virtual int operator+=(int qty);
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		void linear(bool isLinear);
		//public method clear 
		void clear();
		//returns true if the SKU attribute matches the received value
		bool operator==(int sku)const;
		//If a match was found in string it returns true.
		bool operator==(const char* description)const;
		//save method
		 std::ofstream& save(std::ofstream& ofstr)const;
		// loads an iProduct from a file
	     std::ifstream& load(std::ifstream& ifstr);
		 //display 
		 std::ostream& display(std::ostream& ostr)const;
		 //read sku method 
		 int readSku(std::istream& istr);
		 //read method
		 std::istream& read(std::istream& istr);
	};
	
}
#endif // !_Item_h_


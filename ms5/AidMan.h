/* ------------------------------------------------------
Final project Milestone 5 Part 6
Filename: AidMan.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-12
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef _AIDMAN_H_
#define _AIDMAN_H_
#pragma once

#include "Menu.h"
#include "Date.h"
#include "iProduct.h"
#include "Perishable.h"
#include "Item.h"
namespace sdds
{
	const int sdds_max_num_items = 100;
	class AidMan 
	{	
		iProduct* m_product[sdds_max_num_items]{}; 
		int m_ProdNumber{};
		char* m_fileName{};
		Menu m_menu;
		unsigned menu() const;
		//save method
		void save();
		//deallocate method
		void deallocate();
		//load method
		bool load();
		//list method
		int list(const char* sub_desc = nullptr);
		//search method
		int search(int sku) const;
		//addItem Method
		void addItem();
		//REMOVE METHOD
		void remove(int index);
		//REMOVE ITEM
		void removeItem();
		//UPDATE ITEM
		void updateItem();
		//Sort Item
		void sort();
		//ship Item
		void shipItems();
	public:
		AidMan() : m_menu("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7 ) {};
		AidMan(const AidMan&) = delete;
		AidMan& operator= (const AidMan&) = delete;
		void run();
		~AidMan();
	};
}

#endif // !_AIDMAN_H_

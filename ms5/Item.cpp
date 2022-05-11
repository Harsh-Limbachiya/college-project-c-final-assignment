
/* ------------------------------------------------------
Final project Milestone 5 PART 6
Filename: Item.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-12
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstring>
#include "Item.h"
using namespace std;
namespace sdds
{
	//returns the linear flag of the Item
	bool Item::linear() const
	{
		return m_linear;
	}
	//constructor
	Item::Item()
	{

	}
	//copy constructor
	Item::Item(const Item& item)
	{
		*this = item;
	}
	//copy assignment operator 
	Item& Item::operator=(const Item& item)
	{
		if (this != &item)
		{
			if (item.m_description != nullptr)
			{
				delete[] m_description;
				m_description = new char[strlen(item.m_description) + 1];
				strcpy(m_description, item.m_description);
			}
			else
			{
				m_description = nullptr;
			}
			m_linear = item.m_linear;
			m_price = item.m_price;
			m_qty = item.m_qty;
			m_qtyNeeded = item.m_qtyNeeded;
			m_sku = item.m_sku;
			m_state = item.m_state;
		}
		return *this;
	}
	//deallocator
	Item::~Item()
	{
		delete[] m_description;
	}
	//returns the needed-quantity
	int Item::qtyNeeded() const
	{
		return m_qtyNeeded;
	}
	//return the on hand quantity
	int Item::qty() const
	{
		return m_qty;
	}
	//return the price
	Item::operator double() const
	{
		return m_price;
	}
	//return the state of object
	Item::operator bool() const
	{
		return m_state && m_sku > 0;
	}
	// to reduce the quantity on hand
	int Item::operator-=(int qty)
	{
		if (qty > 0)
		{
			m_qty -= qty;
		}
		return m_qty;
	}
	// to increase the quantity on hand
	int Item::operator+=(int qty)
	{
		if (qty > 0)
		{
			m_qty += qty;
		}
		return m_qty;
	}
	// determines if the iProduct is displayed in a linear format or 
	// descriptive format
	void Item::linear(bool isLinear)
	{
		m_linear = isLinear;
	}
	//public method clear 
	void Item::clear()
	{
		m_state = nullptr;
	}
	//returns true if the SKU attribute matches the received value
	bool Item::operator==(int sku) const
	{
		bool val = false;
		if (m_sku == sku)
		{
			val = true;
		}
		return val;
	}
	//If a match was found in string it returns true.
	bool Item::operator==(const char* description) const
	{
		bool val = false;
		if (strstr(m_description, description) && description != nullptr && m_description != nullptr)
		{
			val = true;
		}
		return val;
	}
	//save method
	std::ofstream& Item::save(std::ofstream& ofstr) const
	{
		if (*this/*m_state*/)//check this
		{
			ofstr << m_sku << "\t" << m_description << "\t" << m_qty << "\t" << m_qtyNeeded << "\t" << fixed << setprecision(2) << m_price;
		}
		return ofstr;
	}
	// loads an iProduct from a file
	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		string str;
		ifstr >> m_sku;
		ifstr.ignore();
		getline(ifstr, str, '\t');
		ifstr >> m_qty;
		ifstr.ignore();
		ifstr >> m_qtyNeeded;
		ifstr.ignore();
		ifstr >> m_price;
		ifstr.ignore();
		if (!ifstr)
		{
			m_state = "Input file stream read failed!";
		}
		delete[] m_description;
		m_description = nullptr;
		m_description = new char[str.length() + 1];
		strcpy(m_description, str.c_str());
		return ifstr;
	}
	//display 
	std::ostream& Item::display(std::ostream& ostr) const
	{
		if (*this)
		{
			if (m_linear)
			{
				char str[1000] = {};
				strcpy(str, m_description);
				ostr << m_sku;
				ostr << " | ";
				ostr.setf(ios::left);
				ostr.fill(' ');
				ostr.width(35);
				str[35] = '\0';
				ostr << str;
				ostr.unsetf(ios::left);
				ostr << " " << "| ";
				ostr.setf(ios::right);
				ostr.width(4);
				ostr.fill(' ');
				ostr << m_qty;
				//ostr.unsetf(ios::right);
				ostr << " " << "| ";
				//ostr.setf(ios::right);
				ostr.width(4);
				ostr.fill(' ');
				ostr << m_qtyNeeded;
				//ostr.unsetf(ios::right);
				ostr << " " << "| ";
				ostr.width(7);
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << m_price;
				ostr.unsetf(ios::right);
				ostr.unsetf(ios::fixed);
				ostr << " |";
			}
			else
			{
				ostr << "AMA Item:" << endl;
				ostr << m_sku;
				ostr << ": ";
				ostr << m_description << endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << m_price << endl;
				ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << m_price * (double(m_qtyNeeded) - (m_qty)) << endl;
				ostr.unsetf(ios::fixed);
			}
		}
		else
		{
			ostr << m_state << endl;
		}

		return ostr;
	}
	//read sku method 
	int Item::readSku(std::istream& istr)
	{
		int value = ut.getInt(40000, 99999, "SKU: ");
		return value;
	}
	//read method
	std::istream& Item::read(std::istream& istr)
	{
		char str[1000];
		delete[] m_description;
		m_state.clear();
		cout << "AMA Item:" << endl;
		m_sku = readSku(istr);
		cout << "Description: ";
		istr.ignore();
		istr.getline(str, 1000, '\n');
		m_description = new char[strlen(str) + 1];
		strcpy(m_description, str);
		m_qtyNeeded = ut.getInt(1, 9999, "Quantity Needed: ");
		m_qty = ut.getInt(0, m_qtyNeeded, "Quantity On Hand: ");
		m_price = ut.getDouble(0.00, 9999.00, "Unit Price: $");
		if (istr.fail())
		{
			m_state = "Console entry failed!";
		}
		return istr;
	}
}

/* ------------------------------------------------------
Final project Milestone 5 Part 6
Filename: iProduct.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-12
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#include<iostream>
#include "iProduct.h"
namespace sdds
{
	//read sku 
	int iProduct::readSku(std::istream& istr)
	{
		return 0;
	}
	// to reduce the quantity on hand
	int iProduct::operator-=(int qty)
	{
		return 0;
	}
	// to increase the quantity on hand
	int iProduct::operator+=(int qty)
	{
		return 0;
	}
	// returns the price of the produce
	iProduct::operator double() const
	{
		return 0.0;
	}
	// returns if the iProduct is in a good states
	iProduct::operator bool() const
	{
		return false;
	}
	// returns the number of products needed
	int iProduct::qtyNeeded() const
	{
		return 0;
	}
	// retuns the quantity on hand
	int iProduct::qty() const
	{
		return 0;
	}

	//insertion operator overload
	std::ostream& operator<<(std::ostream& ostr, const iProduct& iProd)
	{
		iProd.display(ostr);
		return ostr;
	}
	//extraction operator overload
	std::istream& operator>>(std::istream& istr, iProduct& iProd)
	{
		iProd.read(istr);
		return istr;
	}
	//deallocator
	iProduct::~iProduct()
	{
	}
}

/* ------------------------------------------------------
Final project Milestone 4
Filename: Perishable.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-05
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include"Perishable.h"
using namespace std;
namespace sdds
{
	//constructor
	Perishable::Perishable()
	{
	}
	//copy constructor
	Perishable::Perishable(const Perishable& perishableItem) : Item(perishableItem)
	{
		*this = perishableItem;
	}
	//Assignment Operator
	Perishable& Perishable::operator=(const Perishable& perishbaleItem) 
	{
		
		if (this != &perishbaleItem)
		{
			Item::operator=(perishbaleItem);
			if (perishbaleItem.m_handling != nullptr)
			{
				delete[] m_handling;
				m_handling = nullptr;
				m_handling = new char[strlen(perishbaleItem.m_handling) + 1];
				strcpy(m_handling, perishbaleItem.m_handling); 
				m_date = perishbaleItem.m_date;
			}			
		}
		return *this;
	}
	//deallocator
	Perishable::~Perishable()
	{
		delete[] m_handling;
	}
	//expiry method
	const Date& Perishable::expiry()
	{
		return m_date;
	}
	//save method override
	std::ofstream& Perishable::save(std::ofstream& ofstr) const
	{
		if (*this) 
		{
			Item::save(ofstr);
			ofstr << '\t';
			if (m_handling && m_handling[0])
			{
				ofstr << m_handling;
			}
			ofstr << '\t';
			Date expiryDate = m_date;
			expiryDate.formatted(false);
			ofstr << expiryDate;
		}
		return ofstr;
	}
	// loads method override
	std::ifstream& Perishable::load(std::ifstream& ifstr)
	{
		m_state.clear();
		string str ="";
		Item::load(ifstr);
		getline(ifstr, str, '\t');
		ifstr >> m_date;
		ifstr.ignore();
		if (!ifstr)
		{
			Item::m_state = "Input file stream read (perishable) failed!";
		}
		delete[] m_handling;
		m_handling = nullptr;
		m_handling = new char[str.length() + 1];
		strcpy(m_handling, str.c_str());
		return ifstr;
	}
	//display method override
	std::ostream& Perishable::display(std::ostream& ostr) const
	{
		if (*this)
		{
		
			if (linear())
			{
				Item::display(ostr);
				if (m_handling != nullptr && strlen(m_handling) != 0)
				{
					ostr << "*";
				}
				else
				{
					ostr << " ";
				}
				ostr << m_date;
			}
			else
			{
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				ostr << m_date << endl;
				if (m_handling != nullptr && strlen(m_handling) != 0)
				{
					ostr << "Handling Instructions: ";
					ostr << m_handling << endl;
				}
			}
		}
		else
		{
			ostr << m_state << endl;
		}
		
		return ostr;
	}
	//readsku method override
	int Perishable::readSku(std::istream& istr)
	{
		int value = ut.getInt(10000, 39999, "SKU: ");
		return value;
	}

	std::istream& Perishable::read(std::istream& istr)
	{
		Item::read(istr);
		delete[] m_handling;
		char str_Handling[100];
		cout << "Expiry date (YYMMDD): ";
		istr >>  m_date;
		istr.ignore();
		cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() != '\n')
		{
			istr.getline(str_Handling , 100, '\n');
			m_handling = new char[strlen(str_Handling) + 1];
			strcpy(m_handling, str_Handling);
		}
		if (istr.fail())
		{
			Item::m_state = "Perishable console date entry failed!";
		}

		return istr;
	}

}
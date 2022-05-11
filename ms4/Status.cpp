/* ------------------------------------------------------
Final project Milestone 4
Filename: Status.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-05
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Utils.h"
#include "Status.h"
using namespace std;
namespace sdds
{
	//safe empty 
	void Status::safeEmpty()
	{
		delete[] m_description;
		m_description = nullptr;
		m_code = 0;
	};
	//constructor
	Status::Status(char* desc, int code)
	{
		//ut.alloCopy(m_description, desc);
		if (desc != nullptr)
		{
			delete[] m_description;
			m_description = nullptr;
			m_description = new char[strlen(desc) + 1];
			strcpy(m_description, desc);
		}
		else
		{
			m_description = nullptr;
		}
		m_code = code;
	};
	//type conversion
	Status::operator int() const
	{
		return m_code;
	};
	//type conversin
	Status::operator char* () const
	{
		return m_description;
	};
	//type conversion 
	Status::operator bool() const
	{
		return m_description == nullptr;
	};
	//operator overloading with integer
	Status& Status::operator=(int code)
	{
		m_code = code;
		return *this;
	};
	//operator overloading with Cstring
	Status& Status::operator=(const char* string)
	{
		if (ut.valid(string))
		{
			delete[] m_description;
			m_description = new char[strlen(string) + 1];
			strcpy(m_description, string);
		}
		return *this;
	};
	//copy constructor 
	Status::Status(const Status& state)
	{
		*this = state;
	};
	// copy assignment operator 
	Status& Status::operator=(const Status& status)
	{
		if (this != &status)
		{
			if (ut.valid(status.m_description))
			{
				delete[] m_description;
				m_description = nullptr;
				m_description = new char[strlen(status.m_description) + 1];
				strcpy(m_description, status.m_description);
			}
			m_code = status.m_code;
		}

		return *this;
	}
	//clear method
	Status& Status::clear()
	{
		delete[] m_description;
		m_description = nullptr;
		m_code = 0;
		return *this;
	};
	//destructor
	Status::~Status()
	{
		delete[] m_description;
	}
	//print method
	std::ostream& Status::print(std::ostream& ostr) const
	{
		if (*this)
		{
			if (m_code != 0)
			{
				ostr << "ERR#" << m_code << ": ";
			}
			ostr << m_description;
		}		
		return ostr;
	};
	//insertion operator 
	std::ostream& operator<<(std::ostream& ostr, const Status& state)
	{
		return state.print(ostr);
	};


}


/* ------------------------------------------------------
Final project Milestone 1
Filename: Status.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-16
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
			ut.alloCopy(m_description, desc);
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
		bool val = true;
		if (m_description != nullptr)
		{
			val = false;
		}
		return val;
	};
	//operator overloading with integer
	int Status::operator=(int code)
	{
		m_code = code;
		return m_code;
	};
	//operator overloading with Cstring
	char& Status::operator=(const char* string)
	{
		if (ut.valid(string))
		{
			delete[] m_description;
			m_description = new char[strlen(string) + 1];
			strcpy(m_description, string);
		}
		return *this->m_description;
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
				m_description = new char[strlen(status.m_description) + 1];
				strcpy(m_description, status.m_description);
				m_code = status.m_code;  
			}
			
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
		m_description  = nullptr;
	}
	//print method
	std::ostream& Status::print(std::ostream& ostr) const
	{
		if (m_code != 0)
		{
			ostr << "ERR#" << m_code << ": ";
		}
		ostr << m_description;

		return ostr;
	}
	;
	//insertion operator 
	std::ostream& operator<<(std::ostream& ostr, const Status& state)
	{
			if (state.m_description != nullptr)
			{
				state.print(ostr);
			}
		return ostr;
	};


}
	

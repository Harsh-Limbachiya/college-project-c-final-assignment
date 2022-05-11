
/* ------------------------------------------------------
Final project Milestone 4
Filename: Date.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-05
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include"Date.h"
#include<cstring>
using namespace std;
namespace sdds
{
	//validate
	bool Date::validate()
	{
		bool valStop = false;
		int currYear{ 0 };
		ut.testMode(false);
		ut.getSystemDate(&currYear);

		if ((m_year > Max_Year || m_year < currYear) && m_month != 0)
		{
			valStop = true;
			m_state = "Invalid year in date";
			m_state = 1;
		}
		if (!valStop && (m_month < 1 || m_month > 12))
		{
			valStop = true;
			m_state = "Invalid month in date";
			m_state = 2;
		}
		if (!valStop && (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)))
		{
			valStop = true;
			m_state = "Invalid day in date";
			m_state = 3;
		}
		if (!valStop)
			m_state.clear();

		return valStop;
	}
	//unique
	int Date::unique(int year, int month, int day)
	{
		int first;
		first = year * 372 + month * 31 + day;
		return first;
	}
	Date::Date()
	{
		ut.getSystemDate(&m_year, &m_month, &m_day);
	}
	//constructor
	Date::Date(int year, int month, int day)
	{
			m_day = day;
			m_month = month;
			m_year = year;
			validate();
	}
	//operator to check two dates are equal 
	bool Date::operator==(const Date& date)
	{
		bool res = false;
		int first = unique(m_year, m_month, m_day);
		int sec = unique(date.m_year, date.m_month, date.m_day);
		if (first == sec)
		{
			res = true;
		}
		return res;
	}
	//operator to check two dates are not equal 
	bool Date::operator!=(const Date& date)
	{
		bool res = false;
		int first = unique(m_year, m_month, m_day);
		int sec = unique(date.m_year, date.m_month, date.m_day);
		if (first != sec)
		{
			res = true;
		}
		return res;
	}
	//operator to check one date is less than other date
	bool Date::operator<(const Date& date)
	{
		bool res = false;
		int first = unique(m_year, m_month, m_day);
		int sec = unique(date.m_year, date.m_month, date.m_day);
		if (first < sec)
		{
			res = true;
		}
		return res;
	}
	//operator to check one date is greater than other date
	bool Date::operator>(const Date& date)
	{
		bool res = false;
		int first = unique(m_year, m_month, m_day);
		int sec = unique(date.m_year, date.m_month, date.m_day);
		if (first > sec)
		{
			res = true;
		}
		return res;
	}
	//operator to check one date is less than equal to other date
	bool Date::operator<=(const Date& date)
	{
		bool res = false;
		int first = unique(m_year, m_month, m_day);
		int sec = unique(date.m_year, date.m_month, date.m_day);
		if (first <= sec)
		{
			res = true;
		}
		return res;
	}
	//operator to check one date is greater than other date
	bool Date::operator>=(const Date& date)
	{
		bool res = false;
		int first = unique(m_year, m_month, m_day);
		int sec = unique(date.m_year, date.m_month, date.m_day);
		if (first >= sec)
		{
			res = true;
		}
		return res;
	}
	//accessor method
	const Status& Date::state()
	{
		return m_state;
	}
	//formatted modifier 
	Date& Date::formatted(bool val)
	{
		m_formatted = val;
		return *this;
	}
	//bool conversion operator
	Date::operator bool()const
	{
		return m_state.operator bool();
	}
	//write method
	ostream& Date::write(ostream& ostr) const
	{
		if (*this)
		{
			if (m_formatted)
			{
				ostr << m_year << "/";
				ostr.width(2);
				ostr.fill('0');
				ostr << m_month << "/";
				ostr << m_day;
			}
			else
			{
				ostr << m_year - 2000;
				ostr.width(2);
				ostr.fill('0');
				ostr << m_month;
				ostr << m_day;
			}
		}
		return ostr;
	}
	//read method
	istream& Date::read(istream& istr)
	{

		std::string result;
		bool failed{ false };
		istr >> result;
		m_state = 0;
		m_state = "Invalid date value";
		if (atoi(result.c_str()) == 0 || strlen(result.c_str()) > 6)
			failed = true;
		if (!failed)
		{
			m_state.clear();
			if (strlen(result.c_str()) == 4)
			{
				m_month = atoi((result.substr(0, 2)).c_str());
				m_day = atoi((result.substr(2, 2)).c_str());
				ut.testMode(false);
				ut.getSystemDate(&m_year);
			}

			else
			{
				if (strlen(result.c_str()) < 6)
					result += "000000";
				m_year = atoi((result.substr(0, 2)).c_str()) + 2000;
				m_month = atoi((result.substr(2, 2)).c_str());
				m_day = atoi((result.substr(4, 2)).c_str());
			}
			if (validate())
			{
				failed = true;
			}
		}
		if (failed)
		{
			istr.setstate(std::ios::badbit);
		}

		return istr;
	}
	// insertion operator
	ostream& operator<<(ostream& ostr, const Date& date)
	{
		date.write(ostr);
		return ostr;
	}
	//extraction operator
	istream& operator>>(istream& istr, Date& date)
	{
		 date.read(istr);
		 return istr;
	}

}

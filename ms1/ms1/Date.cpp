
/* ------------------------------------------------------
Final project Milestone 1
Filename: Date.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-16
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include"Date.h"
using namespace std;
namespace sdds
{
	//validate
	bool Date::validate()
	{
		bool res = false;
		if (m_year >= sdds_testYear && m_year <= Max_Year)
		{
			if (m_month >= 1 && m_month <= 12)
			{
				if (m_day >= 1 && m_day <= ut.daysOfMon(m_month, m_year))
				{
					res = true;
					m_state.clear();
				}
				else
				{
					m_state.operator=("Invalid day in date");
					m_state.operator=(3);
				}
			}
			else
			{
				m_state.operator=("Invalid month in date");
				m_state.operator=(2);
			}
		}
		else
		{
			m_state.operator=("Invalid year in date");
			m_state.operator=(1);
		}
			return res;
	}
	//unique
	int Date::unique(int year, int month , int day)
	{
		int first;
		first = year * 372 + month * 31 + day;
		return first;
	}
	//constructor
	Date::Date(int year, int month, int day)
	{
		if (year == 0 && month == 0 && day == 0)
		{
			ut.getSystemDate(&m_year, &m_month, &m_day);
		}
		else
		{
				m_day = day;
				m_month = month;
				m_year = year;
		}
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
		this->m_formatted = val;
		return *this;
	}
	//bool conversion operator
	 Date::operator bool()const
	{
		 
			 return *this->m_state;
	}
	 //write method
	 ostream& Date::write(ostream& ostr) const
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
		 return ostr;
		
	 }
	 //read method
	 istream& Date::read(istream& istr)
	 {
		 int integer;
		 bool check;
		 istr >> integer;
		 
		 if (integer == 0 )
			{
			 cout << "Invalid date value";
		 }
		 else
		 {
			 if (integer > 9 && integer <= 99)
			 {
				 m_day = integer % 100;
				 m_month = integer / 100;
			 }
			 else if (integer > 999 && integer <= 9999)
			 {
				 m_day = integer / 100;
				 m_month = integer % 100;
			 }
			 else if (integer < 1000000)
			 {
				 m_day = integer % 100;
				 m_month = ((integer % 10000) - m_day) / 100;
				 m_year = (integer / 10000) + 2000;
				
			 }

			 check = validate();
			 if(!check)
			 {
				 istr.setstate(std::ios::badbit);
			 }
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
		 return date.read(istr);
	 }
	 
}

/* ------------------------------------------------------
Final project Milestone 2
Filename: Date.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-20
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef _DATE_H_
#define _DATE_H_
#pragma once
#include<iostream>
#include"Status.h"
#include"Utils.h"
namespace sdds
{
	const int Max_Year = 2030;
	class Date
	{
		int m_year;
		int m_month;
		int m_day;
		Status m_state;
		bool m_formatted = true;
		bool validate();                                    //validate
		int unique(int year, int month, int day);			//creates unique value 
	public:
		Date(int year = 0, int month = 0, int day = 0);   //constrcutor
															//operator overloads
		bool operator==(const Date& date);
		bool operator!=(const Date& date);
		bool operator<(const Date& date);
		bool operator>(const Date& date);
		bool operator<=(const Date& date);
		bool operator>=(const Date& date);
		//accessor method
		const Status& state();
		//formatted modifier 
		Date& formatted(bool val);
		//bool conversion operator
		operator bool()const;
		//READ AND WRITE for insertion and extraction
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};
	//insertion and extarction function 
	std::ostream& operator<<(std::ostream& ostr, const Date&);
	std::istream& operator>>(std::istream& istr, Date&);
}
#endif
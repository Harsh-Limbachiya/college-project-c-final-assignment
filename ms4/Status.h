
/* ------------------------------------------------------
Final project Milestone 4
Filename: Status.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-05
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef _STATUS_H_
#define _STATUS_H_
#pragma once
namespace sdds
{
	class Status
	{
		char* m_description{};
		int m_code;
		void safeEmpty();
	public:
		//constructor 
		Status(char* desc = nullptr, int code = 0);
		//type conversion 
		operator int() const;
		operator char* () const;
		operator bool() const;
		//Assignment operator
		Status& operator=(int code);
		Status& operator=(const char*);
		//Rule of three
		Status(const Status& state);
		Status& operator=(const Status& status);
		//clear method
		Status& clear();
		~Status();
		std::ostream& print(std::ostream& ostr)const;
		friend std::ostream& operator<<(std::ostream& ostr, const Status&);
	};


}

#endif



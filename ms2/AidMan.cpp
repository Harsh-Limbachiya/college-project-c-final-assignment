/* ------------------------------------------------------
Final project Milestone 2
Filename: AidMan.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-20
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "AidMan.h"
#include<iostream>
using namespace std;
namespace sdds
{

	unsigned AidMan::menu()
	{
		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << Date() << endl;
		if (m_fileName != nullptr)
		{
			cout << "Data file: " << m_fileName << endl;
		}
		else
		{
			cout << "Data file: " << "No file" << endl;
		}
		cout << "---------------------------------" << endl;
		return m_menu.run();
		
	}

	AidMan::AidMan()
	{
	}

	/*AidMan::AidMan(const AidMan& aidman)
	{
		*this = aidman;
	}*/

	//AidMan& AidMan::operator=(const AidMan& aidman)
	//{
	//	if (this != &aidman)
	//	{
	//		strcpy(m_fileName, aidman.m_fileName);
	//		
	//	}
	//	return *this;
	//}

	void AidMan::run()
	{
		int menuOpt = 0;
		bool flag = false;
		while (flag != true)
		{
			 menuOpt = menu();
			 switch (menuOpt)
			 {
			 case 0:
				 cout << "Exiting Program!" << endl;
				 flag = true;
				 break;
			 case 1:
				 cout << endl;
				 cout << "****List Items****" << endl << endl;
				  break;
			 case 2:
				 cout << endl;
				  cout << "****Add Item****" << endl << endl;
				  break;
			  case 3:
				  cout << endl;
				  cout << "****Remove Item****" << endl << endl;
				  break;
			  case 4:
				  cout << endl;
				  cout << "****Update Quantity****" << endl << endl;
				  break;
			  case 5:
				  cout << endl;
				  cout << "****Sort****" << endl << endl;
				  break;
			  case 6:
				  cout << endl;
				  cout << "****Ship Items****" << endl << endl;
				  break;
			  case 7:
				  cout << endl;
				  cout << "****New/Open Aid Database****" << endl << endl;
				  break;
			 }
		}

	}

	AidMan::~AidMan()
	{
	}

}

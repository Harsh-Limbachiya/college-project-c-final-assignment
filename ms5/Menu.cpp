/* ------------------------------------------------------
Final project Milestone 5 Part 6
Filename: Menu.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-12
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Menu.h"
#include"Utils.h"

using namespace std;
namespace sdds
{
	void Menu::safeEmpty()
	{
		m_options = nullptr;
		m_number = 0;
	}

	bool Menu::validateMenu(const char* option, int number)
	{
		bool res = false;
		if (option != nullptr && number <= MaxMenuOption)
		{
			res = true;
		}
		return res;
	}

	Menu::Menu(const char* options, int number)
	{
		if (validateMenu(options, number))
		{
			delete[] m_options;
			m_options = new char[strlen(options) + 1];
			strcpy(m_options, options);
			m_number = number;
		}
		else
		{
			safeEmpty();
		}
	}

	Menu::Menu(const Menu& menu)
	{
		*this = menu;
	}

	Menu& Menu::operator=(const Menu& menu)
	{
		if (this != &menu)
		{
			if (validateMenu(menu.m_options, menu.m_number))
			{
				delete[] m_options;
				m_options = new char[strlen(menu.m_options) + 1];
				strcpy(m_options, menu.m_options);
				m_number = menu.m_number;
			}
		}
		return *this;
	}

	unsigned Menu::run()const
	{
		int opt = 0;
		cout << m_options;
		cout << "0- Exit" << endl;
		opt =  ut.getInt(0, m_number, "> ");
		return opt;
	}

	Menu::~Menu()
	{
		delete[] m_options;
	}

}


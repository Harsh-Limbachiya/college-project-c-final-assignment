/* ------------------------------------------------------
Final project Milestone 5 Part 6
Filename: AidMan.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-12
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include "AidMan.h"

using namespace std;
namespace sdds
{

	unsigned AidMan::menu() const
	{
		cout << "Aid Management System" << endl;
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
	//save method
	void AidMan::save()
	{
		if (m_fileName != nullptr)
		{
			ofstream ofstr(m_fileName);
			for (int i = 0; i < m_ProdNumber; i++)
			{
				m_product[i]->save(ofstr) << "\n";
			}
			ofstr.close();
		}
	}
	//deallocate method
	void AidMan::deallocate()
	{
		
			for (int i = 0; i < m_ProdNumber; i++)
			{
				delete m_product[i];
				m_product[i] = nullptr;
			}
			delete[] m_fileName;
		    m_fileName = nullptr;
		    m_ProdNumber = 0;
	}
	//load method
	bool AidMan::load()
	{
		int i{};
		Menu yesNo("1- Yes!\n", 1);
		save();
		deallocate();
		cout << "Enter file name: ";
		char fileName[100];
		cin.ignore();
		cin >> fileName;
		delete[] m_fileName;
		m_fileName = nullptr;
		m_fileName = new char[strlen(fileName) + 1];
		strcpy(m_fileName, fileName);
		ifstream fread(m_fileName);
		if (!fread)
		{
			cout << "Failed to open " << m_fileName << " for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			int result = yesNo.run();
			if (result == 1)
			{
				ofstream ofstr(m_fileName);
				ofstr.close();
			}
		}
		else
		{
			while (fread && m_ProdNumber <= sdds_max_num_items)
			{
				
			bool itemCheck{};
				bool perishableCheck{};
				char val = fread.peek();
				int skuInitial = (int)val - 48;
				if (!isdigit(val))
				{
					fread.setstate(std::ios::failbit);
				}
				else
				{
					 if(skuInitial > 0 && skuInitial < 4)
					{
						m_product[i] = new Perishable;
						perishableCheck = true;
					} 
					 else if (skuInitial > 3 && skuInitial < 10)
					{
						m_product[i] = new Item;
						itemCheck = true;
					}

					if (itemCheck || perishableCheck)
					{
						m_product[i]->load(fread);
						i++;
						m_ProdNumber++;
					}
				}
			}
		}
		std::cout << i << " records loaded!\n\n";
		return m_ProdNumber > 0;
	}

	
	void AidMan::run()
	{
		int menuOpt = 0;
		bool flag = false;
		
	
			do
			{
				menuOpt = menu();
				if (menuOpt != 0 && m_fileName == nullptr && menuOpt != 7)
				{
					menuOpt = 7;
				}
				switch (menuOpt)
				{
				case 0:
					save();
					deallocate();
					cout << "Exiting Program!" << endl;
					flag = true;
					break;
				case 1:
					cout << endl;
					cout << "****List Items****" << endl;
					if (m_ProdNumber != 0)
					{
						list(nullptr);
					}
					break;
				case 2:
					cout << endl;
					cout << "****Add Item****" << endl;
					addItem();
					cout << endl;
					break;
				case 3:
					cout << endl;
					cout << "****Remove Item****" << endl;
					removeItem();
					cout << endl;
					break;
				case 4:
					cout << endl;
					cout << "****Update Quantity****" << endl;
					updateItem();
					cout << endl;
					break;
				case 5:
					cout << endl;
					cout << "****Sort****" << endl;
					sort();
					cout << endl;
					break;
				case 6:
					cout << endl;
					cout << "****Ship Items****" << endl;
					shipItems();
					cout << endl;
					break;
				case 7:
					cout << endl;
					cout << "****New/Open Aid Database****\n" ;
					load();
					break;
				}
			} while (flag != true); 
			
	}
	//deallocator
	AidMan::~AidMan()
	{
	}
	//list method
	int AidMan::list(const char* sub_desc)
	{
		int listed = 0;
		if (sub_desc == nullptr)
		{
			if (m_ProdNumber > 0)
			{
				cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
				cout
					<< "-----+-------+-------------------------------------+------+------+---------+-----------\n";
				for (int i = 0; i < m_ProdNumber; i++)
				{
					m_product[i]->linear(true);
					cout.width(4);
					cout.fill(' ');
					cout << listed + 1 << " | ";
					cout << *m_product[i];
					cout << endl;
					listed++;
				}
				cout
					<< "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			}
			else cout << "The list is empty!" << endl;

		}
		else
		{
			if (m_ProdNumber > 0)
			{

				cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
				cout
					<< "-----+-------+-------------------------------------+------+------+---------+-----------\n";
				for (int i = 0; i < m_ProdNumber; i++)
				{
					if (*m_product[i] == sub_desc)
					{
						m_product[i]->linear(true);
						cout.width(4);
						cout.fill(' ');
						cout << listed + 1 << " | ";
						cout << *m_product[i];
						cout << endl;

					}

					listed++;


				}
				std::cout
					<< "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			}
			else
			{
				std::cout << "The list is empty!" << std::endl;

			}

		}
		if (listed && sub_desc == nullptr)
		{
			int number = 0;
			cout << "Enter row number to display details or <ENTER> to continue:\n> ";
			cin.ignore();
			if (cin.peek() != '\n')
			{
				number = ut.getInt(1, listed);
				m_product[number - 1]->linear(false);
				cout << *m_product[number - 1] << endl;
			}
			cout << endl;
		}
		return listed;
	}
	
	//search method
	int AidMan::search(int sku) const
	{
		int val = -1;
		for (int i = 0; i < m_ProdNumber && (val == -1); i++)
		{
			if (*m_product[i] == sku)
			{
				val = i;
			}
		}
		return val;
	}
	void AidMan::addItem()
	{
		if (m_ProdNumber > sdds_max_num_items)
		{
			cout << "Database full!" << endl;
		}
		else
		{
			iProduct* prod{};
			Menu type("1- Perishable\n2- Non-Perishable\n-----------------\n", 2);
			int userEntry = type.run();
			if (userEntry == 1)
			{
				prod = new Perishable;
			}
			else if (userEntry == 2)
			{
				prod = new Item;
			}
			else
			{
				cout << "Aborted\n";
			}

			int val = prod->readSku(cin);
			if (search(val) == -1)
			{
				prod->read(cin);
				if (*prod)
				{
					m_product[m_ProdNumber] = prod;
					m_ProdNumber++;
				}
				else
				{
					cout << *prod;
					delete prod;
				}
			}
			else
			{
				cout << "Sku: " << val << " is already in the system, try updating quantity instead.\n";
				delete prod;
			}
		}
	}

	void AidMan::remove(int index)
	{
		delete m_product[index];
		m_product[index] = nullptr;
		for (int i = index; i < m_ProdNumber; i++)
		{
			m_product[i] = m_product[i + 1];

		}
		m_ProdNumber--;
	}

	void AidMan::removeItem()
	{
		std::string temp;
		int skuval{ 0 };
		std::cout << "Item description: ";
		std::cin.ignore();
		getline(std::cin, temp, '\n');
		list(temp.c_str());
		std::cout << "Enter SKU: ";
		skuval = ut.getInt();
		int found = search(skuval);
		if (found != -1)
		{
			std::cout << "Following item will be removed: \n";
			m_product[found]->linear(false);
			std::cout << *m_product[found];
			std::cout << "\nAre you sure?\n";
			Menu yesNo("1- Yes!\n", 1);
			int result = yesNo.run();
			if (result == 1)
			{
				remove(found);
				std::cout << "Item removed!\n";
			}
			else
			{
				std::cout << "Aborted\n";
			}
		}
		else
		{
			std::cout << "SKU not found!\n";
		}
	}
	//UPDATE ITEM
	void sdds::AidMan::updateItem()
	{
		string temp;
		int sku{ 0 };
		cout << "Item description: ";
		cin.ignore();
		getline(cin, temp, '\n');
		list(temp.c_str());
		cout << "Enter SKU: ";
		sku = ut.getInt();
		int check = search(sku);
		if (check != -1)
		{
			Menu updateOpt("1- Add\n2- Reduce\n", 2);
			int result = updateOpt.run();
			int qnty{ 0 };
			if (result == 1)
			{
				if (m_product[check]->qtyNeeded() != m_product[check]->qty())
				{
					cout << "Quantity to add: ";
					qnty = ut.getInt(1, m_product[check]->qtyNeeded());
					*m_product[check] += qnty;
					cout << qnty << " items added!\n";

				}
				else
				{
					cout << "Quantity Needed already fulfilled!\n";

				}

			}
			else if (result == 2)
			{
				cout << "Quantity to reduce: ";
				qnty = ut.getInt(1, m_product[check]->qty());
				*m_product[check] -= qnty;
				cout << qnty << " items removed!\n";

			}
			else
			{
				cout << "Aborted!\n";
			}

		}
		else
		{
			cout << "SKU not found!\n";
		}
	}
	//sort Item 
	void sdds::AidMan::sort()
	{
		iProduct* tempProd = nullptr;
		for (int i = m_ProdNumber - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if ((m_product[j]->qtyNeeded() - m_product[j]->qty()) < (m_product[j + 1]->qtyNeeded() - m_product[j + 1]->qty()))
				{
					tempProd = m_product[j];
					m_product[j] = m_product[j + 1];
					m_product[j + 1] = tempProd;
				}
			}
		}
		cout << "Sort completed!\n";
	}
	//ship Item
	void sdds::AidMan::shipItems()
	{
		Date date(2022, 3, 31);
		int print{ 0 };
		ofstream fout("shippingOrder.txt");
		fout << "Shipping Order, Date: " << date << endl;
		fout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
		fout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		for (int i = 0; i < m_ProdNumber; i++)
		{

			if (m_product[i]->qty() == m_product[i]->qtyNeeded())
			{
				m_product[i]->linear(true);
				fout.width(4);
				fout.fill(' ');
				fout << print + 1 << " | ";
				fout << *m_product[i];
				fout << endl;
				print++;
				remove(i);
			}
		}
		fout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		cout << "Shipping Order for " << print << " times saved!\n";
	}

}

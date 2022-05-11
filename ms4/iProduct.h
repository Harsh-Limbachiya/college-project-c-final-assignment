
/* ------------------------------------------------------
Final project Milestone 4
Filename: iProduct.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-05
----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef _IPRODUCT_H
#define _IPRODUCT_H
namespace sdds
{

	class iProduct
	{
	public:
		virtual int readSku(std::istream& istr);
		// to reduce the quantity on hand
		virtual int operator-=(int qty);
		// to increase the quantity on hand
		virtual int operator+=(int qty);
		// returns the price of the produce
		virtual operator double()const;
		// returns if the iProduct is in a good state
		virtual operator bool()const;
		// returns the number of products needed
		virtual int qtyNeeded()const;
		// retuns the quantity on hand
		virtual int qty()const;
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		virtual void linear(bool isLinear) = 0;
		// saves the iProduct into a file
		virtual std::ofstream& save(std::ofstream& ofstr)const = 0;
		// loads an iProduct from a file
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
		// displays the iProduct on the screen
		virtual std::ostream& display(std::ostream& ostr)const = 0;
		// reads the iProduct from the console
		virtual std::istream& read(std::istream& istr) = 0;
		// return true if the sku is a match to the iProduct's sku
		virtual bool operator==(int sku)const = 0;
		// rtrns true if the description is found in the iPorduct's description
		virtual bool operator==(const char* description)const = 0;
		virtual ~iProduct(){};
	};
	//insertion operator overload
	std::ostream& operator<<(std::ostream&, const iProduct&);
	//extraction operator overload
	std::istream& operator>>(std::istream&, iProduct&);

}

#endif // !_IPRODUCT_H



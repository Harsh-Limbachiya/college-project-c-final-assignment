/* ------------------------------------------------------
Final project Milestone 3
Filename: Utils.cpp
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-04-03
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include<iomanip>
#include "Utils.h"
using namespace std;
namespace sdds
{
    Utils ut;
    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }
    //allocate and copy  
    void Utils::alloCopy(char* des, const char* src)
    {
        if (ut.valid(src))
        {
            delete[] des;
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
    }
    //check the state validity
    bool Utils::valid(const char* description)
    {
        bool res = false;
        if (description != nullptr)
        {
            res = true;
        }
        return res;
    }
    //get input as integer
    int Utils::getInt(const char* prompt)
    {
        int integer = 0;
        bool valid = false;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        do
        {
            cin >> integer;
            if (cin.fail())
            {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(256, '\n');
            }
            else if (integer >= 0)
            {
                valid = true;
            }
            else
            {
                cout << "Invalid Integer, retry: ";
            }
        } while (!valid);
        return integer;
    }
    
    //get input as integer and validate integer 
    int Utils::getInt(int min, int max, const char* prompt, const char* errMsg)
    {
        int integer;
        bool valid = false;
       // cout << "> ";
        integer = getInt(prompt);
        while (!valid)
        {
            if (integer >= min && integer <= max)
            {
                valid = true;
            }
            else
            {
                if (errMsg != nullptr)
                {
                    cout << errMsg << ", retry: ";
                    cin >> integer;
                }
                else
                {
                    cout << "Value out of range [" << fixed <<  setprecision(2) << min << "<=val<=" << fixed << setprecision(2) << max << "]: ";
                    cin >> integer;
                }
            }
        };
        return integer;
    }

    double Utils::getdouble(const char* prompt)
    {
        double val = 0.0;
        bool valid = false;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        do
        {
            cin >> val;
            if (cin.fail())
            {
                cout << "Invalid number, retry: ";
                cin.clear();
                cin.ignore(256, '\n');
            }
            else if (val >= 0.0)
            {
                valid = true;
            }
            else
            {
                cout << "Invalid number, retry: ";
            }
        } while (!valid);
        return val;
    }
    double Utils::getDouble(double min, double max, const char* prompt, const char* errMsg)
    {
        double val;
        bool valid = false;
        //cout << "> ";
        val = getdouble(prompt);
        while (!valid)
        {
            if (val >= min && val <= max)
            {
                valid = true;
            }
            else
            {
                if (errMsg != nullptr)
                {
                    cout << errMsg << ", retry: " << endl;
                    cin >> val;
                }
                else
                {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                    cin >> val;
                }
            }
        };
        return val;
    }
    //gets the system date 
    void Utils::getSystemDate(int* year, int* mon, int* day)
    {
        if (m_testMode)
        {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    //gets the days of month 
    int Utils::daysOfMon(int month, int year)const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

}
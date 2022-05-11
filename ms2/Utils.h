/* ------------------------------------------------------
Final project Milestone 2
Filename: Utils.h
Name : Harsh Vishnu Limbachiya
Email id: Hvlimbachiya@myseneca.ca
Date: 2022-03-20
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#pragma once
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds
{
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils
    {
        bool m_testMode = false;
    public:
        //gets date from system
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        //gets the days of month
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        //allocate and copy  
        void alloCopy(char* des, const char* src);
        //check the state validity
        bool valid(const char* description);
        //get input as integer 
        int getInt(const char* prompt = nullptr);
        //get input as integer and validate integer 
        int getInt(int min, int max, const char* prompt = nullptr, const char* errMsg = nullptr);
    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H

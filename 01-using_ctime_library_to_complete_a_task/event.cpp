//Name: Rujal Tuladhar
//Student: 154594188
//Class: OOP345NBB
//Seneca email: rtuladhar@myseneca.ca

//I have done this workshop 1 on my own only using the materials provided to me by the professor

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include<iomanip>
#include<iostream>
#include<cstring>



using namespace std;

unsigned long g_sysClock = 0;
namespace sdds
{
	sdds::Event::Event()
	{
		m_time = 0;
		m_desc = nullptr;
	}

	void sdds::Event::display()
	{
		static int counter = 0;

		unsigned int hh = 0, mm = 0, ss = 0;

		hh = m_time / 3600;
		mm = (m_time / 60) %60;
		ss = m_time%60;

		if (m_desc == nullptr)
		{
			cout << setw(2) << setfill(' ') << ++counter << ". " << "| No Event |" << endl;

		}
		else
		{
			cout << setw(2) << setfill(' ') << ++counter << ". " << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " => " << m_desc<<endl;
		}
	}


	void sdds::Event::set(const char* m_value)
	{
		m_time = g_sysClock;
		if (m_value != nullptr &&  strlen(m_value)!=0)
		{
			if (m_desc != nullptr)
			{
				delete[] m_desc;
				m_desc = nullptr;
			}
			m_desc = new char[strlen(m_value) + 1];
			strcpy(m_desc, m_value);
			

			



		}
		else
		{
			delete[] m_desc;
			m_desc = nullptr;
			m_time = 0;
		}
	}

	Event::Event(const Event& obj)
	{
		m_time = obj.m_time;
		if (obj.m_desc != nullptr)
		{
			m_desc = new char[strlen(obj.m_desc) + 1];
			strcpy(m_desc, obj.m_desc);

			
		}
		else
		{
			m_desc = nullptr;
		
		}
		
	}

	Event& Event::operator=(const Event& obj)
	{
		if (this != &obj)
		{
			m_time = obj.m_time;

			if (m_desc != nullptr)
			{
				delete[] m_desc;
			}

			if (obj.m_desc != nullptr)
			{
				m_desc = new char[strlen(obj.m_desc) + 1];
				strcpy(m_desc, obj.m_desc);
				
			}
			else
			{
				m_desc = nullptr;
				
			}

		}
		

		// TODO: insert return statement here
		return *this;
	}

	Event::~Event()
	{
		if (m_desc != nullptr)
		{
			delete[] m_desc;
		}
		m_desc = nullptr;

		m_time = 0;
	}


}



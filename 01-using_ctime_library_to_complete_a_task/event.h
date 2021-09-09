//Name: Rujal Tuladhar
//Student: 154594188
//Class: OOP345NBB
//Seneca email: rtuladhar@myseneca.ca

//I have done this workshop 1 on my own only using the materials provided to me by the professor

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned long g_sysClock;

namespace sdds
{
	class Event
	{
		int m_time;
		char* m_desc;

	public:

		Event();

		void display();

		void set(const char* m_value = 0);

		Event(const Event& obj);
		Event& operator = (const Event& obj);

		~Event();
	};

}




#endif
//Name: Rujal Tuladhar
//Email: rtuladhar@myseneca.ca
//Seneca_id: 154594188
//I have done this project on my own using the only the material my professor has provided me.

#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <iomanip>
using namespace std;
namespace sdds
{
	


	

	void sdds::TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();
	}

	void sdds::TimedEvents::stopClock()
	{
		 end = std::chrono::steady_clock::now();
	}

	void sdds::TimedEvents::addEvent(const char* value)
	{

		static size_t counter = 0;
		if (counter < MAX_SIZE)
		{
			s[counter].event_name = value;
			s[counter].m_frame = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			s[counter].u_time = "nanosceonds";
			counter++;
 		}

		this->rec_number = counter;

	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& obj)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (size_t i = 0; i < obj.rec_number; i++)
		{
		
			os << setw(21) << left << obj.s[i].event_name << setw(13) << right << obj.s[i].m_frame.count()<<endl;

		}

		os << "--------------------------"<<endl;
		return os;
	}




}
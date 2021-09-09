//Name: Rujal Tuladhar
//Email: rtuladhar@myseneca.ca
//Seneca_id: 154594188
//I have done this project on my own using the only the material my professor has provided me.
#pragma once
#ifndef SDDS_TEMED_EVENTTS_H
#define SDDS_TIMED_EVENTS_H
#include<chrono>
#include<string>
#define MAX_SIZE 10



namespace sdds
{
	

	class TimedEvents
	{
		size_t rec_number{ 0u};
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end ;
		
	   struct Event{
		   std::string event_name {};
		   std::string u_time {};
			std::chrono::steady_clock::duration m_frame {};
		}s[MAX_SIZE];

	public:

		
		void startClock();
		void stopClock();
 		void addEvent(const char* value);
		
		friend std::ostream& operator <<(std::ostream& os, const TimedEvents& obj);

	};
}


#endif // SDDS_TEMED_EVENTTS_H

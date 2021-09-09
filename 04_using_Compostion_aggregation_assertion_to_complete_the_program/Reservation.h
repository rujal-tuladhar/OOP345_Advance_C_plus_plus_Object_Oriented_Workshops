//Name: Rujal Tuladhar
//email: rtuladhar@myseneca.ca
//id: 154594188
//I have done this work using only the notes provided by the profesoor
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H


#include<string>
#include<iostream>

namespace sdds
{
	class Reservation
	{
		
		std::string res_id {0};
		std::string m_name {0};
		std::string m_email {0};
		int no_people =0;
		int the_day =0;
		int the_hour=0;

	public:


		Reservation();

		Reservation(const std::string& res);

		friend std::ostream &operator << (std::ostream& os,const Reservation& obj); 
	
	};
	

}

#endif // !SDDS_RESERVATION_H
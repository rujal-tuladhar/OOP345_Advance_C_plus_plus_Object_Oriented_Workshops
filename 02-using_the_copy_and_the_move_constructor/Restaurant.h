//Name: Rujal Tuladhar
//email: rtuladhar@myseneca.ca
//id: 154594188
//I have done this work using only the notes provided by the profesoor
#ifndef _SDDS_RESTAURANT_H
#define _SDDS_RESTAURANT_H
#include<iostream>
#include"Reservation.h"
namespace sdds
{

	class Restaurant
	{
		Reservation* m_obj = nullptr;
		size_t no;


	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);

		~Restaurant();

		Restaurant(const Restaurant& obj);

		Restaurant& operator =(const Restaurant& obj);


		Restaurant(Restaurant&& obj)noexcept;

		Restaurant&& operator=(Restaurant&& obj)noexcept;


		size_t size() const;

		friend std::ostream &operator<<(std::ostream& os, const Restaurant& obj);
	};
	
}
#endif



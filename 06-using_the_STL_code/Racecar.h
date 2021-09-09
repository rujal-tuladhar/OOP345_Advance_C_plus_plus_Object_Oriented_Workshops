//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor

#pragma once
#ifndef SDDS_RACE_H
#define SDDS_RACE_H

#include <istream>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	
	{
		double m_boost; 
	
	public:
		
		Racecar(std::istream& in);


		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}


#endif

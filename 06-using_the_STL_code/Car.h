//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor

#ifndef SDDS_CAR_H
#define SDDS_CAR_H


#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{	
		std::string m_tag;		
		std::string m_maker;		
		std::string m_condition;	
		double m_top_speed;


	public:
		
		
		Car(std::istream& record);
		std::string condition() const;	
		double topSpeed() const;
		void display(std::ostream& out) const;	
		void remov(std::string& line);

	};
}
#endif
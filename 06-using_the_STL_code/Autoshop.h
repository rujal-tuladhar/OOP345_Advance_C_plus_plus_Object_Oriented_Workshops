//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor

#pragma once
#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include <iostream>
#include "Vehicle.h"


namespace sdds 
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:

		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (size_t i = 0; i < m_vehicles.size(); i++)
			{
				if (test(m_vehicles[i]))
				{
					vehicles.push_back(m_vehicles[i]);
				}
			}
		};
	};

}
#endif 


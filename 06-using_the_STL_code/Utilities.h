//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor

#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <istream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"


namespace sdds 
{
	Vehicle* createInstance(std::istream& in);
}

#endif 


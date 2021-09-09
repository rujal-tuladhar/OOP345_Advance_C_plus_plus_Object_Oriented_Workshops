//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor
#define _CRT_SECURE_NO_WARNINGS
#include "Racecar.h"

namespace sdds 
{
	Racecar::Racecar(std::istream& in) :Car(in)
	{

		try {
			std::string temp;

			getline(in, temp, '\n');
			m_boost = std::stod(temp);

		}
		catch (...) {
			throw std::invalid_argument("Invalid record!");
		}
	}
	
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed() * m_boost);
	}
}
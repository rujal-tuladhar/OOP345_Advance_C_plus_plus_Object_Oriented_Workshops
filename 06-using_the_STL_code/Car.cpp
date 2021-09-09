//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor
#include <iostream>
#include <iomanip>      
#include <sstream>    
#include <string>

#include "Car.h"

using namespace std;

namespace sdds {

	//instead of repeating removing the unwanted charcter form the begining and the end of the file 
	void Car::remov(std::string& line)
	{
		size_t i = 0u;
		for (i = 0u; i < line.length() && line[i] == ' '; ++i);
		line = line.substr(i);
		for (i = line.length(); i > 0u && line[i - 1] == ' '; --i);
		line = line.substr(0, i);
	}

	Car::Car(std::istream& record) {
		std::string token;
		//finddint the string up to the comma and storing it in the string
		std::getline(record, m_tag, ',');
		remov(m_tag);

		std::getline(record, m_maker, ',');
		remov(m_maker);

		std::getline(record, m_condition, ',');
		remov(m_condition);

		if (m_condition != "n" && m_condition != "u" && m_condition != "b") {
			if (m_condition == "") 
			{
				//if the empty
				m_condition = "new";
			}
			else {
				throw "Invalid record!";
			}
		}

		std::getline(record, token, ',');
		remov(token);

		try
		{
			m_top_speed = stod(token);
		}
		catch (...) {
			throw "Invalid record!";
		}
	};

	

	std::string Car::condition() const
	{
		std::string temp = "";
		if (m_condition[0] == 'n') {
			temp = "new";
		}
		else if (m_condition[0] == 'u') {
			temp = "used";
		}
		else if (m_condition[0] == 'b') {
			temp = "broken";
		}
		return temp;
	}

	double Car::topSpeed() const 
	{
		return m_top_speed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out << std::setw(10) << right << m_maker;
		out << " | ";
		out << std::setw(6) << left << this->condition();
		out << " | ";
		out << std::setw(6) << right << std::fixed << std::setprecision(2) << topSpeed();
		out << " |";
	}
}
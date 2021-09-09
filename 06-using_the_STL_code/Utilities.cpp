//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

using namespace std;

namespace sdds {

	Vehicle* createInstance(istream& in)
	{
	
		stringstream str;
		string value;
		getline(in, value, '\n');

		str << value;

		value = value.substr(0, value.find(','));
		//removing the space from the begining of the string and the end of the string
		value.erase(0, value.find_first_not_of(" "));
		value.erase(value.find_last_not_of(" ") + 1);


		if (value !="")
		{
			if (value[0] == 'c' || value[0] == 'C')
			{
				return new Car(str);
			}

			else if (value[0] == 'r' || value[0] == 'R')
			{
				return new Racecar(str);
			}

			else
			{
			
				string s_value;
				getline(str, s_value, ',');
				//removing the space in the string

				s_value.erase(0, s_value.find_first_not_of(" "));
				s_value.erase(s_value.find_last_not_of(" ") + 1);
				//this throw will be cathed in the main file 
				throw "Unrecognized record type: [" + s_value + "]";
			}
		}
		else
		{
			return  nullptr;
		}
		
	}

}

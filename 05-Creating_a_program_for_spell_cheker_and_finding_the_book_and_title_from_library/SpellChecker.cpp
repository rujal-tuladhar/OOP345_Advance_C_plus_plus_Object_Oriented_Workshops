//Name: Rujal Tuladhar
//Student id: 154594188
//Seneca email: rtuladhar@myseneca.ca

#include <iomanip>
#include <fstream>
#include "SpellChecker.h"


using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) 
	
	{
		ifstream file(filename);
		
		if (!file) 
		{
			throw "Bad file name!";
		}
		for (size_t i = 0; i < 5; i++)
		{
			file >> m_badWords[i];
			file >> m_goodWords[i];
		}
	}

	void SpellChecker::operator()(std::string& t) const {
		for (size_t i = 0; i < 5; i++) {
			while (t.find(m_badWords[i]) != string::npos)
			
			{
				t = t.replace(t.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}
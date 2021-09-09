//Name: Rujal Tuladhar
//Student id: 154594188
//Seneca email: rtuladhar@myseneca.ca

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <cstring>

namespace sdds
{

	class SpellChecker
	{
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		SpellChecker(const char*);
		void operator()(std::string&) const;

	};
}

#endif
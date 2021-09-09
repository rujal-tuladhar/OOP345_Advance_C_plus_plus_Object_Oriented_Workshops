//Name: Rujal Tuladhar
//Student id: 154594188
//Seneca email: rtuladhar@myseneca.ca


#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
namespace sdds {
	class Movie
	
	{
		std::string m_title;
		size_t m_year;
		std::string m_desc;
		
	public:
		
		Movie();
		Movie(const std::string& strMovie);
		~Movie() {};

		const std::string& title() const;
		
		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}
		friend std::ostream& operator<<(std::ostream&, const Movie&);
		
	};
}

#endif

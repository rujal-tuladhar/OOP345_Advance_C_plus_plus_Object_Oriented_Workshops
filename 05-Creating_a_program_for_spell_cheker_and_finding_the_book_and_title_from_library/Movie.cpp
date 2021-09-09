
#include <iomanip>
#include "Movie.h"
using namespace std;

namespace sdds

{
	Movie::Movie() : m_title{ "" }, m_year{ 0 }, m_desc{ "" } {}



	const string& Movie::title() const
    {
		return m_title;
	}

    Movie::Movie(const string& mov)
    {
        string title, year, desc;
        string str = mov;

        title = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        year = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        desc = str;

        // trim the whitespaces
        title.erase(title.find_last_not_of(' ') + 1);
        title.erase(0, title.find_first_not_of(' '));

        desc.erase(desc.find_last_not_of(' ') + 1);
        desc.erase(0, desc.find_first_not_of(' '));

        m_title = title;
        m_desc = desc;
        m_year = stoi(year);
    }

	ostream& operator<<(ostream& os, const Movie& movie)
    
    {
		os << setw(40) << movie.m_title << " | "
		   << setw(4) << movie.m_year << " | "
		   << movie.m_desc << endl;
		return os;
	}
}
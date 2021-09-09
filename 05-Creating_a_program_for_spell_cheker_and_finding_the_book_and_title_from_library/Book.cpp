//Name: Rujal Tuladhar
//Student id: 154594188
//Seneca email: rtuladhar@myseneca.ca

#include <iomanip>
#include "Book.h"
using namespace std;

namespace sdds {

	Book::Book() 
	{
		m_year = 0;
		m_price = 0;
	}
	const string& Book::title() const
	{
		return m_title;
	}
	const string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}


	void Book::trim(string& val) 
	{
		size_t i = 0;
		for (i = 0; i < val.length() && val[i] == ' '; i++);
		val = val.substr(i);

		for (i = val.length(); i > 0 && val[i - 1] == ' '; i--);
		val = val.substr(0, i);
	}
	//previous workshop
	Book::Book(const string& bk) {
		std::string src;
		src = bk;
		trim(src);
		size_t field;

		field = src.find(",");
		m_author = src.substr(0, field);
		trim(m_author);
		src.erase(0, field + 1);

		field = src.find(",");
		m_title = src.substr(0, field);
		trim(m_title);
		src.erase(0, field + 1);

		field = src.find(",");
		m_country = src.substr(0, field);
		trim(m_country);
		src.erase(0, field + 1);

		field = src.find(",");
		m_price = std::stod(src.substr(0, field)); 
		src.erase(0, field + 1);

		field = src.find(",");
		m_year = std::stoi(src.substr(0, field));
		src.erase(0, field + 1);

		m_description = src.substr(0);
		trim(m_description);
	}


	ostream& operator<<(ostream& os, const Book& book) 
	{
		os  
			<< setw(20) << book.m_author << " | "
			<< setw(22) << book.title() << " | "
			<< setw(5) << book.country() << " | "
			<< setw(4) << book.year() << " | "
			<< setw(6) << fixed << setprecision(2) << book.m_price << " | "
			<< book.m_description << endl;
		return os;
	}
}
//Name: Rujal Tuladhar
//Student id: 154594188
//Seneca email: rtuladhar@myseneca.ca

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
#include<fstream>

using namespace std;


namespace sdds {
	
	class Book {

		string m_author;
		string m_title;
		string m_country;
		size_t m_year;
		double m_price;
		string m_description;
		
	public:

		Book();
		

		const string& title() const;
		const string& country() const;
		const size_t& year() const;

		double& price();
		Book(const string& bk);

		const string& description() const;
		friend ostream& operator<<(ostream& os, const Book&);
		void trim(string& val);
		
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_description);
		}
	};

}
#endif
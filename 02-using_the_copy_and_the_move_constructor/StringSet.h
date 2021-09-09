//Name: Rujal Tuladhar
//Email: rtuladhar@myseneca.ca
//Seneca_id: 154594188
//I have done this project on my own using the only the material my professor has provided me.
#pragma once
#ifndef SDDS_STRING_SET
#define SDDS_STRING_SET
#include<string>

using namespace std;
namespace sdds
{
class StringSet
{

	string *m_info;
	size_t noOfRecords;
public:

	StringSet();
	StringSet(const char* m_file );
	size_t size();
	string operator[](size_t m_index);
	StringSet(const StringSet&);
	StringSet& operator = (const StringSet& obj);
	StringSet(StringSet&&)noexcept;
	StringSet& operator = (StringSet&& obj)noexcept;


	~StringSet();

};

}

#endif // !SDDS_STRING_SET
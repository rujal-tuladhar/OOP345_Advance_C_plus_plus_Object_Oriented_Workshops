//Name: Rujal Tuladhar
//Email: rtuladhar@myseneca.ca
//Seneca_id: 154594188
//I have done this project on my own using the only the material my professor has provided me.
#include<iostream>
#include<fstream>
#include "StringSet.h"
#include"TimedEvents.h"
using namespace std;
namespace sdds
{
	
	StringSet::StringSet()
	{
		this->m_info = nullptr;
		this->noOfRecords = 0u;
	}

	StringSet::StringSet(const char* m_file)
	{
		string temp ;
	    size_t counter = 0;
		ifstream newfile(m_file);
	      if(newfile.is_open())
		{
			  while (!newfile.eof())
			  {
				  (getline(newfile, temp, ' '));
					  ++counter;
			  }
		}

		 
		 noOfRecords = counter;
		 newfile.close();
		 temp = " ";
		
		  m_info = new string[counter];
		 
		
		  
		  ifstream read_file(m_file);
		  if (read_file.is_open())
		  {
			  while (!read_file.eof())
			  {
				  for (size_t i = 0; i < counter; i++)
				  {
					  getline(read_file, temp, ' ');
					  this->m_info[i] = temp;
				  }


			  }
		 
		  }

		  read_file.close();


	}

	size_t StringSet::size()
	{
		return this->noOfRecords;
	}

	string StringSet::operator[](size_t m_index)
	{
		return (noOfRecords > 0 && m_index < noOfRecords) ? m_info[m_index] : "";
		
	}


	StringSet::StringSet(const StringSet &obj)
	{
		
		*this = obj;


		
	}
	
	StringSet& StringSet::operator=(const StringSet& obj)
	{
		if (this != &obj)
		{
			
			

			this->m_info = new string[obj.noOfRecords];
			//since i cannot use the copy since they are of string and char type
			for (size_t i = 0u; i < obj.noOfRecords; ++i)
			{
				this->m_info[i] = obj.m_info[i];
			}


			this->noOfRecords = obj.noOfRecords;

		}

		return *this;
	}

	StringSet::StringSet( StringSet&& obj)noexcept
	{
		*this = move(obj);
	}

	StringSet& StringSet::operator=( StringSet&& obj)noexcept
	{
		if (this != &obj)
		{
	

			this->noOfRecords = obj.noOfRecords;

			this->m_info = new string[noOfRecords];
			for (size_t i = 0u; i < noOfRecords; i++)
			{
				this->m_info[i] = obj.m_info[i];
			}

			delete[] obj.m_info;
			obj.m_info = nullptr;

			
			obj.noOfRecords = 0u;
			
			


	   }

		return *this;
	}

	StringSet::~StringSet()
	{

		delete[] this->m_info;
		this->m_info = nullptr;
		
	}


}

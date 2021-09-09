#include "Restaurant.h"

using namespace std;
namespace sdds
{
	Restaurant::Restaurant()
	{
		this->m_obj = nullptr;
		this->no = 0;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		this->no = cnt;
		this->m_obj = new Reservation[cnt];

		for (size_t i = 0; i < no; i++)
		{
			m_obj[i] = *reservations[i];
		}


	}

	Restaurant::~Restaurant()
	{
		delete[] m_obj;
	}

	Restaurant::Restaurant(const Restaurant& obj)
	{
		*this = obj;

	}


	Restaurant& Restaurant::operator =(const Restaurant& obj)
	{
		if (this != &obj)
		{
			delete[] this->m_obj;

			this->m_obj = new Reservation[obj.no];
			for (size_t i = 0; i < obj.no; i++)
			{
				this->m_obj[i] = obj.m_obj[i];
			}

			this->no = obj.no;
		}

		return *this;
	}

	Restaurant::Restaurant(Restaurant&& obj)noexcept
	{
		*this = move(obj);
	}
	

	Restaurant&& Restaurant::operator=(Restaurant&& obj)noexcept
	{
		if (this != &obj)
		{
			this->m_obj = obj.m_obj;
			this->no = obj.no;
			obj.m_obj = nullptr;
			obj.no = 0;

		}

		return std::move(*this);
	}

	size_t Restaurant::size() const
	{
		return this->no;
	}

	
	

	ostream& operator<<(ostream& os, const Restaurant& obj)
	{
		
			os << "--------------------------" << endl;
			static int counter=0;
			os << "Fancy Restaurant " << "("<<++counter<<")" << endl;


			if (obj.no == 0)
			{
				os << "--------------------------" << endl;
				os << "This restaurant is empty!"<<endl;

			}
			else
			{
				os << "--------------------------" << endl;
				for (size_t i = 0; i < obj.no; i++)
				{
					os << obj.m_obj[i];
				}
			}

			os << "--------------------------" << endl;

		
		return os;
	}

}
//Name: Rujal Tuladhar
//email: rtuladhar@myseneca.ca
//id: 154594188
//I have done this work using only the notes provided by the profesoor


#include <iomanip>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {

	ConfirmationSender::ConfirmationSender() {}


	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& obj)
	{
		if (this != &obj) {
			m_count = obj.m_count;

			delete[] this->m_reserve;
			this->m_reserve = new const Reservation * [m_count];

			for (auto i = 0u; i < m_count; i++)
			{
				this->m_reserve[i] = obj.m_reserve[i];
			}
		}
		return *this;
	}


	ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj)
	{
		*this = obj;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj) noexcept 
	{
		*this = move(obj);
	}




	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& obj) noexcept
	{
		if (this != &obj)
		{
			m_count = obj.m_count;

			delete[] this->m_reserve;
			this->m_reserve = obj.m_reserve;
			obj.m_count = 0;
			obj.m_reserve = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& reservation)
	{
		bool result = false;
		for (auto i = 0u; i < m_count && result == false; i++)
		{
			if (&reservation == m_reserve[i])
			{
				result = true;
			}
		}

		if (result == false)
		{
			const Reservation** temp = nullptr;
			temp = new const Reservation * [m_count + 1];
			for (auto i = 0u; i < m_count; i++)
			{
				temp[i] = m_reserve[i];
			}
			temp[m_count] = &reservation;
			m_count++;
			delete[] m_reserve;
			m_reserve = temp;
		}
		return *this;
	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& reservation)

	{
		bool result = false;
		int index = -1;
		for (auto i = 0u; i < m_count && result == false; i++)

		{
			if (&reservation == m_reserve[i])
			{
				result = true;
				index = i;
			}
		}

		if (result == true)
		{
			const Reservation** temp = nullptr;
			if (m_count > 0)
			{
				temp = new const Reservation * [m_count - 1];
				for (int i = 0; i < (int)m_count - 1; i++)
				{
					if (i < index)
					{
						temp[i] = m_reserve[i];
					}
					else
						temp[i] = m_reserve[i + 1];
				}
			}
			m_count--;
			delete[] m_reserve;
			m_reserve = temp;
		}

		return *this;
	}


	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_reserve;
	}


	ostream& operator<<(ostream& os, const ConfirmationSender& c_sender)
	{
		os << "--------------------------\n"
			<< "Confirmations to Send\n"
			<< "--------------------------\n";
		if (c_sender.m_count == 0) {
			os << "There are no confirmations to send!\n";
		}
		for (auto i = 0u; i < c_sender.m_count; i++)
		{
			if (c_sender.m_reserve[i] != nullptr)
			{
				os << *c_sender.m_reserve[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}
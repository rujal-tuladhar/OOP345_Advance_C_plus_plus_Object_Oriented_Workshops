//Name: Rujal Tuladhar
//email: rtuladhar@myseneca.ca
//id: 154594188
//I have done this work using only the notes provided by the profesoor
#ifndef _SDDS_CONFIRMATIONSENDER_H
#define _SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
#include <iostream>


namespace sdds
{
	class ConfirmationSender

	{
		const Reservation** m_reserve = nullptr;
		size_t m_count = 0u;
	public:
		ConfirmationSender();

		ConfirmationSender(const ConfirmationSender& obj);
		ConfirmationSender& operator=(const ConfirmationSender& obj);
		ConfirmationSender(ConfirmationSender&& obj) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& obj) noexcept;

		ConfirmationSender& operator+=(const Reservation& reservation);
		ConfirmationSender& operator-=(const Reservation& reservation);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& conSender);
		~ConfirmationSender();
	};
}
#endif

//Name: Rujal Tuladhar
//email: rtuladhar@myseneca.ca
//id: 154594188
//I have done this work using only the notes provided by the profesoor
#include<iomanip>
#include "Reservation.h"
using namespace std;
namespace sdds
{

	Reservation::Reservation()
	{
		this->m_email = "";
		this->m_name = "";
		this->no_people = 0;
		this->res_id = "";
		this->the_day = 0;
		this->the_hour = 0;

	}


	Reservation::Reservation(const std::string& res)
	{

		string value;
		value = res;


		//value.erase(remove(value.begin(), value.end(), ' '), value.end());

	


		string id;
		string name;
		string email;
		string people;
		string day;
		string hour;


		id = value.substr(0, value.find(':'));
		value.erase(0, value.find(':')+1);

		id.erase(id.find_last_not_of(' ') + 1);
		id.erase(0, id.find_first_not_of(' '));


		

		name = value.substr(0, value.find(','));
		value.erase(0, value.find(',') + 1);
		name.erase(name.find_last_not_of(' ') + 1);
		name.erase(0, name.find_first_not_of(' '));


		email = value.substr(0, value.find(','));
		value.erase(0, value.find(',') + 1);
		email.erase(email.find_last_not_of(' ') + 1);
		email.erase(0, email.find_first_not_of(' '));


		
		
		people = value.substr(0, value.find(','));
		value.erase(0, value.find(',') + 1);


		
		day = value.substr(0, value.find(','));
		value.erase(0, value.find(',') + 1);




		hour = value.substr(0, value.find(','));


		this->res_id = id;
		this->m_name = name;
		this->m_email = email;
		this->no_people = stoi(people);
		this->the_day = stoi(day);
		this->the_hour = stoi(hour);
		  



	}


 

	ostream &operator<<(ostream& os,const Reservation& obj)
	{
		
		if (obj.the_hour >= 6 && obj.the_hour <= 9)
		{
			os << "Reservation " << setw(10) << right << obj.res_id << ": ";
			os << setw(20) << right << obj.m_name;
			os << "  <" << setw(20) << left << obj.m_email + ">  ";
			os << "   Breakfast on day " << obj.the_day << " @ " << obj.the_hour << ":00 for " << obj.no_people;
			if (obj.no_people > 1)
			{
				os << " people." << endl;
			}
			else
				os << " person." << endl;
	   
		}
		else if (obj.the_hour >= 11 && obj.the_hour <= 15)
		{
			os << "Reservation " << setw(10) << right << obj.res_id << ": ";
			os << setw(20) << right << obj.m_name;
			os << "  <" << setw(20) << left << obj.m_email + ">  ";
			os << "   Lunch on day " << obj.the_day << " @ " << obj.the_hour << ":00 for " << obj.no_people;
			if (obj.no_people > 1)
			{
				os << " people." << endl;
			}
			else
				os << " person." << endl;

		}
		else if (obj.the_hour >= 17 && obj.the_hour <= 21)
		{
			os << "Reservation " << setw(10) << right << obj.res_id << ": ";
			os << setw(20) << right << obj.m_name;
			os << "  <" << setw(20) << left << obj.m_email + ">  ";
			os << "   Dinner on day " << obj.the_day << " @ " << obj.the_hour << ":00 for " << obj.no_people;
			if (obj.no_people > 1)
			{
				os << " people." << endl;
			}
			else
				os << " person." << endl;

		}
		
		else  
		{
			os << "Reservation " << setw(10) << right << obj.res_id << ": ";
			os << setw(20) << right << obj.m_name;
			os << "  <" << setw(20) << left << obj.m_email + ">  ";
			os << "   Drinks on day " << obj.the_day << " @ " << obj.the_hour << ":00 for " << obj.no_people;
			if (obj.no_people > 1)
			{
				os << " people." << endl;
			}
			else
				os << " person." << endl;

		}


		


		return os;
	}

}
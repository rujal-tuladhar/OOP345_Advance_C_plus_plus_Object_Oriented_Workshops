//Name: Rujal Tuladhar
//id: 154594188
//I have done the assignment on my own using only the code provided by my proffesor
#define _CRT_SECURE_NO_WARNINGS
#include "Autoshop.h"

namespace sdds

{
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
     
        return *this;
    }

    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------" << std::endl;
       
        out << "| Cars in the autoshop!        |" << std::endl;
       
        out << "--------------------------------" << std::endl;

      

        for (auto iterator = m_vehicles.begin(); iterator != m_vehicles.end(); iterator++)
        
        {
            (*iterator)->display(out);
            out << std::endl;
        }
      
        out << "--------------------------------" << std::endl;

    }

    Autoshop::~Autoshop()
    {
        for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
            delete* ptr;
    }

    

}

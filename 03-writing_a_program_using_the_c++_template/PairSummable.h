//student id - 154594188
//name - Rujal Tuladhar
//seneca email - rtuladhar@myseneca.ca
//I have done this work on my own only using the code provided by my professor.


#ifndef SDDS_PAIR_SUMMABLE_H
#define SDDS_PAIR_SUMMABLE_H
#include<iomanip>
#include"Pair.h"

namespace sdds
{
	template<typename V, typename K>
	class PairSummable: public Pair<V,K>
	{
	private:

		static V initial;
		static size_t min_field;

	public:
		PairSummable() { };

		PairSummable(const  K& key, const V& value = initial) :Pair<V,K>(key,value)
		{
			if (key.size() > min_field)
			{
				 min_field = key.size();
		  
			}
		}

		bool isCompatibleWith(const PairSummable<V,K>& b)const
		{
			bool value = false;
			if (this->key() == b.key())
			{
				value = true;
			}

			return value;
		}


		PairSummable<V, K>& operator += (const PairSummable<V, K> &obj)
		{

			*this = PairSummable(this->key(),this->value() + obj.value());
				return *this;
			
		}
                 //override function
		void display(std::ostream &os)const override
		{
			os.setf(std::ios::left);
			os.width(min_field);
			Pair<V, K>::display(os);
			
		}
		
		
	};
	//the static value intilization for the istance of the class
	template<typename V, typename K>
	size_t PairSummable<V, K>::min_field = 0u;

	//since the intial value depend upon the type assigned so we need to intilize the value accordingly

	template<typename V, typename K>
	V PairSummable<V, K>::initial{};

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator +=(const PairSummable<std::string, std::string>& obj)
	{
		//to remove the spaces in the first value we use the if statement
		if (this->value() != "")  
		{
			*this = PairSummable<std::string,std::string>(this->key(),this->value() + ", " + obj.value());
			
		}
		else
		{
			*this = PairSummable<std::string, std::string>( this->key(),this->value() + obj.value());
		}


		return *this;
	}

}
#endif
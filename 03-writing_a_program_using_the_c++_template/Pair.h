//student id - 154594188
//name - Rujal Tuladhar
//seneca email - rtuladhar@myseneca.ca
//I have done this work on my own only using the code provided by my professor.


#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include<iostream>

namespace sdds
{
	template<typename V, typename K>
	class Pair
	{
	private:
		V m_value;
		K m_key;

		
	public:
		Pair()
		{

		}

		Pair(const K& key, const V& value)
		{
			m_value = value;
			m_key = key;
		}

		const V& value() const
		{
			return m_value;
		}

		const K& key() const
		{
			return m_key;
		}

		virtual void display(std::ostream& os)const
		{
			os << m_key << " : " << m_value << std::endl;
		}
	

	};


	template<typename V , typename K>
	std::ostream& operator <<(std::ostream& os, const Pair<V, K>& pair)
	{
		pair.display(os);
		return os;
	}

}
#endif // !1

//student id - 154594188
//name - Rujal Tuladhar
//seneca email - rtuladhar@myseneca.ca
//I have done this work on my own only using the code provided by my professor.


#ifndef SDDS_SET_H
#define SDDS_SET_H
namespace sdds
{

	template<unsigned int N, typename T>
	class Set
	{

		T arr[N];
		unsigned int counter = 0;

	public:

	

		size_t size()const
		{
			return counter;
		}

		const T& get(size_t idx) const
		{
			
			return arr[idx];
		}

		void operator+=(const T& item)
		{
			if (N > counter)
			{
				arr[counter] = item;
				++counter;
			}

			
		}



	};




}



#endif
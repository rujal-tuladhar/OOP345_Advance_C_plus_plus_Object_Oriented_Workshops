//student id - 154594188
//name - Rujal Tuladhar
//seneca email - rtuladhar@myseneca.ca
//I have done this work on my own only using the code provided by my professor.


#ifndef SDDS_SET_SUMMABLE_H
#define SDDS_SET_SUMMABLE_H
#include"Set.h"

namespace sdds
{

	template <unsigned int N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T obj(filter);
			for (size_t i = 0u; i < this->size(); i++) {
				//cheking if it compatible withe the accumulator obj
				if ((this->get(i)).isCompatibleWith(obj)) {
					obj += this->get(i);
				}
			}
			return obj;
		}
	};

}



#endif

//Name- Rujal Tuladhar
//id - 154594188
//email - rtuladhar@myseneca.ca
//I have done this workshop on my own using the notes provided by the professor

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include "List.h"
#include "Element.h"

namespace sdds {             
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif

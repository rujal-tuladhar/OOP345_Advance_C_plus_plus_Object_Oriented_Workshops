//Name- Rujal Tuladhar
//id - 154594188
//email - rtuladhar@myseneca.ca
//I have done this workshop on my own using the notes provided by the professor

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product* value = new Product(desc[i].desc, price[j].price);
					value->validate();

					priceList += value;
					delete value;

				}
			}
		}



		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> uni_value( new Product(desc[i].desc, price[j].price) );
					
					
					uni_value->validate();
					priceList += uni_value;

					
				}
			}
		}




		return priceList;
	}









}

#include "Allergen.h"
#include <iostream>
const std::unordered_map<Allergen, std::string> allergenNames//Hastábla
{
	{Allergen::Gluten, "gluten"},
	{Allergen::Lactose, "lactose"},
	{Allergen::Eggs, "eggs"},
	{Allergen::Fish, "fish"},
};
Allergen ParseAllergen(const std::string& s) 
{
	const auto selectAllergen = [](const auto& allergenName) 
	{
		for (const auto& [allergen, name] : allergenNames) 
		{
			if (allergenName==name)
			{
				return allergen;
			}
		}
	};
	//const auto selectAllergen = [](const auto& allergenName)Itt kicsit lemaradtam
	//{
	//	const auto it = std::find_if(, allergenNames.cbegin(), allergenNames.cend(), [&allergenName](const auto& allergenNamePair)) 
	//	{
	//		return allergenNamePair.second==allergenName;
	//	}
	//		return it->first;
	//};
	const auto position = s.find(',');
	if (position==std::string::npos)
	{
		return selectAllergen(s);
	}
	auto result = selectAllergen(s.substr(0, position));
	result |= ParseAllergen(s.substr(position + 2));
	return result;
}
void operator |=(Allergen& lhs, const Allergen rhs)
{
	lhs = static_cast<Allergen>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
bool operator &(const Allergen& lhs, const Allergen& rhs) 
{
	return (static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}

std::ostream& operator<<(std::ostream& outputStream, const Allergen allergens) 
{
	std::string separator = "";
	for (const auto& [allergen, name] : allergenNames) 
	{
		if (allergens & allergen)
		{
			outputStream <<separator<< name;
			separator = ", ";
		}
	}
	return outputStream;
}
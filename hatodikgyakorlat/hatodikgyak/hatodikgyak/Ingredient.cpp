#include "Ingredient.h"
#include <string>
#include <iostream>

Ingredient::Ingredient(const std::string& name)
	:mName(name) 
{

}
Ingredient::Ingredient(const std::string& name, const Allergen allergen)
	:mName(name)
	, mAllergens(allergen)
{

}
Ingredient::Ingredient(const std::string& name, const std::vector<Allergen>& allergens) 
	:mName(name)
{
	for (const auto& allergen:allergens)
	{
		mAllergens |= allergen;
	}
}

Ingredient Ingredient::Parse(const std::string& s)
{
	const auto position = s.find('(');
	if (position == std::string::npos)
	{
		return Ingredient(s);
	}
	return Ingredient(s.substr(0, position-1), ParseAllergen(s.substr(position+1,s.size()-position-2)));
}

std::ostream& operator<<(std::ostream& outputStream, const Ingredient& Ingredient) 
{
	outputStream << Ingredient.mName;
	if (Ingredient.mAllergens==Allergen::None)
	{
		return outputStream;
	}

	outputStream << " (" << Ingredient.mAllergens << ")";
	return outputStream;
}
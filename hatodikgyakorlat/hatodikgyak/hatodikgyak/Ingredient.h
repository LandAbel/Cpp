#pragma once
#include "Allergen.h"

#include <string>
#include <vector>
#include <iostream>
class Ingredient
{
public:
	Ingredient(const std::string& name);
	Ingredient(const std::string& name, const Allergen allergen);
	Ingredient(const std::string& name, const std::vector<Allergen>& allergens);

	static Ingredient Parse(const std::string& s);

	friend std::ostream& operator<<(std::ostream& outputStream, const Ingredient& Ingredient);
private:
	std::string mName;
	Allergen mAllergens = Allergen::None;//static_cast<Allergen>(0)
};

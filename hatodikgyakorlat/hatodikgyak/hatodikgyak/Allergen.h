#pragma once
#include <cstdint>
#include <iostream>
#include <unordered_map>

enum class Allergen: uint8_t
{
	None=0,
	Gluten=1<<0,
	Lactose=1<<1,
	Eggs=1<<2,
	Fish=1<<3,

};

Allergen ParseAllergen(const std::string& s);
void operator |=(Allergen& lhs, const Allergen rhs);
bool operator &(const Allergen& lhs, const Allergen& rhs);

std::ostream& operator<<(std::ostream& outputStream, const Allergen allergens);


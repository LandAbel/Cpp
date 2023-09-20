#include "Ingredient.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main()
{
    //std::cout << "Hello World!\n";
    //Ingridient ingridient01("salt");
    //Ingridient ingridient02("wheat flour", Allergen::Gluten);
    //Ingridient ingridient03("pasta", { Allergen::Gluten, Allergen::Eggs });
    std::vector<Ingredient> ingridients
    {
        {"salt"},
        {"wheat flour", Allergen::Gluten},
        {"pasta", {Allergen::Gluten, Allergen::Eggs}}
    };
    std::ofstream outputFile("ingredients.txt");
    if (!outputFile.is_open())
    {
        return -1;
    }
    for (const auto& ingridient:ingridients )
    {
        outputFile << ingridient << std::endl;
        //std::cout << ingridient << std::endl;
    }

    std::ifstream inputFile("ingredients.txt");
    if (!inputFile)
    {
        return -1;
    }
    std::vector<Ingredient> ingredients2;
    while (!inputFile.eof())
    {
        std::string s;
        std::getline(inputFile, s);
        if (s.empty())
        {
            continue;
        }
        ingredients2.push_back(Ingredient::Parse(s));
    }
    //Egy gyors kiírás, hogy lecsekkoljam
    for (const auto& ingridient : ingredients2)
    {
        std::cout << ingridient << std::endl;
    }
    //Saját idióta probálkozásom
    //std::string line;
    //while (std::getline(inputFile, line)) 
    //{
    //    auto first = line.substr(0, line.find('(') | line.find(' '));
    //    auto firstAllergen = line.substr(line.find('(')+1, line.find(')'));
    //    //std::cout << first << std::endl;
    //    std::cout << "*************************************" << std::endl;
    //    std::cout << firstAllergen << std::endl;
    //}
}


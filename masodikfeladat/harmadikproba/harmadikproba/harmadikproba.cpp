#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Trie.h"
int main() 
{
	//Read spelldict. file and insert into tree
	Trie spelldicitionary;
	std::ifstream infile("wordsEn.txt");
	if (!infile) {
		std::cerr << "Error: could not open file 'wordsEn.txt'" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(infile,line))
	{
		spelldicitionary.insert(line);
	}
	//Read input text from console
	std::string text;
	std::cout << "Enter text:\t";
	std::getline(std::cin, text);
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);//To convert upper to lower
	std::replace_if(text.begin(), text.end(),
		[](const auto c) { return !std::isalpha(c); }, ' ');//Deleting all non letter characters from the input line, like: numbers, punctuation marks
	std::istringstream iss(text);
	std::string word;
	//bool for checking if everything is correct
	bool all_words_spelled_correctly = true;
	while (iss>>word)
	{
		if (!spelldicitionary.search(word))
		{
			all_words_spelled_correctly = false;
			std::cout << "Incorrect word:\t" << word << std::endl;
		}
	}
	if (all_words_spelled_correctly)
	{
		std::cout << "All words are spelled correctly."  << std::endl;
	}
	else
	{
		std::cout << "Some words are spelled incorrectly." << std::endl;
	}
	return 0;
}
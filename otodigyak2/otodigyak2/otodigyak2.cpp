#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

static bool AreYouValid(const char karakter)
{
    //Original
    //bool isUnderscore = (karakter == '_');
    //bool isCapitalletter = (karakter >= 'A' && karakter <= 'Z');
    //bool isLowerletter = (karakter >= 'a' && karakter <= 'z');
    //bool isDigit = (karakter >= '0' && karakter <= '9');

    //return isUnderscore || isCapitalletter || isLowerletter || isDigit;

    //Updated
    return std::isalnum(karakter) || karakter == '_';
    //std::isalnum(karakter) 
    //Checks if the given character is an alphanumeric character as classified by the current C locale. In the default locale, the following characters are alphanumeric:
    //    digits(0123456789)
    //    uppercase letters(ABCDEFGHIJKLMNOPQRSTUVWXYZ)
    //    lowercase letters(abcdefghijklmnopqrstuvwxyz)
}

int main()
{
    std::ifstream inputFile("otodigyak2.cpp");

    std::map<std::string, size_t> wordCounts;

    std::string line;
    while (std::getline(inputFile, line))//Line by line read and store in line variable
    {
        std::replace_if(line.begin(), line.end(),
            [](const auto c) { return !AreYouValid(c); }, ' ');//Replaces the non valid chars with space

        std::stringstream stream(line);//Breaks down the line to words
        std::string word;
        while (stream >> word)
        {
            //This is a great tactic 
            if (const auto& [it, success] = wordCounts.try_emplace(word, 1); !success) {
                ++it->second;
            }
            
            //++wordCounts[word];
        }
    }

    std::ofstream wordOutputFile("word_statistics.txt");//Opens a file named word_statistics.txt for write
    //Writer
    for (const auto& [word, count] : wordCounts)//structured biding declaration
    {
        wordOutputFile << word << " " << count << std::endl;
    }
    wordOutputFile.close();

    //Sort
    std::multimap<size_t, std::string, std::greater<>> frequencyCounts;//size_t-key, string-value, greater<> comparison 
    for (const auto& [word, count] : wordCounts)
    {
        frequencyCounts.emplace(count, word);//new key and value without new object
    }

    std::ofstream frequencyOutputFile("frequency_statistics.txt");//Opens a file named frequency_statistics.txt for write

    //Writer
    for (const auto& [count, word] : frequencyCounts)
    {
        frequencyOutputFile << count << " " << word << std::endl;
    }
    frequencyOutputFile.close();

    return 0;
}
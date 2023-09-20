#pragma once
#include <memory>
#include <unordered_map>
#include <string>
class TrieNode
{
public:
	std::unordered_map<char, std::unique_ptr<TrieNode>> children;
	//Public property for checking the end
	bool isEndOfWord;
	//Constructors
	TrieNode();
	~TrieNode();
};
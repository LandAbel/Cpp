#pragma once
#include "TrieNode.h"
class Trie
{
public:
	std::unique_ptr<TrieNode> root;
	Trie();
	bool search(const std::string word);
	void insert(const std::string word);
};
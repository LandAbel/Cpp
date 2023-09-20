#include "Trie.h"

Trie::Trie() 
{
	root = std::make_unique<TrieNode>();
}

void Trie::insert(const std::string word) 
{
	TrieNode* curr = root.get();
	for (char c:word)
	{
		if (curr->children.find(c)==curr->children.end())
		{
			curr->children[c] = std::make_unique<TrieNode>();
		}
		curr = curr->children[c].get();
	}
	curr->isEndOfWord = true;
}
bool Trie::search(const std::string word) 
{
	TrieNode* curr = root.get();
	for (char c : word)
	{
		if (curr->children.find(c) == curr->children.end())
		{
			return false;
		}
		curr = curr->children[c].get();
	}
	curr->isEndOfWord = true;
}



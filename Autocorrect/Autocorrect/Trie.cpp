#include "Trie.h"

// Функция создания нового узла Trie
TrieNode* getNewTrieNode()
{
	TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

// Функция получения всех слов в Trie
void getAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& words)
{
	if (node == nullptr) {
		return;
	}

	if (node->isEndOfWord) {
		words.push_back(prefix);
	}

	for (char c = 'a'; c <= 'z'; c++) {
		int index = c - 'a';
		getAllWords(node->children[index], prefix + c, words);
	}
}

void insert(TrieNode* root, const std::string& key)
{
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			node->children[index] = getNewTrieNode();
		node = node->children[index];
	}

	node->isEndOfWord = true;
}

bool isTrieEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
			return false;
	}
	return true;
}


void addWordInVector(TrieNode* root, std::vector<std::string>& result, char buf[], int ind)
{
		if (root->isEndOfWord)
		{
			buf[ind] = '\0';
			result.push_back(std::string(buf));
		}

		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (root->children[i])
			{
				buf[ind] = i + 'a';
				addWordInVector(root->children[i], result, buf, ind + 1);
			}
		}
}

std::vector<std::string> getAllWordsByPrefix(TrieNode* root, const std::string& prefix)
{
	std::vector<std::string> result;
	if (!root)
		return result;

	TrieNode* node = root;
	char buf[ALPHABET_SIZE] = {};
	int ind = 0;

	for (int i = 0; i < prefix.length(); i++)
	{
		int index = prefix[i] - 'a';
		buf[ind] = prefix[i];
		ind++;
		if (!node->children[index])
			return result;

		node = node->children[index];
	}

	addWordInVector(node, result, buf, ind);
	return result;
}
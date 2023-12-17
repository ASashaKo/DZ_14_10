#pragma once
#include <iostream>
#include <string>
#include <vector>
#define ALPHABET_SIZE 26

struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TrieNode* getNewTrieNode();
void getAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& words);
void insert(TrieNode* root, const std::string& key);
bool isTrieEmpty(TrieNode* root);
std::vector<std::string> getAllWordsByPrefix(TrieNode* root, const std::string& prefix);


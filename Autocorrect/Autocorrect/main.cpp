#include "Trie.h"



int main() {
	setlocale(LC_ALL, "Russian");
	TrieNode* root = getNewTrieNode();

	insert(root, "cat");
	insert(root, "call");
	insert(root, "march");
	insert(root, "mum");
	insert(root, "morning");
	insert(root, "monkey");
	insert(root, "control");
	insert(root, "big");
	insert(root, "by");

	int c;
	std::vector<std::string> words;

	do {
		std::cout << "1 - Добавить слово в словарь" << std::endl << "2 - Поиск слов по префиксу" << std::endl;
		std::cin >> c;
		switch (c)
		{
		case 1:
		{
			std::string word;
			std::cin >> word;
			if (word.size() < 1) {
				std::cout << "Введите снова" << std::endl;
				break;
			}
			else {
				insert(root, word);
				getAllWords(root, "", words);
				for (const auto& word : words) {
					std::cout << word << " " << "\n";
				}
				break;
			}
		}

		case 2:
		{
			std::string pref;
			std::cin >> pref;
				if (pref.size() < 1) {
					std::cout << "Введите снова" << std::endl;
					break;
				}
				else {
					std::vector<std::string> words = getAllWordsByPrefix(root, pref);
					for (const std::string& word : words) {
						std::cout << word << " ";
					}
					std::cout << std::endl;
				}
		}
		}
	} while (c < 3 || c > 0);
		return 0;
}
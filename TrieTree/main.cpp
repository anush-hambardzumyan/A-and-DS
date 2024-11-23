#include "TrieTree.h"
#include "TrieTree.hpp"
#include <iostream>

int main() {
    TrieTree trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insertRecursive("banana");

    std::cout << std::boolalpha;
    std::cout << "Search 'apple': " << trie.searchWord("apple") << "\n";   // true
    std::cout << "Search 'app': " << trie.searchWord("app") << "\n";       // true
    std::cout << "Search 'banana': " << trie.searchWordRecursive("banana") << "\n"; // true
    std::cout << "Search 'bat': " << trie.searchWord("bat") << "\n";       // false

    return 0;
}

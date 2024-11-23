#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include <unordered_map>
#include <string>

class TrieTree {
private:
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool isWord = false;
    };

    TrieNode* root{nullptr};

    // Helper Functions
    void insertRecursiveHelper(TrieNode* node, const std::string& word, int currIdx);
    bool searchWordRecursiveHelper(TrieNode* node, const std::string& word, int currIdx);
    bool searchPrefixRecursiveHelper(TrieNode* node, const std::string& pref, int currIdx);
    bool removeWordHelper(TrieNode* node, const std::string& word, int currIdx);

public:
    // Constructor
    TrieTree();

    // Insert Functions
    void insert(const std::string& word);
    void insertRecursive(const std::string& word);

    // Search Functions
    bool searchWord(const std::string& word);
    bool searchWordRecursive(const std::string& word);
    bool searchPrefix(const std::string& pref);
    bool searchPrefixRecursive(const std::string& pref);

    // Remove Functions
    bool removeWordHelper(const std::string& word);
};

#include "TrieTree.hpp"

#endif // TRIE_TREE_H

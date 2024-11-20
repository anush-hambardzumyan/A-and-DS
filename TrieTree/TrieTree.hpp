#include <iostream>
#include <unordered_map>
#include <string>

class TrieTree {
    private:
        struct TrieNode {
            std::unordered_map<char, TrieNode*> children;
            bool isWord;
        };

        TrieNode* root{nullptr};

    public:
        TrieTree() {
            root = new TrieNode();
        }


        void insert(const std::string& word) {
            TrieNode* curr = root;
            for (char c : word) {
                if (!curr -> children.contains(c)) {
                    curr -> children[c] = new TrieNode();
                }
                curr = curr -> children[c];
            }
            curr -> isWord = true;
        }

        void insertRecursiveHelper(TrieNode* node, const std::string& word, int currIdx) {
            if (currIdx == word.size()) {
                node -> isWord = true;
                return;
            }

            char c = word[currIdx];
            if (!node -> children.contains(c)) {
                node -> children[c] = new TrieNode();
            }
            insertRecursiveHelper(node -> children[c], word, currIdx + 1);
        }

        void insertRecursive(const std::string& word) {
            insertRecursiveHelper(root, word, 0);
        }


        bool searchWordRecursiveHelper(TrieNode* node, const std::string& word, int currIdx) {
            if (currIdx == word.size()) {
                return node -> isWord;
            }

            TrieNode* tmp = node -> children[word[currIdx]];
            if (!tmp) 
                return false;

            return searchWordRecursiveHelper(tmp, word, currIdx + 1);
        }

        bool searchWordRecursive(const std::string& word) {
            return searchWordRecursiveHelper(root, word, 0);
        }

        bool searchWord(const std::string& word) {
            TrieNode* curr = root;
            int i = 0;
            for (char c : word) {
                if (!curr -> children.contains(c)) {
                    return false;
                }
                curr = curr -> children[c];
            }
            return curr -> isWord;
        }

        bool searchPrefixRecursiveHelper(TrieNode* node, const std::string& pref, int currIdx) {
            if (currIdx == pref.size()) {
                return true;
            }

            TrieNode* tmp = node -> children[pref[currIdx]];
            if (!tmp) 
                return false;

            return searchPrefixRecursiveHelper(tmp, pref, currIdx + 1);
        }

        bool searchPrefixRecursive(const std::string& pref) {
            return searchPrefixRecursiveHelper(root, pref, 0);
        }

        bool searchPrefix(const std::string& pref) {
            TrieNode* curr = root;
            for (char c : pref) {
                if (!curr -> children.contains(c)) {
                    return false;
                }
                curr = curr -> children[c];
            }
            return true;
        }

        bool removeWordHelper(TrieNode* node, const std::string& word, int currIdx) {
            if (currIdx == word.size()) {
                if (!node -> isWord) {
                    return false;
                }
                node -> isWord = false;
                return node -> children.empty();
            }
            
            TrieNode* curr = node -> children[word[currIdx]];;
            if (!curr)
                return false;
            
            bool mustBeDeleted = removeWordHelper(curr, word, currIdx + 1);
            if (mustBeDeleted) {
                curr -> children.erase(word[currIdx]);;
                if (curr -> children.empty()) {
                    delete curr;
                    curr = nullptr;
                    return true;
                }
                return false;
            }
            return false;
        }
};
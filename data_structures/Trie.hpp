#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <vector>
#include <algorithm>

namespace data_structures {

/**
 * @brief Trie Node representing each character.
 */
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    /**
     * @brief Constructor initializes children and end flag.
     */
    TrieNode();
};

/**
 * @brief Trie data structure supporting insert, search, and prefix queries.
 */
class Trie {
private:
    TrieNode* root;

public:
    /**
     * @brief Constructor initializes the root node.
     */
    Trie();

    /**
     * @brief Destructor to free the memory.
     */
    ~Trie();

    /**
     * @brief Inserts a word into the trie.
     * @param word The word to be inserted.
     */
    void insert(const std::string& word);

    /**
     * @brief Searches for a word in the trie.
     * @param word The word to be searched.
     * @return True if the word exists, false otherwise.
     */
    bool search(const std::string& word);

    /**
     * @brief Checks if any word in the trie starts with the given prefix.
     * @param prefix The prefix to check.
     * @return True if any word starts with the prefix, false otherwise.
     */
    bool startsWith(const std::string& prefix);

    /**
     * @brief Deletes a word from the trie.
     * @param word The word to delete.
     * @return True if the word was found and deleted, false otherwise.
     */
    bool remove(const std::string& word);

    /**
     * @brief Lists all words in the trie with the given prefix.
     * @param prefix The prefix to search.
     * @return A vector of all words starting with the given prefix.
     */
    std::vector<std::string> listWordsWithPrefix(const std::string& prefix);

    /**
     * @brief Lists all words stored in the trie.
     * @return A vector of all words.
     */
    std::vector<std::string> listAllWords();

    /**
     * @brief Counts the total number of complete words stored in the trie.
     * @return Total word count.
     */
    int countWords();

    /**
     * @brief Counts how many words start with a given prefix.
     * @param prefix The prefix to search.
     * @return Number of words starting with the prefix.
     */
    int countPrefix(const std::string& prefix);

    /**
     * @brief Checks if the trie is empty.
     * @return True if trie is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Returns the longest common prefix among all inserted words.
     * @return The longest common prefix string.
     */
    std::string longestCommonPrefix();

private:
    void destroy(TrieNode* node);
    bool removeHelper(TrieNode* node, const std::string& word, int depth);
    void dfsWords(TrieNode* node, std::string current, std::vector<std::string>& result);
    int countWordsHelper(TrieNode* node);
    int countPrefixHelper(TrieNode* node);
    bool isEmptyHelper(TrieNode* node);
    std::string longestCommonPrefixHelper(TrieNode* node);
};
TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; ++i) children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    destroy(root);
}

void Trie::destroy(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; ++i)
        destroy(node->children[i]);
    delete node;
}

void Trie::insert(const std::string& word) {
    TrieNode* curr = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (!curr->children[idx])
            curr->children[idx] = new TrieNode();
        curr = curr->children[idx];
    }
    curr->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* curr = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (!curr->children[idx])
            return false;
        curr = curr->children[idx];
    }
    return curr->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* curr = root;
    for (char ch : prefix) {
        int idx = ch - 'a';
        if (!curr->children[idx])
            return false;
        curr = curr->children[idx];
    }
    return true;
}

bool Trie::remove(const std::string& word) {
    return removeHelper(root, word, 0);
}

bool Trie::removeHelper(TrieNode* node, const std::string& word, int depth) {
    if (!node) return false;

    if (depth == word.size()) {
        if (!node->isEndOfWord) return false;
        node->isEndOfWord = false;

        for (int i = 0; i < 26; ++i)
            if (node->children[i]) return true;

        return false;
    }

    int idx = word[depth] - 'a';
    if (!node->children[idx] || !removeHelper(node->children[idx], word, depth + 1))
        return false;

    delete node->children[idx];
    node->children[idx] = nullptr;

    return !node->isEndOfWord && std::all_of(std::begin(node->children), std::end(node->children), [](TrieNode* child) { return child == nullptr; });
}

std::vector<std::string> Trie::listWordsWithPrefix(const std::string& prefix) {
    TrieNode* curr = root;
    for (char ch : prefix) {
        int idx = ch - 'a';
        if (!curr->children[idx])
            return {};
        curr = curr->children[idx];
    }

    std::vector<std::string> result;
    dfsWords(curr, prefix, result);
    return result;
}

void Trie::dfsWords(TrieNode* node, std::string current, std::vector<std::string>& result) {
    if (!node) return;
    if (node->isEndOfWord)
        result.push_back(current);
    for (int i = 0; i < 26; ++i) {
        if (node->children[i])
            dfsWords(node->children[i], current + char('a' + i), result);
    }
}

std::vector<std::string> Trie::listAllWords() {
    std::vector<std::string> result;
    dfsWords(root, "", result);
    return result;
}

int Trie::countWords() {
    return countWordsHelper(root);
}

int Trie::countWordsHelper(TrieNode* node) {
    if (!node) return 0;
    int count = node->isEndOfWord ? 1 : 0;
    for (int i = 0; i < 26; ++i)
        count += countWordsHelper(node->children[i]);
    return count;
}

int Trie::countPrefix(const std::string& prefix) {
    TrieNode* curr = root;
    for (char ch : prefix) {
        int idx = ch - 'a';
        if (!curr->children[idx]) return 0;
        curr = curr->children[idx];
    }
    return countPrefixHelper(curr);
}

int Trie::countPrefixHelper(TrieNode* node) {
    if (!node) return 0;
    int count = node->isEndOfWord ? 1 : 0;
    for (int i = 0; i < 26; ++i)
        count += countPrefixHelper(node->children[i]);
    return count;
}

bool Trie::isEmpty() {
    return isEmptyHelper(root);
}

bool Trie::isEmptyHelper(TrieNode* node) {
    if (node->isEndOfWord) return false;
    for (int i = 0; i < 26; ++i)
        if (node->children[i]) return false;
    return true;
}

std::string Trie::longestCommonPrefix() {
    return longestCommonPrefixHelper(root);
}

std::string Trie::longestCommonPrefixHelper(TrieNode* node) {
    std::string prefix;
    TrieNode* curr = node;

    while (curr) {
        int childrenCount = 0;
        int index = -1;

        for (int i = 0; i < 26; ++i) {
            if (curr->children[i]) {
                childrenCount++;
                index = i;
            }
        }

        if (childrenCount != 1 || curr->isEndOfWord) break;

        prefix += char('a' + index);
        curr = curr->children[index];
    }

    return prefix;
}
}
#endif // TRIE_H

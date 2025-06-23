/**
 * @author      Vaibhav Jindal
 *              B.Tech CSE Core, VIT Bhopal
 * 
 * @details     Modular, templated C++ library for 
 *              educational, research, and production use.
 * 
 * 📦 Namespace: data_structures
 * 📧 Contact  : jindalvaibhav63@gmail.com
 */

#include <iostream>
#include "../data_structures/Trie.hpp"


using namespace std;
using namespace data_structures;

void printVector(const vector<string>& vec) {
    for (const auto& word : vec) {
        cout << word << endl;
    }
}

int main() {
    Trie trie;

    // Basic insertions
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");
    trie.insert("bat");
    trie.insert("ball");
    trie.insert("batter");
    trie.insert("batman");

    // --------------------------
    cout << "=== SEARCH TEST ===" << endl;
    cout << "Search 'app': " << trie.search("app") << endl;
    cout << "Search 'appl': " << trie.search("appl") << endl;
    cout << "Search 'batman': " << trie.search("batman") << endl;

    // --------------------------
    cout << "\n=== PREFIX TEST ===" << endl;
    cout << "StartsWith 'ap': " << trie.startsWith("ap") << endl;
    cout << "StartsWith 'bat': " << trie.startsWith("bat") << endl;
    cout << "StartsWith 'cat': " << trie.startsWith("cat") << endl;

    // --------------------------
    cout << "\n=== LIST WORDS WITH PREFIX 'bat' ===" << endl;
    vector<string> batWords = trie.listWordsWithPrefix("bat");
    printVector(batWords);

    // --------------------------
    cout << "\n=== LIST ALL WORDS ===" << endl;
    vector<string> allWords = trie.listAllWords();
    printVector(allWords);

    // --------------------------
    cout << "\n=== COUNT TESTS ===" << endl;
    cout << "Total Words: " << trie.countWords() << endl;
    cout << "Words with prefix 'ba': " << trie.countPrefix("ba") << endl;
    cout << "Words with prefix 'app': " << trie.countPrefix("app") << endl;
    cout << "Words with prefix 'z': " << trie.countPrefix("z") << endl;

    // --------------------------
    cout << "\n=== EMPTY CHECK ===" << endl;
    cout << "Is Trie Empty: " << trie.isEmpty() << endl;

    // --------------------------
    cout << "\n=== LONGEST COMMON PREFIX ===" << endl;
    cout << "LCP: " << trie.longestCommonPrefix() << endl;

    // --------------------------
    cout << "\n=== DELETE TEST ===" << endl;
    cout << "Delete 'batman': " << trie.remove("batman") << endl;
    cout << "Delete 'xyz' (not present): " << trie.remove("xyz") << endl;
    cout << "After Deleting 'batman':" << endl;
    printVector(trie.listAllWords());

    // Final cleanup test
    cout << "\nFinal Word Count: " << trie.countWords() << endl;
    
    cout<<"All tests completed.";
    return 0;
}

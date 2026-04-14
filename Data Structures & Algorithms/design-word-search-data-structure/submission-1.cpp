
#include <map>
#include <string>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() : root(new TrieNode()) {}

    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            // operator[] will insert key with nullptr if absent
            if (cur->children[c] == nullptr) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }

    bool search(const string& word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(const string& word, int pos, TrieNode* node) {
        TrieNode* cur = node;

        for (int i = pos; i < (int)word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                // Try all children from the current node
                for (auto& kv : cur->children) {
                    TrieNode* child = kv.second;
                    if (child && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                // Use operator[]; if absent, this creates a nullptr entry.
                TrieNode* next = cur->children[c];
                if (next == nullptr) {
                    return false; // no path for this character
                }
                cur = next;
            }
        }
        return cur->word;
    }
};
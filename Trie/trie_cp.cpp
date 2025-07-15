#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26] = {nullptr};
    bool isTerminal = false;
};

class Trie {
    TrieNode* root;

    void collectWords(TrieNode* node, string& path, vector<string>& result) {
        if (node->isTerminal)
            result.push_back(path);
        for (int i = 0; i < 26; ++i) {
            if (node->child[i]) {
                path.push_back('a' + i);
                collectWords(node->child[i], path, result);
                path.pop_back(); // backtrack
            }
        }
    }

    bool deleteUtil(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isTerminal) return false;
            node->isTerminal = false;

            for (int i = 0; i < 26; ++i)
                if (node->child[i])
                    return false;

            return true; // delete this node
        }

        int idx = word[depth] - 'a';
        if (deleteUtil(node->child[idx], word, depth + 1)) {
            delete node->child[idx];
            node->child[idx] = nullptr;

            return !node->isTerminal &&
                   all_of(begin(node->child), end(node->child), [](TrieNode* ptr) { return ptr == nullptr; });
        }

        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root; 
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isTerminal = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return node->isTerminal;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return true;
    }

    void deleteWord(const string& word) {
        deleteUtil(root, word, 0);
    }

    vector<string> getWordsWithPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->child[idx])
                return {}; // no such prefix
            node = node->child[idx];
        }

        vector<string> result;
        string path = prefix;
        collectWords(node, path, result);
        return result;
    }
};


int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("ape");
    trie.insert("bat");
    trie.insert("batman");

    cout << trie.search("app") << "\n";     // 1
    cout << trie.startsWith("ba") << "\n";  // 1

    trie.deleteWord("bat");
    cout << trie.search("bat") << "\n";     // 0

    vector<string> words = trie.getWordsWithPrefix("ap");
    for (string& s : words)
        cout << s << "\n"; // ape, app, apple

    return 0;
}

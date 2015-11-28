// Implement Trie (Prefix Tree)

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() { }
    TrieNode* next[26] = {NULL};
    bool flags[26] = {false};
    ~TrieNode() {
        for(auto n: next) {
            delete n;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        size_t len = word.size();
        TrieNode* p = root;
        for(size_t i=0; i< len; i++) {
            if(p -> next[word[i] - 'a'] == NULL) {
                p -> next[word[i] - 'a'] = new TrieNode();
            }
            p = p -> next[word[i] - 'a'];
        }
        p -> flags[word.at(len-1) - 'a'] = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        size_t len = word.size();
        TrieNode* p = find(root, word);
        if(p == NULL || !p -> flags[word[len-1] - 'a']) return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = find(root, prefix);
        if(p == NULL) return false;
        return true;
    }

private:
    TrieNode* root;
    TrieNode* find(TrieNode* root, string word) {
        for(size_t i=0; i< word.size() && root != NULL; i++) {
            root = root -> next[word[i] - 'a'];
        }
        return root;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

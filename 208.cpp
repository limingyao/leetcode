// Implement Trie (Prefix Tree)

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        
    }
    TrieNode* next[26] = {NULL};
    bool flags[26] = {false};
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
        for(int i=0; i< len; i++) {
            if(p -> next[word.at(i) - 'a'] == NULL) {
                p -> next[word.at(i) - 'a'] = new TrieNode();
                p = p -> next[word.at(i) - 'a'];
            } else {
                p = p -> next[word.at(i) - 'a'];
            }
        }
        p -> flags[word.at(len-1) - 'a'] = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        size_t len = word.size();
        TrieNode* p = root;
        for(int i=0; i< len; i++) {
            if(p -> next[word.at(i) - 'a'] != NULL) {
                p = p -> next[word.at(i) - 'a'];
            } else {
                return false;
            }
        }
        if(!p -> flags[word.at(len-1) - 'a']) return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        size_t len = prefix.size();
        TrieNode* p = root;
        for(int i=0; i< len; i++) {
            if(p -> next[prefix.at(i) - 'a'] != NULL) {
                p = p -> next[prefix.at(i) - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

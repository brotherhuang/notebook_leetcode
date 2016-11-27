/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

Subscribe to see which companies asked this question*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
    }
    bool isNode = false;
    TrieNode *children[26] = {NULL};
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->isNode = 1;
    }

    bool search(string &word, bool isPrefix) {
        TrieNode *current = root;
        for (auto c : word) {
            int index = c - 'a';
            if (current->children[index] == NULL)
                return false;
            current = current->children[index];
        }
        return isPrefix || current->isNode;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return search(word, false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return search(prefix, true);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

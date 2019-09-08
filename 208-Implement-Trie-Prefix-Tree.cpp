class Node
{
public:
    bool k;
    Node *next[26];
    Node()
    {
        k = false;
        for(int i = 0; i < 26; ++i)
        {
            next[i] = NULL;
        }
    }
};

class Trie {
public:

    /** Initialize your data structure here. */
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *p = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(p -> next[word[i] - 'a'] == NULL) 
            {
                p -> next[word[i] - 'a'] = new Node();
            }
            p = p -> next[word[i] - 'a'];
        }
        p -> k = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *p = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(p -> next[word[i] - 'a'] == NULL)
            {
                return false;
            }
            p = p -> next[word[i] - 'a'];
        }
        
        return p -> k;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *p = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            if(p -> next[prefix[i] - 'a'] == NULL) return false;
            p = p -> next[prefix[i] - 'a'];
        }
        
        return true;
    }
private:
    bool k;
    Trie *next[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Runtime: 76 ms, faster than 64.69% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 44.8 MB, less than 56.67% of C++ online submissions for Implement Trie (Prefix Tree).

// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

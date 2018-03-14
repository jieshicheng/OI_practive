#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

class TrieNode {
public:
    TrieNode() : list(26, nullptr), is_word(false) { }
    vector<TrieNode *> list;
    bool is_word;
};



class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *iter = root;
        for( int i = 0; i != word.size(); ++i ) {
            if( iter->list[word[i] - 'a'] == nullptr ) {
                iter->list[word[i] - 'a'] = new TrieNode;
            }
            iter = iter->list[word[i] - 'a'];
        }
        iter->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *iter = root;
        for( int i = 0; i != word.size(); ++i ) {
            if( iter->list[word[i] - 'a'] == nullptr )
                return false;
            iter = iter->list[word[i] - 'a'];
        }
        return iter->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *iter = root;
        for( int i = 0; i != prefix.size(); ++i ) {
            if( iter->list[prefix[i] - 'a'] == nullptr )
                return false;
            iter = iter->list[prefix[i] - 'a'];
        }
        if( iter )
            return true;
        else 
            return false;
    }	
};

int main() {
	return 0;
}


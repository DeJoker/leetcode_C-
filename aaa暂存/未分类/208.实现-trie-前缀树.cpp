/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "../common/debugger.h"

// @lc code=start
class Trie {
public:
    map<char, Trie*> _mmap;
    bool valid = false;
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        map<char, Trie*>* mmap = &_mmap;
        Trie* last = this;
        for(auto& c : word) {
            if ((*mmap)[c] == nullptr) {
                (*mmap)[c] = new Trie();
            }
            last = (*mmap)[c];
            mmap = &((*mmap)[c]->_mmap);
        }
        last->valid = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        map<char, Trie*>* mmap = &_mmap;
        Trie* last = this;
        for(auto& c : word) {
            if (mmap->find(c) != mmap->end()) {
                last = (*mmap)[c];
                mmap = &((*mmap)[c]->_mmap);
            } else {
                return false;
            }
        }
        if (last && last->valid) {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        map<char, Trie*>* mmap = &_mmap;
        for(auto& c : prefix) {
            if (mmap->find(c) != mmap->end()) {
                mmap = &((*mmap)[c]->_mmap);
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main() {
    Trie trie;

    trie.insert("apple");
    LOG_DEBUG << trie.search("apple");   // 返回 true
    LOG_DEBUG << trie.search("app");     // 返回 false
    LOG_DEBUG << trie.startsWith("app"); // 返回 true
    trie.insert("app");   
    LOG_DEBUG << trie.search("app");     // 返回 true
}
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include "../common/debugger.h"

// @lc code=start
class LRUCache {
struct Node {
    int key, val;
    Node(int k, int v) :
        key(k), val(v)
    {}
};

public:
    int _cap;
    // 
    list<Node> _recent;
    map<int, list<Node>::iterator> _kv;

    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto iter = _kv.find(key);
        if (_kv.find(key) == _kv.end()) return -1;

        auto node = *(iter->second);
        _recent.erase(iter->second);
        _recent.push_front(node);
        _kv[key] = _recent.begin();

        return node.val;
    }
    
    void put(int key, int value) {
        Node n(key, value);

        auto iter = _kv.find(key);
        if (_kv.find(key) == _kv.end()) {
            if (_cap == _kv.size()) {
                Node& del = _recent.back();
                _kv.erase(del.key);
                _recent.pop_back();
            }
            _recent.push_front(n);
            _kv[key] = _recent.begin();
        } else {
            auto listIt = iter->second;
            _kv.erase(key);
            _recent.erase(listIt);
            //  AddressSanitizer: heap-use-after-free 
            // _recent.erase(iter->second);
            _recent.push_front(n);
            _kv[key] = _recent.begin();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache lRUCache(2);
    // lRUCache.put(1, 1); // 缓存是 {1=1}
    // lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    // lRUCache.get(1);    // 返回 1
    // lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    // lRUCache.get(2);    // 返回 -1 (未找到)
    // lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // lRUCache.get(1);    // 返回 -1 (未找到)
    // lRUCache.get(3);    // 返回 3
    // lRUCache.get(4);    // 返回 4


    // ["LRUCache","put","put","get","put","put","get"]
    // [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
    lRUCache.put(2, 1);
    lRUCache.put(2, 2);
    lRUCache.get(2);
    lRUCache.put(1, 1);
    lRUCache.put(4, 2);
    lRUCache.get(2);
}



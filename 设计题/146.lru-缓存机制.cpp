/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include "../common/debugger.h"

// @lc code=start


class LRUCache {
    int cap;
    map<int, list<pair<int, int>>::iterator> mp;
    // 需要pair，因为put的时候淘汰需要删除key
    list<pair<int, int>> recent;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    // 无论是get还是put  map和list的操作都是删除然后添加
    int get(int key) {
        if (mp.find(key)==mp.end()) {
            return -1;
        }
        
        // 注意迭代器失效，先取值，list只有删除的迭代器失效
        pair<int, int> node = *mp[key];
        recent.erase(mp[key]);
        // 迭代器失效有两方面，还有map指向的迭代器也需要有效
        recent.push_front(node);
        mp[key] = recent.begin();

        return node.second;
    }

    // 如果是相同key只删map
    void put(int key, int value) {
        auto node = make_pair(key, value);
        // 还要考虑等值的情况
        if (mp.find(key) != mp.end()) {
            recent.erase(mp[key]);
            mp.erase(key);
        } else if (mp.size() == cap) {
            // list为什么需要是pair的原因：弹出头要把mp对应的删除
            auto last = *recent.rbegin();
            mp.erase(last.first);
            recent.pop_back();
        }

        recent.push_front(node);
        mp[key] = recent.begin();
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
    // LRUCache lRUCache(2);
    // lRUCache.put(1, 1); // 缓存是 {1=1}
    // lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    // LOG_DEBUG << lRUCache.get(1);    // 返回 1
    // lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    // LOG_DEBUG << lRUCache.get(2);    // 返回 -1 (未找到)
    // lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // LOG_DEBUG << lRUCache.get(1);    // 返回 -1 (未找到)
    // LOG_DEBUG << lRUCache.get(3);    // 返回 3
    // LOG_DEBUG << lRUCache.get(4);    // 返回 4


    LRUCache l2(2);
    l2.put(2, 1);
    l2.put(1, 1);
    LOG_DEBUG << l2.get(2);    // 返回 1
    l2.put(4, 1);
    LOG_DEBUG << l2.get(1);    // 返回 -1
    LOG_DEBUG << l2.get(2);    // 返回 1
}

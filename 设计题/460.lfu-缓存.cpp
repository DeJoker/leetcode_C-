/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include "../common/debugger.h"

// @lc code=start

// 插入相同key，居然是freq+1  ....
class LFUCache {
    map<int, list<tuple<int, int, int>>::iterator> mp;
    // count -> <key value count>  （访问次数）
    map<int, list<tuple<int, int, int>>> freq;
    int cap;
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end()) {
            return -1;
        }

        auto it = mp[key];
        auto node = *mp[key];
        int& cnt = std::get<2>(node);
        cnt++;

        mp.erase(key);
        freq[cnt-1].erase(it);
        if (freq[cnt-1].empty()) {
            freq.erase(cnt-1);
        }
        freq[cnt].push_front(node);
        mp[key] = freq[cnt].begin();

        return std::get<1>(node);
    }
    
    void put(int key, int value) {
        if (cap==0) return;
        if (mp.find(key)==mp.end()) {
            auto node = make_tuple(key, value, 1);
            put(node);
            return;
        }

        auto it = mp[key];
        int cnt = std::get<2>(*mp[key]);
        freq[cnt].erase(it);
        mp.erase(key);
        if (freq[cnt].empty()) {
            freq.erase(cnt);
        }
        auto node = make_tuple(key, value, cnt+1);
        put(node);
    }
private:
    void put(tuple<int, int, int>& node) {
        int cnt = std::get<2>(node);
        int key = std::get<0>(node);
        if (mp.size() == cap) {
            // int minCnt = freq.begin()->first;
            auto& minList = freq.begin()->second;
            int delKey = std::get<0>(*minList.rbegin());

            mp.erase(delKey);
            minList.pop_back();
            if (minList.empty()) {
                freq.erase(freq.begin());
            }
        }
        freq[cnt].push_front(node);
        mp[key] = freq[cnt].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LFUCache lFUCache(2);
    lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
    lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    LOG_DEBUG << lFUCache.get(1);      // 返回 1
                        // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                        // cache=[3,1], cnt(3)=1, cnt(1)=2
    LOG_DEBUG << lFUCache.get(2);      // 返回 -1（未找到）
    LOG_DEBUG << lFUCache.get(3);      // 返回 3
                        // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                        // cache=[4,3], cnt(4)=1, cnt(3)=2
    LOG_DEBUG << lFUCache.get(1);      // 返回 -1（未找到）
    LOG_DEBUG << lFUCache.get(3);      // 返回 3
                        // cache=[3,4], cnt(4)=1, cnt(3)=3
    LOG_DEBUG << lFUCache.get(4);      // 返回 4
                        // cache=[3,4], cnt(4)=2, cnt(3)=3


    LFUCache l(0);
    l.put(0,0);
    LOG_DEBUG << l.get(0);
}

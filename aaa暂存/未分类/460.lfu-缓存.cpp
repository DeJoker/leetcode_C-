/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include "../common/debugger.h"

// @lc code=start
class LFUCache3333 {
public:
    list<pair<int, int>> _recent;
    map<int, list<pair<int, int>>::iterator> _kv;
    int _cap;

    LFUCache3333(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        if (_kv.find(key) != _kv.end()) {
            auto it = _kv[key];
            auto v = *it;
            _recent.erase(it);
            _recent.push_front(v);
            return v.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (_kv.find(key) != _kv.end()) {
            _recent.erase(_kv[key]);
        }
        _recent.push_front({key, value});
        _kv[key] = _recent.begin();

        if (_kv.size() > _cap) {
            auto kv = _recent.back();
            _kv.erase(kv.first);
            _recent.pop_back();
        }
    }
};



class LFUCache {
struct Node {
    int key, val, freq;
    Node(int k, int v, int f) :
        key(k), val(v), freq(f)
    {}
};

    int _minFreq, _cap;
    map<int, list<Node>::iterator> _kv;
    map<int, list<Node>> _freqTable;

public:
    LFUCache(int cap) {
        _cap = cap;
        _minFreq = 0;
    }


    int get(int key) {
        auto it = _kv.find(key);
        if (it == _kv.end())  return -1;

        Node s = *(it->second);
        _freqTable[s.freq].erase(it->second);
        // 这里minFreq自增1 是没有问题的，get当前也只会因为这次的访问而增加
        if (_freqTable[s.freq].size() == 0) {
            _freqTable.erase(s.freq);
            if (_minFreq == s.freq) _minFreq++;
        }

        s.freq++;
        _freqTable[s.freq].push_front(s);
        _kv[key] = _freqTable[s.freq].begin();

        return s.val;
    }

    void put(int key, int value) {
        if (_cap == 0) return;

        auto it = _kv.find(key);
        if (it != _kv.end()) {
            auto iter = it->second;

            // 清理原值
            int freq = iter->freq;
            _freqTable[freq].erase(iter);

            // 每次对空List都清理是
            if (_freqTable[freq].size() == 0) {
                _freqTable.erase(freq);
                if (freq == _minFreq) _minFreq += 1;
            }
            // 插入值
            _freqTable[freq+1].push_front(Node(key, value, freq+1));
            _kv[key] = _freqTable[freq+1].begin();

        } else {
            if (_kv.size() == _cap) {
                // 移除过期值
                Node s = _freqTable[_minFreq].back();
                _kv.erase(s.key);
                _freqTable[_minFreq].pop_back();

                // 每次对空List都清理是
                if (_freqTable[_minFreq].size() == 0) {
                    _freqTable.erase(_minFreq);
                }
            }
            // 插入值
            _freqTable[1].push_front(Node(key, value, 1));
            _kv[key] = _freqTable[1].begin();
            _minFreq = 1;
        }
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
    lFUCache.put(1, 1);
    lFUCache.put(2, 2);
    lFUCache.get(1);      // 返回 1
    lFUCache.put(3, 3);   // 去除键 2
    lFUCache.get(2);      // 返回 -1（未找到）
    lFUCache.get(3);      // 返回 3
    lFUCache.put(4, 4);   // 去除键 1
    lFUCache.get(1);      // 返回 -1（未找到）
    lFUCache.get(3);      // 返回 3
    lFUCache.get(4);      // 返回 4
}


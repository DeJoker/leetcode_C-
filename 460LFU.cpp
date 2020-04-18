#include "common/debugger.h"


class LFUCache {
// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};

    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        // key_table.clear();
        // freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            // freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                if (!freq_table[minfreq].empty())
                    freq_table[minfreq].pop_back();
                // if (freq_table[minfreq].size() == 0) {
                //     freq_table.erase(minfreq);
                // }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};


int main() {

    unordered_map<int, list<int>> aaa;
    aaa[3] = list<int>{6};
    aaa[3].pop_back();
    cout << aaa[3].back() << endl;
    aaa[3].clear();
    cout << aaa[3].back() << endl;

    LFUCache cache(2);

    // cache.put(1, 1);
    // cache.put(2, 2);
    // cout << cache.get(1) << endl;       // 返回 1
    // cache.put(3, 3);    // 去除 key 2
    // cout << cache.get(2) << endl;       // 返回 -1 (未找到key 2)
    // cout << cache.get(3) << endl;       // 返回 3


    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // 返回 1
    cache.put(3, 3);    // 去除 key 2
    cout << cache.get(2) << endl;       // 返回 -1 (未找到key 2)
    cout << cache.get(3) << endl;       // 返回 3
    cache.put(4, 4);    // 去除 key 1
    cout << cache.get(1) << endl;       // 返回 -1 (未找到 key 1)
    cout << cache.get(3) << endl;       // 返回 3
    cout << cache.get(4) << endl;       // 返回 4
}

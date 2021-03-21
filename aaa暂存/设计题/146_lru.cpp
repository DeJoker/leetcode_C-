#include "../common/debugger.h"

class LRUCache {
public:
    unordered_map<int, int> _kv;
    list<int> _cur;
    int _size;
    LRUCache(int capacity) {
        _size = capacity;
    }
    
    int get(int key) {
        if (_kv.find(key) != _kv.end())
            return _kv[key];
        return -1;
    }
    
    void put(int key, int value) {
        _kv[key] = value;
        _cur.push_back(key);
        if (_cur.size() > _size) {
            int del = _cur.front();
            _cur.pop_front();
            _kv.erase(del);
        }
    }
};

int main() {
    LRUCache a(2);
    a.put(1,1);
    a.put(2,2);
    a.put(3,3);

    cout << a.get(1) << endl;
    cout << a.get(2) << endl;
    cout << a.get(3) << endl;
}
#include "../common/debugger.h"

class Deduplicate {
    deque<uint64_t> _cache;
    int _maxSize;
public:
    Deduplicate (int n) : _maxSize(n)
    {}

    bool CheckSame(uint64_t msgId) {
        if (_cache.size() > _maxSize) {
            _cache.pop_front();
        }

        // 从后往前判断，最近的消息更容易重复
        bool ret = std::find(_cache.rbegin(), _cache.rend(), msgId) != _cache.rend();
        _cache.push_back(msgId);
        return ret;
    }
};


int main() {
    Deduplicate d(3);
    cout << d.CheckSame(2) << endl;
    cout << d.CheckSame(2) << endl;
    if (d.CheckSame(2))
        cout << "niamde";
    cout << d.CheckSame(3) << endl;
    cout << d.CheckSame(1) << endl;
    cout << d.CheckSame(4) << endl;
    cout << d.CheckSame(2) << endl;
}

#include "common/debugger.h"


class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> N;
        for(int i=0; i<n; ++i) {
            N.push_back(i);
        }

        auto iter = N.begin();
        while(N.size() != 1) {
            for(int i=0; i<m; i++) {
                if(iter != N.end())
                    ++iter;
                else
                    iter = N.begin();
            }
            // 保证迭代器始终有效的情况下删除？？
            N.erase(iter++);
            --iter;
        }
        return *N.begin();
    }
};

int main() {
    Solution sol;
    sol.lastRemaining(5,3);
}
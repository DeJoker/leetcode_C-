/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "../common/debugger.h"

// @lc code=start



class Solution {
public:
    void ShiftUp(vector<pair<int, int>>& heap, int last) {
        int son=last, dad=(last-1)/2;
        while (dad >= 0) {  // >= 跟Down一样因为这里有-1，而且向上肯定要遍历dad情况
            if (heap[son].second >= heap[dad].second) break;

            swap(heap[son], heap[dad]);
            son=dad; dad=(son-1)/2; 
        }
    }

    // 小顶堆
    void ShiftDown(vector<pair<int, int>>& heap, int start, int last) {
        int dad=start, son=2*start+1;
        while(son <= last) {
            if (son+1 <= last && heap[son+1].second < heap[son].second) ++son;
            if (heap[son].second >= heap[dad].second) break;

            swap(heap[son], heap[dad]);
            dad=son; son=2*dad+1;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        vector<pair<int, int>> heap;

        for(auto kv : occurrences) {
            if (heap.size() < k) {
                heap.push_back(kv);
                // 新插入是往上调整。。。。。。。
                    ShiftUp(heap, heap.size()-1);
            } else {
                if (kv.second > heap[0].second) {
                    heap[0] = kv;
                // 后调整是往下。。。。。。。
                ShiftDown(heap, 0, heap.size()-1);
                }
            }
        }

        vector<int> res;
        for(auto [fir, sec] : heap) {
            res.push_back(fir);
        }
        return res;
    }
};


class Solution2 {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};


// @lc code=end




// 数组内不需要有序，保证是k个高频就行了，不一定首元素最高频
int main() {
    vector<int> p, r;

    p = {1,1,1,2,2,3}; // p,3      1,2
    r = Solution().topKFrequent(p, 2);
    DebugVector(r);

    p = {1,}; // p,1      1
    r = Solution().topKFrequent(p, 1);
    DebugVector(r);


    p = {1,1,1,2,2,3}; // p,3      1,2
    r = Solution().topKFrequent(p, 2);
    DebugVector(r);

    p = {1,}; // p,1      1
    r = Solution().topKFrequent(p, 1);
    DebugVector(r);


    // ShiftUp 写了dad>0 忽略了dad=0
    p = {5,2,5,3,5,3,1,1,3}; // p,1      5,3
    r = Solution().topKFrequent(p, 2);
    DebugVector(r);

    // 插入是shiftUp、交换新元素是shiftDown
    p = {-1,1,4,-4,3,5,4,-2,3,-1}; // p,3     4,3,-1
    r = Solution().topKFrequent(p, 3);
    DebugVector(r);
}


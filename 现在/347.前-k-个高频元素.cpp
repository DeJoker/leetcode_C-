/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
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

class Solution222;



class Solution222 {
public:
    void sift_up(vector<vector<int>> &heap, int chlid){
        vector<int> val = heap[chlid];
        while (chlid >> 1 > 0 && val[1] < heap[chlid>>1][1]){
            heap[chlid] = heap[chlid>>1];
            chlid >>= 1;
        heap[chlid] = val;
        }
    }

    void sift_down(vector<vector<int>> &heap, int root, int k){
        vector<int> val = heap[root];
        while (root << 1 < k){
            int chlid = root << 1;
            // 注意这里位运算优先级要加括号
            if ((chlid|1) < k && heap[chlid|1][1] < heap[chlid][1]) chlid |= 1;
            if (heap[chlid][1] < val[1]){
                heap[root] = heap[chlid];
                root = chlid;
            }
            else break;
        }
        heap[root] = val;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> stat;
        for (auto &num : nums) stat[num]++;
        vector<vector<int>> vec_stat;
        for (auto &item : stat) vec_stat.push_back({item.first, item.second});

        vector<vector<int>> heap;
        heap.push_back({0, 0});
        for (int i = 0; i < k; i++){
            heap.push_back(vec_stat[i]);
            sift_up(heap, heap.size()-1);
        }

        for (int i = k; i < vec_stat.size(); i++){
            if (vec_stat[i][1] > heap[1][1]){
                heap[1] = vec_stat[i];
                sift_down(heap, 1, k+1);
            }
        }

        vector<int> result;
        for (int i = 1; i < k+1; i++) result.push_back(heap[i][0]);
        return result;
    }
};



int main() {
    vector<int> p, r;
    p = {1,1,1,2,2,3}; // p,3      1,2
    r = Solution().topKFrequent(p, 2);
    DebugVector(r);

    p = {1,}; // p,1      1
    r = Solution().topKFrequent(p, 1);
    DebugVector(r);


    p = {1,1,1,2,2,3}; // p,3      1,2
    r = Solution222().topKFrequent(p, 2);
    DebugVector(r);

    p = {1,}; // p,1      1
    r = Solution222().topKFrequent(p, 1);
    DebugVector(r);
}


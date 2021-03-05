/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "../common/debugger.h"



// @lc code=start

bool cmp(int a, int b) {
    return a>b;
}

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // greater是小顶栈
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);

        for (auto n : nums) {
            if (pq.size() == k && pq.top() >= n) continue;
            if (pq.size() == k) {
                pq.pop();
            }
            pq.push(n);
        }
        return pq.top();
    }
};


// [2,1]  2     未通过
class Solution {
public:

int k;

void ShiftUp(vector<int>& heap, int son) {
    int val = heap[son];
    int dad=son/2;
    while(dad>0 && heap[dad] > val) {
        heap[son] = heap[dad];
        son=dad; dad=dad/2;
        heap[son] = val;
    }
}

void ShiftDown(vector<int>& heap, int start) {
    int val = heap[start];
    int dad=start, son=start*2;
    while(son < k) {
        if (son+1<k && heap[son+1] < heap[son]) ++son;
        if (heap[son] >= val) break;
        heap[dad] = heap[son];
        dad=son; son=2*son;
    }
    heap[dad] = val;
}

int findKthLargest(vector<int>& nums, int k) {
    this->k = k;

    vector<int> heap;
    for(int i=0; i<k; i++) {
        heap.push_back(nums[i]);
        ShiftUp(heap, i);
    }
    
    for(int i=k-1; i<nums.size(); i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            ShiftDown(heap, 0);
        }
    }
    return heap[0];
}
};
// @lc code=end





int main() {
    vector<int> p;
    p = {3,2,1,5,6,4};
    LOG_DEBUG << Solution().findKthLargest(p, 2);
    // LOG_DEBUG << Heap().findKthLargest(p, 2);

    p = {3,2,3,1,2,4,5,5,6};
    LOG_DEBUG << Solution().findKthLargest(p, 4);
    // LOG_DEBUG << Heap().findKthLargest(p, 4);
}

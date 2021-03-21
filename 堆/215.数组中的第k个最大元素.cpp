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


// swap
class Solution {
public:
    void ShiftUp(vector<int>& heap, int son) { // son相当于新加入的，调整到合适位置
        int dad=(son-1)/2;
        while (dad>=0) { // 因为是新加入原来的已经有序，因此这里如果到合理位置立即结束
            if (heap[son] >= heap[dad]) break;
            swap(heap[son], heap[dad]);
            son=dad; dad=(son-1)/2;
        }
    }

    void ShiftDown(vector<int>& heap, int dad, int last) {
        int son=2*dad+1;
        while(son <= last) {
            if (son+1 <= last && heap[son]>heap[son+1]) son++;
            if (heap[son] >= heap[dad]) break;

            swap(heap[son], heap[dad]);
            dad=son; son=2*dad+1;
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        for(auto num : nums) {
            if (heap.size()==k && num <= heap[0]) continue;
            if (heap.size() < k) {
                heap.push_back(num);
                ShiftUp(heap, heap.size()-1);
            } else {
                heap[0]=num;
                ShiftDown(heap, 0, heap.size()-1);
            }
        }
        return heap[0];
    }
};

// 自己完成重写
class SolutionMMM {
public:
    void ShiftUp(vector<int>& heap, int son) { // son相当于新加入的，调整到合适位置
        int val=heap[son];
        int dad=(son-1)/2;
        while (dad>=0 && heap[dad]>val) { // 因为是新加入原来的已经有序，因此这里如果到合理位置立即结束
            // 给下面赋更大的值，然后上面为刚才的val
            heap[son] = heap[dad];
            son=dad; dad=(son-1)/2;
            heap[son] = val;
        }
    }

    void ShiftDown(vector<int>& heap, int dad, int last) {
        int val=heap[dad];
        int son=2*dad+1;
        while(son <= last) {
            if (son+1 <= last && heap[son]>heap[son+1]) son++;
            if (heap[son] >= val) break; // 
            heap[dad] = heap[son];
            dad=son; son=2*dad+1;
        }
        heap[dad] = val; // 为什么在外层？
    }


    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        for(auto num : nums) {
            if (heap.size()==k && num <= heap[0]) continue;
            if (heap.size() < k) {
                heap.push_back(num);
                ShiftUp(heap, heap.size()-1);
            } else {
                heap[0]=num;
                ShiftDown(heap, 0, heap.size()-1);
            }
        }
        return heap[0];
    }
};


// [2,1]  2     v1未通过
// [-1,2,0]  2     v2未通过
// v3通过 （修改入队和出队方式）

// 小顶堆实现
class SolutionPPP {
private:
int k;

void ShiftUp(vector<int>& heap, int son) {
    int val = heap[son];
    int dad=son/2;
    while(son>0 && heap[dad] > val) { // 向上调，因此如果son为0变成根 结束
        heap[son] = heap[dad];
        son=dad; dad=dad/2;
        heap[son] = val;
    }
}

void ShiftDown(vector<int>& heap, int start) {
    int val = heap[start];
    int dad=start, son=start*2;
    while(son < k) { // 向上调，如果son到右边界结束
        if (son+1<k && heap[son+1] < heap[son]) ++son;
        if (heap[son] >= val) break;
        heap[dad] = heap[son];
        dad=son; son=2*son;
    }
    heap[dad] = val;
}

public:

int findKthLargest(vector<int>& nums, int k) {
    this->k = k;
    vector<int> heap;


    for (int i=0; i<nums.size(); i++) {
        if (heap.size()==k && heap[0]>=nums[i]) continue;

        if (heap.size()==k) {
            // pop and push
            heap[0] = nums[i];
            ShiftDown(heap, 0);
        } else {
            heap.push_back(nums[i]);
            ShiftUp(heap, i);
        }
    }
    return heap[0];
}
};
// @lc code=end





int main() {
    vector<int> p;
    p = {3,2,1,5,6,4};
    LOG_DEBUG << Solution().findKthLargest(p, 2); // 5

    p = {3,2,3,1,2,4,5,5,6};
    LOG_DEBUG << Solution().findKthLargest(p, 4); // 4

    p = {2,1};
    LOG_DEBUG << Solution().findKthLargest(p, 2); // 1

    p = {-1,2,0};
    LOG_DEBUG << Solution().findKthLargest(p, 2); // 0
}

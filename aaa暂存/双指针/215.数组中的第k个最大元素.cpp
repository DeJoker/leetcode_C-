/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include "../common/debugger.h"
// @lc code=start
class Solution {
public:

    void Heapify(vector<int>& nums, int start, int last) {
        int dad = start;
        int son = dad*2+1;
        while(son <= last) {
            // nums[son+1] < nums[son] 和 nums[dad] < nums[son] 要确定最小堆与最大堆
            if (son+1 <= last && nums[son+1] > nums[son]) {
                son++;
            }

            if (nums[dad] > nums[son]) {
                break;
            } else {
                swap(nums[son], nums[dad]);
                dad = son;
                son = dad*2+1;
            }
        }
    }

    int Sort(vector<int>& nums) {
        const int len = nums.size();
        for(int i=len/2-1; i>=0; --i) {
        // for(int i=len/2; i>=0; --i) {
            Heapify(nums, i, len-1);
        }

        for(int i=len-1; i>0; --i) { // 这里注意是i>0, 只交换N-1次
            swap(nums[0], nums[i]);
            Heapify(nums, 0, i-1);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        for(int i=len/2-1; i>=0; --i) {
            Heapify(nums, i, len-1);
        }

        // 排除最小的 nums.size()-k个，保留k个取最大值
        for(int i=nums.size()-1; i>nums.size()-k+1; --i) {
            swap(nums[0], nums[i]);
            --len;
            Heapify(nums, 0, len-1);
        }
        return nums[0];
    }
};


class Solution33 {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

// @lc code=end

int main() {
    vector<int> xx = {3,2,1,5,6,4};
    // Solution().Sort(xx);
    // Solution().findKthLargest(xx, 2);

    vector<int> xx2 = {2,1};
    Solution33().findKthLargest(xx2, 2);
    Solution().findKthLargest(xx2, 2);
}
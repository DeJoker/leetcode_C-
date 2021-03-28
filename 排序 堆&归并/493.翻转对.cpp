/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */
#include "../common/debugger.h"



// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对


//  [1,3,2,3,1]  ret: 2


// @lc code=start

// 为什么可以是归并排序呢
// 第一，他是稳定排序
// 其次，因为是递归后处理；那么排序过程中是无序且相对位置没有变化

class Solution {
    int res;
public:
    void Merge(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left >= right) return;

        int mid = left+(right-left)/2;
        Merge(nums, left, mid, tmp);
        Merge(nums, mid+1, right, tmp);

        int p=left, q=mid+1, pos=left;
        while (p<=mid && q<=right) {
            // 满足题意，那么p到mid一定都比当前q大
            // 满足应该移动q，要检测更大者是否满足两倍关系
            if (nums[p] > (int64_t)(nums[q])*2) {
                res += mid+1 - p;
                ++q;
            } else {
                ++p;
            }
        }

        p=left, q=mid+1;
        while (pos <= right) {
            if (p > mid) {
                tmp[pos++] = nums[q++];
            } else if (q > right) {
                tmp[pos++] = nums[p++];
            } else {
                if (nums[p] > nums[q]) {
                    tmp[pos++] = nums[q++];
                } else {
                    tmp[pos++] = nums[p++];
                }
            }
        }

        for(int i=left; i<=right; i++) {
            nums[i] = tmp[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n);
        Merge(nums, 0, n-1, tmp);
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p={1,3,2,3,1,};
    LOG_DEBUG << Solution().reversePairs(p); // 2
    p={2,4,3,5,1};
    LOG_DEBUG << Solution().reversePairs(p); // 3
}


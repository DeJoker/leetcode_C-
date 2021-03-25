
#include "../common/debugger.h"

// 注释的地方也可以使用

class Solution {
public:
    int Merge(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left >= right) return 0;

        int mid = left+ (right-left)/2;
        int lR = Merge(nums, left, mid, tmp);
        int rR = Merge(nums, mid+1, right, tmp);

        int count(0);
        int p=left, q=mid+1, pos=left;
        while(pos <= right) {
            if (q > right) {
                tmp[pos++] = nums[p++];
                count += q-(mid+1);
            } else if (p > mid) {
                tmp[pos++] = nums[q++];
                // count += (mid+1)-p;
            } else {
                if (nums[p] <= nums[q]) {
                    tmp[pos++] = nums[p++];
                    count += q-(mid+1);
                } else {
                    tmp[pos++] = nums[q++];
                    // count += (mid+1)-p;
                }
            }
        }

        // 忘记tmp移动到nums，但是我们样例是有序因此不这里出错
        for (int i=left; i<=right; i++) {
            nums[i] = tmp[i];
        }
        return count+lR+rR;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n);
        return Merge(nums, 0, n-1, tmp);
    }
};


int main() {
    vector<int> p;
    p = {4,6,7,7};
    // LOG_DEBUG << Solution().reversePairs(p);

    p = {7,7,6,4};
    LOG_DEBUG << Solution().reversePairs(p); // 5
    return 0;
}



class Solutionkk {
public:
    int Merge(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left >= right) return 0;
        int mid = left+ (right-left)/2;

        int count = Merge(nums, left, mid, tmp)+Merge(nums, mid+1, right, tmp);

        int p=left, q=mid+1, pos=left;
        while (p<=mid && q<=right) {
            if (nums[p] <= nums[q]) {
                tmp[pos] = nums[p++];
                count += q-(mid+1);
            } else {
                tmp[pos] = nums[q++];
            }
            ++pos;
        }
        for(int k=p; k<=mid; ++k) {
            tmp[pos++] = nums[k];
            count += q-(mid+1);
        }
        for(int k=q; k<=right; ++k) {
            tmp[pos++] = nums[k];
        }

        for (int i=left; i<=right; i++) {
            nums[i] = tmp[i];
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n);
        return Merge(nums, 0, n-1, tmp);
    }
};

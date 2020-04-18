#include "common/debugger.h"

class Solution {
public:
    //left right
    int Partation(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int RandomPartation(vector<int>& nums, int l, int r) {
        int index = rand() % (r-l +1) + l;
        swap(nums[r], nums[index]);
        return Partation(nums, l, r);
    }
    void FastSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = RandomPartation(nums, l, r);
            FastSort(nums, l, pos-1);
            FastSort(nums, pos+1, r);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        FastSort(nums, 0, nums.size()-1);
        return nums;
    }
public:
    vector<int> HeapSort(vector<int>& nums);
};

class Solution2 {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    Solution ss;
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return ss.Partation(nums, l, r);
    }
    void FastSort(vector<int>& nums, int l, int r) {
        if (l < r){
            // int pos = randomized_partition(nums, l, r);
            int pos = ss.RandomPartation(nums, l, r);
            FastSort(nums, l, pos - 1);
            FastSort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        FastSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};


int main() {
    Solution2 sol;
    vector<int> arr{3,4,5,1,43,54,12,57,49};
    sol.sortArray(arr);
    return 0;
}

#include "../common/debugger.h"

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


class Heap {
public:
// 自上而下
void MaxHeapify(int arr[], int start, int last) {
    // 父节点 子节点
    int dad = start;
    int son = dad * 2 + 1;
    // 
    while (son <= last) { 
        if (son + 1 <= last && arr[son] < arr[son + 1]) // 两子节点取最大的
            son++;
        if (arr[dad] > arr[son]) // 父大于子结束
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void HeapSort(int arr[], int len) {
    // 初始化，最后一个父开始（自下而上）
    for (int i = len / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, i, len - 1);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    // 将之前排序好的父
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, 0, i - 1);
    }
}
};


int main() {
    Solution2 sol;
    vector<int> arr{3,4,5,1,43,54,12,57,49};
    sol.sortArray(arr);

    int xxx[] = {3,4,5,1,43,54,12,57,49};
    int len = sizeof(xxx)/sizeof(int);
    Heap().HeapSort(xxx, len);

    return 0;
}

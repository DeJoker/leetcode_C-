/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include "../common/debugger.h"

// @lc code=start
class SolutionHeap {
public:
    // 大顶堆
    void makeHeap(vector<int>& nums, int start, int end) {
        int fa=start, son=start*2+1;
        while(son <= end) {
            if (son+1 <= end && nums[son+1] > nums[son]) ++son;

            // 这步父子比较一定需要，为什么？
            // 我们建堆后已经保证了大的在上面，因此一旦发现父节点确实大，调整结束
            // 不然我们再交换相当于又把小的交换下去了，这个比大小的过程就体现了
            // 究竟是大根堆还是小根堆
            if (nums[fa] > nums[son]) break; 

            swap(nums[son], nums[fa]);
            fa=son; son=son*2+1;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        // 最后一个父一定是除2再减， 拿0、1、2的0和2举例即可
        for(int i=n/2-1; i>=0; --i) {
            makeHeap(nums, i, n-1);
        }

        
        for(int i=n-1; i>0; --i) {
            swap(nums[i], nums[0]);
            makeHeap(nums, 0, i-1); // i已经是当前最后且被交换出去了，这里减1才是需要排序的
        }
        return nums;
    }
};




class Solution {
public:
    void QuickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int primary = (rand()%(right-left+1))+left;
        swap(nums[primary], nums[right]);
        // 交换后这里应该取right位
        int pivot = nums[right]; 
        // partition
        int pos(left);
        for(int i=left; i<right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[pos]);
                ++pos;
            }
        }
        swap(nums[pos], nums[right]);

        // 注意不包括pos
        QuickSort(nums, left, pos-1);
        QuickSort(nums, pos+1, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
};



// Merge
class SolutionMerge {
public:
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid+1, right, temp);

        // 合并区间到tmp，三个数组三个下标
        int p = left, q = mid+1, pos = left;
        while (pos <= right) {
            if (p > mid) {
                temp[pos++] = nums[q++];
            } else if (q > right) {
                temp[pos++] = nums[p++];
            } else {
                if (nums[p] < nums[q]) {
                    temp[pos++] = nums[p++];
                } else {
                    temp[pos++] = nums[q++];
                }
            }
        }

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n);
        mergeSort(nums, 0, n-1, tmp);
        return nums;
    }
};

// Quick
class SolutionQuick {
    int partition(vector<int>& nums, int lf, int rg) {
        int pivot = nums[rg];
        int i=lf;
        for(int j=lf; j<rg; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        // 此步之前分为小于pivot和大于pivot pivot是rg下标的元素
        // i是刚好比pivot大的一个，因此交换两者
        swap(nums[i], nums[rg]);
        return i;
    }

    void quickSort(vector<int>& nums, int lf, int rg) {
        if (lf < rg) {
            int i = (rand()%(rg-lf+1)) + lf;
            swap(nums[i], nums[rg]);
            int pos = partition(nums, lf, rg);

            quickSort(nums, lf, pos-1);
            quickSort(nums, pos+1, rg);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};


// @lc code=end



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
    // 初始化，最后一个父开始
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
    vector<int> p;
    p = {5,2,3,1};
    Solution().sortArray(p);
    DebugVector(p);

    p = {5,1,1,2,0,0};
    Solution().sortArray(p);
    DebugVector(p);
}



class SolutionWrong1 {
public:
    // 大顶堆
    void makeHeap(vector<int>& nums, int start, int end) {
        int fa=start, son=start*2+1;
        while(son <= end && fa <= son) {
            if (son+1 <= end && nums[son+1] > nums[son]) ++son;
            swap(nums[son], nums[fa]);

            fa=son; son=son*2+1;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1; i>=0; --i) {
            makeHeap(nums, i, n-1);
        }

        for(int i=n-2; i>0; --i) {
            swap(nums[i+1], nums[0]);
            makeHeap(nums, 0, i);
        }
        return nums;
    }
};

















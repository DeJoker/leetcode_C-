#include "../common/debugger.h"

class Solution22 {
public:
    int n,k;
    vector<vector<int>> _res;

    void backtrack(int first, vector<int> curr, const vector<int>& nums) {
        if (curr.size() == k) {
            _res.push_back(curr);
        }

        for(int i=first; i<n; ++i) {
            curr.push_back(nums[i]);
            backtrack(first+1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subset(vector<int> nums) {
        n = nums.size();
        for(k=0; k<n+1; ++k) {
            backtrack(0, {}, nums);
        }
        return _res;
    }
};


class Solution {
public:
    int n;
    vector<vector<int>> _res;
    void backtrack(int first, vector<int> track, const vector<int>& nums) {
        _res.push_back(track);

        for(int i=first; i<n; ++i) {
            track.push_back(nums[i]);
            backtrack(i+1, track, nums);
            track.pop_back();
        }
    }
    vector<vector<int>> subset(vector<int> nums) {
        n = nums.size();
        vector<int> track;
        backtrack(0, track, nums);
        return _res;
    }

    // vector<vector<int>> res;
    // vector<vector<int>> subset(vector<int> nums) {
    //     // 记录走过的路径
    //     vector<int> track;
    //     backtrack(nums, 0, track);
    //     return res;
    // }
    // void backtrack(vector<int>& nums, int start, vector<int>& track) {
    //     res.push_back(track);
    //     // 注意 i 从 start 开始递增
    //     for (int i = start; i < nums.size(); i++) {
    //         // 做选择
    //         track.push_back(nums[i]);
    //         // 回溯
    //         backtrack(nums, i + 1, track);
    //         // 撤销选择
    //         track.pop_back();
    //     }
    // }

};

int main() {
    auto ret = Solution().subset({1,2,3});
    DebugPlanarVector(ret);
    return 0;
}
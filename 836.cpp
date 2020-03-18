#include "common/debugger.h"

class Solution {
public:
    bool isOverlap(int d11, int d12, int d21, int d22) {
        // 注意if的问题 尽量加 {}
        if (d11 < d21) {
            if (d12 > d21)
                return true;
        } else if (d11 > d21) {
            if (d11 < d22)
                return true;
        } else
            return true;
        
        return false;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) && 
                isOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
};



int main() {
    vector<int> rec1 = {7,8,13,15};
    vector<int> rec2 = {10,8,12,20};

    Solution sol;
    sol.isRectangleOverlap(rec1, rec2);
}


#include "../common/debugger.h"

// t 异或 a[i] = 

// 2 ^ 4 = 6   2 ^ 6 = 4   4 ^ 6 = 2
int FindXorCount(vector<int> a, int t) {
    // vector<vector<int> > res;

    vector<int> separator;

    for (int i=0; i<a.size(); i++) {
        int findV = a[i] ^ t;
        int rightPos(-1);
        for (int j=i; j<a.size(); j++) {
            if (a[j] == findV) {
                rightPos = j; // 最大边界
            }
        }

        if (rightPos != -1) {
            // vector<int> section{i, rightPos};
            // res.push_back(section);

            separator.push_back(i);
            separator.push_back(rightPos);
        }
    }

    separator.push_back(0);
    separator.push_back(int(a.size()-1)); // 重复也没问题
    
    sort(separator.begin(), separator.end());

    // 计算区间个数， 两个元素组成一个区间
    int res(0);
    for (int i=0; i<separator.size()-1; i++) {
        // 元素个数:区间个数   2:2  3:(3*2)/2   4:(4*3/2)

        int eleCount = separator[i+1]-separator[i]+1;
        res += eleCount*(eleCount-1)/2;
    }

    return res;
}


int main() {
    cout << FindXorCount({2,4,8,6,65,325,56}, 6) << endl;
    cout << FindXorCount({2,8,3}, 6) << endl;
}

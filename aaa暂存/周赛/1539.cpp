#include "../common/debugger.h"


class Solution {
public:
    int findKthPositive(const vector<int>& arr, int k) {
        // int n=0, miss=-1;
        // if (arr.front() > k)
        //     return k;
        // n=arr.front()-1; miss=arr.front()-1;
        // for(auto iter=arr.begin()+1; iter!=arr.end(); ++iter) {
        //     int dist = *iter-*(iter-1);
        //     if (dist > 1) {
        //         if (n+dist > k) {
        //             return miss+(k-n+1);
        //         } else {
        //             n += dist-1;
        //             miss = 
        //         }
        //     }
        // }

        if (arr.front() > k)
            return k;

        vector<int> miss;
        for(int i=1; i<arr.front(); ++i) {
            miss.push_back(i);
        }
        auto iter = arr.begin();
        for(int i=arr.front(); i<2000; ++i) {
            // if (i == *iter && iter!=arr.end()) { // 应该先合法校验
            if (iter!=arr.end() && i == *iter) {

                ++iter;
            } else {
                miss.push_back(i);
                if (miss.size() == k) {
                    return i;
                }
            }
        }
        return 2000;
    }
};



// 1540
class Solution1540 {
public:
    bool canConvertString(string s, string t, int k) {
        set<int> dists;
        for(int i=0; i<s.size(); ++i) {
            int dist = t[i]-s[i] >= 0 ? t[i]-s[i] : 26+t[i]-s[i];
            if (dist != 0) {
                auto ret = dists.insert(dist);
                while (!ret.second) {
                    dist += 26;
                    ret = dists.insert(dist);
                }
            }
        }
        if (dists.empty() || *dists.rbegin() <= k)
            return true;
        return false;
    }
};

// "())"
class Solution1541 {
public:
    int minInsertions(string s) {
        stack<int> st;
        int clc(0);
        for(char c : s) {
            if (c == '(')
                st.push(0);
            else {
                if (clc >= 1) {
                    if (!st.empty()) {
                        st.pop();
                        --clc;
                    } else
                        ++clc;
                }
                else
                    clc = 1;
            }
        }

        // if (2*st.size() > clc) {
        //     return 2*st.size() - clc;
        // }
        // int rg = clc - 2*st.size();
        // return rg%2 ? rg/2+2 : rg/2;

        int res = 2*st.size();
        if (clc != 0) {
            if (clc%2) {
                res = res ? res-clc/2 : clc/2+2;
            } else {
                res = res ? res-clc/2+2 : clc/2;
            }
        }
        
        return res;
    }
};


class Solution1542 {
public:
    int longestAwesome(string s) {

    }
};

// "atmtxzjkz"
// "tvbtjhvjd"

int main() {
    // LOG_DEBUG << Solution().findKthPositive({10,}, 5);
    // LOG_DEBUG << Solution().findKthPositive({2,3,4,7,11}, 5);
    // LOG_DEBUG << Solution().findKthPositive({1,2,3,4,}, 2);

    // LOG_DEBUG << Solution1540().canConvertString("abc", "bcd", 10);
    // LOG_DEBUG << Solution1540().canConvertString("leetcode", "leetcode", 0);
    // LOG_DEBUG << Solution1540().canConvertString("aab","bbb",27);
    // LOG_DEBUG << Solution1540().canConvertString("abc","abcd",1000);
    // LOG_DEBUG << Solution1540().canConvertString("atmtxzjkz", "tvbtjhvjd", 35);

    // LOG_DEBUG << Solution1541().minInsertions("())");
    // LOG_DEBUG << Solution1541().minInsertions("))())(");
    // LOG_DEBUG << Solution1541().minInsertions("((((((");
    // LOG_DEBUG << Solution1541().minInsertions(")))))))");
    // LOG_DEBUG << Solution1541().minInsertions("))))))");
    LOG_DEBUG << Solution1541().minInsertions("(()))");


}
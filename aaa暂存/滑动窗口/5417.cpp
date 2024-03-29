#include "../common/debugger.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<char> yuan = {'a', 'e', 'i', 'o', 'u'};
        int cnt(0), l(0);
        for(int i=0; i<l+k; ++i) {
            if (find(yuan.begin(), yuan.end(), s[i]) != yuan.end())
                ++cnt;
        }
        ++l;                        
        cout << cnt << endl;

        int cur(cnt);
        //这是如果要加入一次遍历应该是-1！！！！
        for(;l+k-1<s.size(); ++l) {
            //这里也要检测，但是是l+k-1 还是l+k
            bool right = find(yuan.begin(), yuan.end(), s[l+k]) != yuan.end();
            bool left = find(yuan.begin(), yuan.end(), s[l]) != yuan.end();
            if (left && !right)
                --cur;
            else if (!left && right)
                ++cur;
            
            cnt = std::max(cur, cnt);
            cout << cnt << endl;
        }
        
        return cnt;
    }
};

int main() {
    Solution sol;
    sol.maxVowels("tnfazcwrryitgacaabwm", 4);
    // sol.maxVowels("novelsd", 1);
    // sol.maxVowels("tryhard", 4);
}
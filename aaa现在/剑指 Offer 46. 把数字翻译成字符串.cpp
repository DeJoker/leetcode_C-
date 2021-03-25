
#include "../common/debugger.h"


// dp[0] 为何为 1
// dp[i] ：翻译前 i 个数的方法数。
// dp[0]=1 ，是为了让边界情况也能满足通式：比如数字 16 ，dp[2]=2 是肯定的，dp[1]=1dp[1]=1 也是肯定的。为了让 dp[2]=dp[0]+dp[1]dp[2]=dp[0]+dp[1] 通式成立，只有让 dp[0]=1dp[0]=1


class Solution {
public:
    // dp[i] = (dp[i-1]+1) + (dp[i-2]+1)
    // dp[0] = 0;
    int translateNum(int num) {
        string str = to_string(num);
        int n=str.size();

        vector<int> dp(n+1);
        dp[0]=1; dp[1]=1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1];
            int tmp = atoi(str.substr(i-2, 2).c_str());
            if (tmp<26 && tmp>=10) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
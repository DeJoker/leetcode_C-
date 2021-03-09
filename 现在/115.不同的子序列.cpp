/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include "../common/debugger.h"

// dp[i][j] 能够组成几种

// 先看s[i] == t[j] 时，以s = "rara" t = "ra" 为例，
// 当i = 3, j = 1时，s[i] == t[j]

// 此时分为2种情况，s串用最后一位的a + 不用最后一位的a
// 如果用s串最后一位的a,那么t串最后一位的a也被消耗掉，此时的子序列其实=dp[i-1][j-1]
// 如果不用s串最后一位的a，那就得看"rar"里面是否有"ra"子序列的了，就是dp[i-1][j]


// 再看s[i] != t[j] 比如 s = "rarb" t = "ra" 
// 还是当i = 3, j = 1时，s[i] != t[j]
// 此时显然最后的b想用也用不上啊。所以只能指望前面的"rar"里面是否有能匹配"ra"的
// 所以此时dp[i][j] = dp[i-1][j]


// @lc code=start

// class Solution:
//     def numDistinct(self, s: str, t: str) -> int:
//         n1 = len(s)
//         n2 = len(t)
//         dp = [[0] * (n1 + 1) for _ in range(n2 + 1)]
//         for j in range(n1 + 1):
//             dp[0][j] = 1
//         for i in range(1, n2 + 1):
//             for j in range(1, n1 + 1):
//                 if t[i - 1] == s[j - 1]:
//                     dp[i][j] = dp[i - 1][j - 1]  + dp[i][j - 1]
//                 else:
//                     dp[i][j] = dp[i][j - 1]
//         #print(dp)
//         return dp[-1][-1]


class Solution {
public:
    // 用s子序列匹配t
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // t的空串一定被所有匹配
        for(int j=0; j<=n; j++) {
            dp[0][j] = 1;
        }

        // t为外层，内层s不断增长来匹配t
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if (i>j) continue; // 长度不满足一定无法匹配

                if (s[j-1]==t[i-1]) 
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

class SolutionWrong {
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if (s[i-1]==t[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};

class Solution22 {
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if (j>i) break; // 记得是匹配，短的必然匹配不了长的

                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().numDistinct("rabbbit", "rabbit");
    LOG_DEBUG << Solution().numDistinct("babgbag", "bag");
    LOG_DEBUG << Solution().numDistinct("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo"
, "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");
}


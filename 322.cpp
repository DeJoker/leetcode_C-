#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename Ty1, typename Ty2>
void DebugVecor(map<Ty1, Ty2>& mm)
{
    cout << "Debug Map ";
    for (auto data : mm)
    {
        cout << data.first << " : " << data.second << endl;
    }
    cout << "Debug end ---- " << endl;
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> combin(amount+1, -1);
        combin[0]=0;
        for(auto coin : coins)
        {
            combin[coin] = 1;
        }
        // 初始化
        // int it(1);
        // for(; it<*coins.rbegin(); ++it)

        for(int it=1; it<amount+1; ++it)
        {
            int mincount(amount);
            for(auto coin : coins)
            {
                if (it-coin < 0)
                    continue;
                mincount = combin[it-coin]+1 < mincount ? combin[it-coin]+1 : mincount;
                // if (combin[it-coin]+1 < mincount)
            }
            combin[it] = mincount;
        }
        return combin[amount];
    }
};




int main()
{
    Solution sol;
    vector<int> coins = {1,2,5};
    int ret = sol.coinChange(coins, 10);
    cout << ret << endl;
    return 0;
}
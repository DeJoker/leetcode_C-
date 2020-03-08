#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
    // int max_int = 0xFFFFFFFF;
    int max_int = 100000;
        // for_each(coins.begin(), coins.end(),
        //     [&](int coin)
        //     {
        //         if ()
        //     }
        // );
        
        vector<int> combin(amount+1, max_int);
        combin[0]=0;
        for(auto coin : coins)
        {
            combin[coin] = 1;
        }
        // sort coin
        // 如果coin大于amount没有处理

        for(int it=1; it<amount+1; ++it)
        {
            int mincount(max_int);
            for(auto coin : coins)
            {
                if (it-coin < 0)
                    continue;
                // mincount = combin[it-coin]+1 < mincount ? combin[it-coin]+1 : mincount;
                if (combin[it-coin]+1 < mincount && combin[it-coin] != -1)
                    mincount = combin[it-coin]+1;
            }
            if (mincount == max_int)
                combin[it] = -1;
            else
                combin[it] = mincount;
        }
        return combin[amount];
    }
};




int main()
{
    Solution sol;
    vector<int> coins = {2};
    int ret = sol.coinChange(coins, 1);
    // vector<int> coins = {1};
    // int ret = sol.coinChange(coins, 0);
    // vector<int> coins = {1,2,5};
    // int ret = sol.coinChange(coins, 10);
    cout << ret << endl;
    return 0;
}
#include <iostream>
#include <set>
#include <stack>
#include <functional>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    // void change1(vector<vector<int>>& grid, int i, int j)
    // {
    //     grid[i-1][j] = grid[i-1][j]==0 ? 0 : 2;
    //     grid[i+1][j] = grid[i-1][j]==0 ? 0 : 2;
    //     grid[i][j+1] = grid[i-1][j]==0 ? 0 : 2;
    //     grid[i][j-1] = grid[i-1][j]==0 ? 0 : 2;
    // }
    // int orangesRotting1(vector<vector<int>>& grid) {
    //     set<pair<int ,int>> bad;
    //     int count(-1), badsize(0);
    //     do
    //     {
    //         badsize = bad.size();
    //         for(int i=0; i<grid.size(); ++i) {
    //             for(int j=0; j<grid.size(); ++j) {
    //                 if(grid[i][j] == 2) {
    //                     change(grid)
    //                 }
    //             }
    //         }
    //         ++count;
    //     }while(bad.size() > badsize);
    //     return count;
    // }




    bool changeAndpop(set<pair<int ,int>>& bad, set<pair<int ,int>>& good, pair<int, int>& pos)
    {
        bool change(false);
        auto iter = good.find(make_pair(pos.first+1, pos.second));
        if (iter != good.end())
        {
            change = true;
            bad.insert(*iter);
            good.erase(iter);
        }
        iter = good.find(make_pair(pos.first-1, pos.second));
        if (iter != good.end())
        {
            change = true;
            bad.insert(*iter);
            good.erase(iter);
        }
        iter = good.find(make_pair(pos.first, pos.second+1));
        if (iter != good.end())
        {
            change = true;
            bad.insert(*iter);
            good.erase(iter);
        }
        iter = good.find(make_pair(pos.first, pos.second-1));
        if (iter != good.end())
        {
            change = true;
            bad.insert(*iter);
            good.erase(iter);
        }
        return change;
    }
    int orangesRotting(vector<vector<int>>& grid)
    {
        set<pair<int ,int>> bad, good;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid.size(); ++j) {
                if(grid[i][j] == 1)
                    good.insert(make_pair(i,j));
                else if (grid[i][j] == 2)
                    bad.insert(make_pair(i,j));
            }
        }

        int count(-1);
        while(true)
        {
            ++count;
            // 考虑用出循环后的good数量的变动判断是否该退出
            bool cant(false);
            for(auto pos : bad)
            {
                // cant 应该是全部位置都不行才退出
                cant = changeAndpop(bad, good, pos);
                if(good.empty())
                    return count;
                // 同时也要想到怎么会一个条件用两次呢
            }
            if(count == 10)
                // return bad.size(); // 5
                return good.size(); // 2
        }
        if (cant)
            return -1;
        return count;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> inital = 
    {{2,1,1},{1,1,0},{0,1,1}};
    int cc = sol.orangesRotting(inital);
    cout << cc << endl;
}

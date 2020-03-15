#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template<typename Frist, typename Second>
void DebugPair(pair<Frist, Second>& data)
{
    cout << data.first << " : " << data.second << endl;
}


class Solution {
public:
    vector<pair<int, int>> _directs;
    Solution() {
        // _direct = {1, 2};
        _directs = {{1, 0},{-1,0},{0,-1},{0,1}};
    }

    int dps(vector<vector<int>>& grid, pair<int, int>& pos) {
        if(pos.first < 0 || pos.second < 0 ||
            pos.first >= grid.size() || pos.second >= grid[0].size() ||
            grid[pos.first][pos.second] == 0)
            return 0;
        
        grid[pos.first][pos.second] = 0;
        int area = 1;
        for(auto direct : _directs) {
            pair<int, int> next = {pos.first+direct.first, pos.second+direct.second};
            area += dps(grid, next);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mmax = 0;
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[i].size(); ++j) {
                auto pos = make_pair(i, j);
                mmax = std::max(mmax, dps(grid, pos));
            }
        return mmax;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> gr = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << sol.maxAreaOfIsland(gr) << endl;

    // DebugPair(sol._direct);
}

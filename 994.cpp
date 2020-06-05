#include <iostream>
#include <set>
#include <stack>
#include <functional>
#include <queue>
#include <map>
using namespace std;

#include <cstring>


class Solution2 {
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
            int size = good.size();
            for(auto pos : bad)
            {
                // 调试发现因为bad和good会在循环中发生改变因此该方案不可取
                changeAndpop(bad, good, pos);
                if(good.empty())
                    return count;
                // 同时也要想到怎么会一个条件用两次呢
            }
            if (size == good.size())
                return -1;
        }
        
        return count;
    }
};





class Solution {
    int cnt;
    int dis[10][10];
    int dir_x[4]={0, 1, 0, -1};
    int dir_y[4]={1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> >Q;
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n=(int)grid.size(), m=(int)grid[0].size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 2){
                    Q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
                else if (grid[i][j] == 1) cnt += 1;
            }
        }

        while (!Q.empty()){
            pair<int,int> x = Q.front();Q.pop();
            for (int i = 0; i < 4; ++i){
                int tx = x.first + dir_x[i];
                int ty = x.second + dir_y[i];
                if (tx < 0|| tx >= n || ty < 0|| ty >= m|| ~dis[tx][ty] || !grid[tx][ty]) continue;
                dis[tx][ty] = dis[x.first][x.second] + 1;
                Q.push(make_pair(tx, ty));
                if (grid[tx][ty] == 1){
                    cnt -= 1;
                    ans = dis[tx][ty];
                    if (!cnt) break;
                }
            }
        }
        
        return cnt ? -1 : ans;
    }
};


class Solution3 {
public:
    // static constexpr int dx[4] = {0, -1, 0, 1};
    // static constexpr int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    int orangesRotting(vector<vector<int>> grid) {
        queue<tuple<int, int, int>> rot;
        int n = grid.size(), m=grid[0].size();
        int fresh(0), rotTime(0);
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 2)
                    rot.push({i,j,0});
                else if (grid[i][j] == 1)
                    ++fresh;
            }
        }

        while(!rot.empty()) {
            // if (fresh == 0)
            //     break;
            auto [x, y, count] = rot.front(); rot.pop();
            for(int i=0; i<4; ++i) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx<0 || nx>=n || ny<0 || ny>=m) // 这里m填错成了n
                    continue;
                if (grid[nx][ny]==1) {
                    rot.push({nx, ny, count+1});
                    grid[nx][ny] = 2;
                    rotTime = count+1;
                    --fresh;
                }
            }
        }
        if (fresh == 0)
            return rotTime;
        else
            return -1;
    }
};


int main() {
    vector<vector<int>> inital = {{2,1,1},{0,1,1},{1,0,1}};
    
    // int cc = Solution3().orangesRotting(inital);
    int cc = Solution3().orangesRotting({{1},{2}});
    cout << cc << endl;
}

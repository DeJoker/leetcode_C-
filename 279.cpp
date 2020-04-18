#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<bool> v(n,false);//访问数组，标记已经用过的数，避免重复判断
        queue<int> q;//队列
        int step = 0;
        q.push(n);
        
        step = bfs(q,v,n,step);//bfs
        return step;
    }

    int bfs(queue<int> &q,vector<bool> &v,int &n,int &step)
    {
        while(!q.empty())
        {
            int size = q.size();
            step++;//每一层+1
            while(size>0)//一层一层搜索,这里的size是上一层的size,size为0则进入下一层
            {
                int val = q.front();//取出队头
                q.pop();//弹出队头
                for(int i = 1; val - i * i >= 0;i++)
                {
                    int temp = val - i * i;
                    if(temp == 0)///找到了
                    {
                        return step;
                    }
                    if(!v[temp])////未访问的数入队，进行下一层判断
                    {
                        q.push(temp);
                        v[temp] = true;////置为访问过
                    }
                }
                size--;
            }

        }
        return -1;
    }
};



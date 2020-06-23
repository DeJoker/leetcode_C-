#include <iostream>
#include <vector>
using namespace std;
 #include <unistd.h>

template<typename Frist, typename Second>
void DebugPair(pair<Frist, Second>& data)
{
    cout << data.first << " : " << data.second << endl;
}

template<typename Ty>
void DebugPlanarVector(vector<vector<Ty>>& data)
{
    for (auto parallel : data)
    {
        cout << "[";
        for (auto val : parallel)
        {
            cout << val << ",";
        }
        cout << "]" << endl;
    }
}

class Solution
{
public:
    pair<int, int> caculate(int mid, int num)
    {
        if (mid < num)
            return make_pair(-1, -1);
        if (num % 2 == 1)
            return make_pair(num*mid, num*mid);
        else
            return make_pair(num*(2*mid - 1) / 2, num*(2*mid + 1) / 2);
    }

    vector<int> GetVector(int mid, int num, int direct)
    {
        vector<int> ret;
        int start(0), end(0);
        if (direct == -1)
        { // 左 中
            start = mid - num / 2;
        }
        else if (direct == 1)
        { // 右
            start = mid - num / 2 + 1;
        }

        end = start + num;
        for (; start < end; ++start)
        {
            ret.push_back(start);
        }
        return ret;
    }

    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ret;
        int num(1);
        while (true)
        {
            ++num;
            int mid = (target+1) / num;
            auto calcu = caculate(mid, num);
            DebugPair(calcu);
            if (calcu.first == target)
            {
                ret.push_back(GetVector(mid, num, -1));
            }
            else if (calcu.second == target)
            {
                ret.push_back(GetVector(mid, num, 1));
            }
            else if (calcu.second < target || calcu.first > target)
            {
                break;
            }
            //continue;
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    auto vec = sol.findContinuousSequence(15);
    DebugPlanarVector(vec);
    while(1)
        sleep(5);
    return 0;
}

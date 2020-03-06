class Solution {
public:
    pair<int,int> caculate(int mid, int num)
    {
        if (num % 2 == 1)
            return make_pair(num*mid, num*mid);
        else
            return make_pair(num*mid-1, num*mid+1);
    }

    vector<int> GetVector(int mid, int num, int direct)
    {
        vector<int> ret;
        int start(0),end(0);
        if (direct == -1) { // 左 中
            start = mid - num/2;
        } else if (direct == 1) { // 右
            start = mid - num/2 -1;
        }

        // end = start + num;
        for(;start<start+num;++start)
        {
            ret.push_back(start);
        }
        return ret;
    }

    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ret;
        int num(1);
        while(true)
        {
            ++num;
            int mid = target/num;
            auto calcu = caculate(mid, num);
            if(calcu.first == target) {
                ret.push_back(GetVector(mid, num, -1));
            } else if (calcu.second == target) {
                ret.push_back(GetVector(mid, num, 1));
            } else if (calcu.second > target && calcu.first < target) {
                continue;
            }
            break;
        }

        return ret;
    }
};

int main() {
    Solution sol;
    sol.findContinuousSequence(9);
    
}
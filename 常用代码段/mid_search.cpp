#include "../common/debugger.h"


int BinarySearch(vector<int>& vec, int value)
{
	if (vec.empty())
		return -1;
 
	int low = 0;
	int high = vec.size()- 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (vec[mid] == value)
			return mid;
		else if (vec[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
 
	return -1;
}

// wrong 错误解法
class Solution {
public:
    int Count(int x) {
        int cnt(0);
        while(x) {
            x /= 10;
            cnt++;
        }
        return cnt;
    }
    int mySqrt(int x) {
        if(!x) return x;

        int cnt = Count(x)/2+1;
        int l=pow(10, cnt-1), r=pow(10, cnt);
        while(l<=r) {
            int mid = l+(r-l)/2;
            int cur = mid*mid;
            int nex = (mid+1)*(mid+1);
            if (cur <= x && nex > x) {
                return mid;
            } else if (cur > x) {
                r = mid-1;
            // } else if (nex <= x) {
            } else {
                l = mid+1;
            }
        }
        return -1;
    }
};

int main() {
    // cout << Solution().mySqrt(8) << endl;
    // cout << Solution().mySqrt(0) << endl;
    // cout << Solution().mySqrt(INT_MAX) << endl;

    const char aa[10] = "dwefwf";
    string host(aa+1, 30);
    string host2(aa, 30);
    cout << host << endl;
    cout << host2 << endl;
}


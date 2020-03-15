#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        string compress;
        int count(1);
        for(int i=1; i<S.length(); ++i) {
            if (S[i-1] == S[i]) {
                ++count;
            } else {
                compress += S[i-1];
                compress += std::to_string(count);
                count = 1;
            }
        }
        //没有下面这句，导致最后的重复字符没有记录
        //rbegin写成rend，返回空字符
        compress += *S.rbegin();
        compress += std::to_string(count);
        return S.length() > compress.length() ? compress : S;
    }
};


int main() {
    Solution sol;
    cout << sol.compressString("aabcccccaaa") << endl;
    cout << sol.compressString("aabcccccaa") << endl;
}

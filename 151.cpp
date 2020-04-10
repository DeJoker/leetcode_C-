#include "common/debugger.h"

class Solution {
public:
    string reverseWords(string s) {
        string::size_type pos = s.find_first_not_of(' ');
        if(pos != string::npos)
        {
            s.erase(0,pos);
        }

        reverse(s.begin(), s.end());
        int i(0);
        for(int j=1; j<s.size(); ++j) {
            if (s[j] == ' ') {
                reverse(s.begin()+i, s.begin()+j);
                int k(j);
                while(s[j+1] == ' ') ++j;
                // 如果不相等则应该不使用erase，多出来的空格才删除
                if(k != j)
                    // 注意要删除的是2个或以上，第一个空格不删
                    s.erase(k+1, j+1);
                // 下一个reverse应该是连续单次的单词
                i=j+1;
            }
        }
        reverse(s.begin()+i, s.end());
        return s;
    }
};

int main() {
    Solution sol;
    // cout << sol.reverseWords("") << endl;
    cout << sol.reverseWords("the sky is blue") << endl;
    // bug
    cout << sol.reverseWords("a good   example") << endl;
}
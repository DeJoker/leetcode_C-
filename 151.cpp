#include "common/debugger.h"

class Solution {
public:
    string reverseWords(string s) {
        int ss(0);
        while (ss < s.size() && s[ss] == ' ') ++ss;
        if (ss == s.size())
            return "";

        string::size_type pos = s.find_first_not_of(' ');
        if(pos != string::npos)
        {
            s.erase(0,pos);
        }
        pos = s.find_last_not_of(' ');
        if(pos != string::npos)
        {
            s.erase(pos+1, s.size());
        }
        // int left(0),right(s.size()-1);
        // while(left <= right && s[left] == ' ') ++left;
        // while(left <= right && s[right] == ' ') --right;


        reverse(s.begin(), s.end());
        int i(0);
        for(int j=0; j<s.size(); ++j) {
            // 单字符有严重的bug
            if (s[j] == ' ') {
                reverse(s.begin()+i, s.begin()+j);
                int k(j);
                while(s[j+1] == ' ') ++j;
                // 如果不相等则应该不使用erase，多出来的空格才删除
                if(k != j)
                    // 注意要删除的是2个或以上，第一个空格不删
                    s.erase(k+1, j-k);
                // 下一个reverse应该是连续单次的单词
                i=k+1;
                // 跳过的空格j没有得到更新，其实单字符问题不是我想那样，要静下心认真定位问题不要浮躁
                j=k+1;
            }
        }
        reverse(s.begin()+i, s.end());
        return s;
    }
};

int main() {
    // 头尾多余要去除，单字符reverse问题，删除多余空格
    Solution sol;
    cout << sol.reverseWords("") << endl;
    cout << sol.reverseWords("the sky is blue") << endl;
    // bug
    cout << sol.reverseWords("a good   example") << endl;
    cout << sol.reverseWords("  hello world!  ") << "22" << endl;
    cout << sol.reverseWords("         ") << "22" << endl;
    cout << sol.reverseWords("   a   b  c d   e  ") << "22" << endl;
}
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
                s.erase(k, j);
                i=j;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseWords("") << endl;
    cout << sol.reverseWords("the sky is blue") << endl;
}
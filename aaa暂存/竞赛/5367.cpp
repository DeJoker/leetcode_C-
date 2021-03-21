#include "../common/debugger.h"


class Solution2 {
public:
    string longestPrefix(string s) {
        string forw,backw, ret;
        int start=0;
        while(start != s.size()-1) {
            forw.push_back(*(s.begin()+start));
            backw.push_back(*(s.rbegin()+start));
            if (forw == backw)
                ret = forw;
            ++start;
        }
        return ret;
    }
};

class Solution {
public:
    string longestPrefix2(string s) {
        string forw,backw, ret;
        int start=0;
        while(start != s.size()-1) {
            forw.push_back(s[start]);
            backw.insert(backw.begin(), *(s.rbegin()+start));
            if (forw == backw) {
                ret = forw;
            }
            ++start;
        }
        return ret;
    }

    string longestPrefix(string s) {
        string ret;
        int start=0;
        while(start < s.size()-1) {
            ++start;
            if(s[start] == s[0]) {
                int i=0;
                while(start < s.size()-1 && s[start+1] == s[i]) {
                    ++start;
                    ++i;
                }
                if (start == s.size()-1)
                    ret = s.substr(0, i);
                else
                    --start;
            }
        }
        return ret;
    }
};


int main() {
    Solution sol;
    cout << sol.longestPrefix("acccbaaacccbaac") << endl;
}
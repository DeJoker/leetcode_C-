#include "../common/debugger.h"

class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddress(string s) {
       int l = s.size();
       if (l>12 || l<4) {
           return res;
       }
       
       deque<string> path;
       dfs(s, l, 0, 4, path);
       return res;
    }
    
    void dfs(const string& s, int len, int begin, int residue, deque<string>& path) {
        if (begin==len && residue==0) {
            string ip;
            for(const auto& dot : path) {
                ip += dot + ".";
            }
            ip.erase(ip.size()-1);
            res.push_back(ip);
        }
        for(int i=begin; i<begin+3; i++) {
            if (i>=len)
                break;
            if (residue*3 < len-i) 
                continue;
            
            if (Check(s, begin, i)) {
                string cur = s.substr(begin, i+1-begin);
                path.push_back(cur);
                dfs(s, len, i+1, residue-1, path);
                path.pop_back();
            }
        }
    }
    
    bool Check(const string& s, int l, int r) {
        int len = r-l+1;
        if (len>1 && s[l]=='0') 
            return false;
            
        // int num(0);
        // while(l<=r) {
        //     num += num*10 + s[l]-'0';
        //     ++l;
        // }
        int num = std::stoi(s.substr(l, len));
        return num>=0 && num<=255;
    }
};


int main() {
    auto res = Solution().restoreIpAddress("25525511135");
    DebugVector(res);
}

#include "../common/debugger.h"


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(const auto& c : t){
            ++need[c];
        }

        int l(0), r(0);
        int valid=0;
        int start(0), len(INT_MAX);

        while(r < s.size()) {
            char& c = s[r];
            ++r;
            if(need.count(c)) {
                ++window[c];
                if (window[c] == need[c])
                    ++valid;
            }

            while (valid == need.size()) {
                if (r-l < len) {
                    start = l;
                    len = r-l;
                }

                char d = s[l];
                ++l;
                if (need.count(d)) {
                    if (window[d] == need[d])
                        --valid;
                    --window[d];
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};


class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(const char& c : p) {
            need[c]++;
        }

        int l(0), r(0), valid(0);
        vector<int> res;
        while(r < s.size()) {
            char& c = s[r];
            ++r;
            if (need.count(c)) {
                ++window[c];
                if(need[c] == window[c])
                    ++valid;
            }
            // 左右两边互减出错
            while(r-l >= p.size()) {
                if (valid == need.size())
                    res.push_back(l);

                char& d = s[l];
                ++l;
                if(need.count(d)) {
                    if (window[d] == need[d])
                        --valid;
                    --window[d];
                }
            }
        }
        return res;
    }
};


int main() {
    // auto ret = Solution().minWindow("ADOBECODEBANC", "ABC");
    // auto ret = Solution().minWindow("a", "aa");
    // cout << ret << endl;


    auto ret = Solution2().findAnagrams("cbaebabacd", "abc");
    DebugVecor(ret);
    return 0;
}
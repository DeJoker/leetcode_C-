#include "../common/debugger.h"

vector<int> GetNextWrong(const string& pattern) {
    vector<int> next(pattern.size());
    next[0] = 0;
    next[1] = 1;
    for(int i=2,j=0; i<pattern.size();) {
        if (pattern[i] == pattern[j]) {
            ++j;
            next[i] = j;
            i++;
        } else {
            if (j==0) {
                next[i]=0;
                i++;
            } else {
                j = next[j-1];
            }
        }
    }
    return next;
}

vector<int> GetNextRaw(const string& str)
{
    int len=str.size();
    vector<int> next(len);
    next[0] = -1;//next数组初值为-1
    int j=0,k=-1;
    while(j<len-1)
    {
        if(k==-1||str[j]==str[k])//str[j]后缀 str[k]前缀
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k=next[k];
        }
    }
    return next;
}

vector<int> GetNextOpt1(string str)
{
    int len=str.size();
    vector<int> next(len);
    next[0] = -1;//next数组初值为-1
    int j=0, k=-1;
    while(j<len-1)
    {
        if(k==-1||str[j]==str[k])//str[j]后缀 str[k]前缀
        {
            j++;
            k++;
            if(str[j]!=str[k])
                next[j] = k;  //之前只有这一行
            else
                next[j] = next[k];  //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
        }
        else
        {
            k=next[k];
        }
    }
    return next;
}



int TestKMPNext() {
    DebugVector(GetNextRaw("ABABC"));
    DebugVector(GetNextRaw("abcac"));
    DumpSeparate();
    DebugVector(GetNextOpt1("ABABC"));
    DebugVector(GetNextOpt1("abcac"));
    return 0;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        if(!haystack.size()) return -1;
        //先构造pattern
        int j = -1, i = 0;//j在后面，i在前面
        vector<int> b(needle.size() + 1);
        b[i] = j;
        while(i < needle.size())
        {
            while(j >= 0 && needle[i] != needle[j]) j = b[j];
            i++, j++;
            b[i] = j;
        }
        
        j = 0, i = 0; //j这回是text的， i是pattern的
        while(j < haystack.size())
        {
            while(i >= 0 && needle[i] != haystack[j]) i = b[i];
            i++, j++;
            if(i == needle.size())
            {
                return j - needle.size();
            }
        }
        return -1;
    }
};
 


class Solution2 {
public:
    vector<int> GetNextOpt1(string str)
    {
        int len=str.size();
        vector<int> next(len);
        if (len==0) return next;
        next[0] = -1;//next数组初值为-1
        int j=0, k=-1;
        while(j<len-1)
        {
            if(k==-1||str[j]==str[k])//str[j]后缀 str[k]前缀
            {
                j++;
                k++;
                if(str[j]!=str[k])
                    next[j] = k;  //之前只有这一行
                else
                    next[j] = next[k];  //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
            }
            else
            {
                k=next[k];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        if(!haystack.size()) return -1;
        vector<int> next = GetNextOpt1(needle);
        int i=0, j=0;

        while(j < haystack.size())
        {
            while(i >= 0 && needle[i] != haystack[j]) i = next[i];
            i++, j++;
            if(i == needle.size())
            {
                return j - needle.size();
            }
        }
        return -1;      
    }
};


int main() {
    // TestKMPNext();
    // cout << Solution().strStr("hello", "ll") << endl;
    // cout << Solution().strStr("aaaaa", "bba") << endl;
    // int ret = Solution2().strStr("mississippi", "issipi");
    int ret = Solution().strStr("a", "");
    cout << "eee"+to_string(ret) << endl;
    return 0;
}



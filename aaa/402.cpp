#include "../common/debugger.h"
/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        stack<char> st;
        st.push(num[0]);
        for(int i=1; i<num.size(); i++) {
            if (num[i] > st.top() && k>0) {
                --k;
            } else {
                st.push(num[i]);
            }
        }

        // 忽略了k最后一定要为0
        for(;k>0; --k) {
            st.pop();
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};


// string removeKdigits(string num, int k) {
// 	stack<char> st;
// 	for (int i = 0; i < num.size(); i++)
// 	{
// 		while (!st.empty() && st.top() > num[i] && k)
// 		{
// 			st.pop();
// 			k--;
// 		}
// 		if (st.empty() && num[i] == '0')
// 			continue;//跳过前置0
// 		st.push(num[i]);
// 	}

// 	string result;
// 	while (!st.empty())
// 	{
// 		if (k > 0)//当还要再移除数字的时候：从此时单调递增栈的top部删去数字
// 			k--;
// 		else if (k == 0)//当不用再移除数字的时候：把字符串取出来到result
// 			result += st.top();

// 		st.pop();	
// 	}
// 	reverse(result.begin(), result.end());
// 	return result == "" ? "0" : result;
// }


// string removeKdigits(string num, int k) {
//     vector<int> stk(num.size());//单调递增栈
//     if(num.size()==k) return "0";

//     int top = -1;//栈顶
//     string ans;

//     for(int i = 0; i < num.size(); i++){
//         //高位可换成更小的时，则去替换高位值，最多k次
//         while(top!=-1&&stk[top]>num[i]&&k) {
//             top--,k--;
//         }
//         stk[++top] = num[i];
//     }
//     while(k--) top--;//若还没删够，则删除末尾的k个数
//     int i = 0;
//     while(stk[i]=='0'&&i < top) i++;//去除前导零
//     while(i <= top) ans.push_back(stk[i++]);
//     return ans;
// }


// bool backtrack(vector<int>& list, const string& S, int length, int index, long long sum, int prev) {
//     // 满足条件，记录结果
//     if (index == length) {
//         return xxx==xxx;
//     }

//     long long curr = 0;
//     for (int i = index; i < length; i++) {
//         // 排除错误选项
//         if () {
//             break;
//         }
        
//         // 填写 计算 回退
//         list.push_back(curr);
//         if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
//             return true;
//         }
//         list.pop_back();
//     }
//     return false;
// }


// @lc code=end


int main() {
    LOG_INFO << Solution().removeKdigits("4563213", 5);
    system("pause");
}




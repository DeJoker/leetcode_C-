/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */
#include "../common/debugger.h"


// 股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）
// [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]

// 是往后看，如果有小的弹出，栈本身应该是递减的

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {

    }
    // w表示它离上一个价格之间（即最近的一个大于它的价格之间）的天数
    stack<pair<int, int>> st;

    int next(int price) {
        int w=1;
        while(!st.empty() && st.top().second <= price) {
            w += st.top().first;
            st.pop();
        }

        st.push({w, price});
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

int main() {
    StockSpanner ss; // [null,1,1,1,2,1,4,6]
    LOG_DEBUG << ss.next(100);
    LOG_DEBUG << ss.next(80);
    LOG_DEBUG << ss.next(60);
    LOG_DEBUG << ss.next(70);
    LOG_DEBUG << ss.next(60);
    LOG_DEBUG << ss.next(75);
    LOG_DEBUG << ss.next(85);


    StockSpanner ss2; // [null,1,2,3,4,5]
    LOG_DEBUG << ss.next(31);
    LOG_DEBUG << ss.next(41);
    LOG_DEBUG << ss.next(48);
    LOG_DEBUG << ss.next(59);
    LOG_DEBUG << ss.next(79);
}
